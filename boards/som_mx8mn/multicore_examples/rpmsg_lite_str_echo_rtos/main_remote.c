/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpmsg_lite.h"
#include "rpmsg_queue.h"
#include "rpmsg_ns.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"

#include "fsl_uart.h"
#include "rsc_table.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define RPMSG_LITE_SHMEM_BASE         (VDEV0_VRING_BASE)
#define RPMSG_LITE_LINK_ID            (RL_PLATFORM_IMX8MN_M7_USER_LINK_ID)
#define RPMSG_LITE_NS_ANNOUNCE_STRING "rpmsg-virtual-tty-channel-1"
#define APP_TASK_STACK_SIZE (256)
#ifndef LOCAL_EPT_ADDR
#define LOCAL_EPT_ADDR (30)
#endif

/* Globals */
static char app_buf[65536]; /* Each RPMSG buffer can carry less than 512 payload */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static TaskHandle_t app_task_handle = NULL;

static void app_task(void *param)
{
    volatile uint32_t remote_addr;
    struct rpmsg_lite_endpoint *volatile my_ept;
    volatile rpmsg_queue_handle my_queue;
    struct rpmsg_lite_instance *volatile my_rpmsg;
    void *rx_buf;
    uint32_t len;
    int32_t result;
    void *tx_buf;
    uint32_t size;

    uint32_t debug = 0;


#define ROUND_ROBIN_TEST 0

#ifndef ROUND_ROBIN_TEST
    uint32_t bytes_rec = 0;
#endif

    /* Print the initial banner */
    PRINTF("\r\nRPMSG String Echo FreeRTOS RTOS API Demo...RTOS - by BTC...\r\n");

#ifdef MCMGR_USED
    uint32_t startupData;

    /* Get the startup data */
    (void)MCMGR_GetStartupData(kMCMGR_Core1, &startupData);

    my_rpmsg = rpmsg_lite_remote_init((void *)startupData, RPMSG_LITE_LINK_ID, RL_NO_FLAGS);

    PRINTF("After rpmsg_lite_remote_init, MCMGR_USED...RTOS \r\n");
    
    /* Signal the other core we are ready */
    (void)MCMGR_SignalReady(kMCMGR_Core1);
#else
    my_rpmsg = rpmsg_lite_remote_init((void *)RPMSG_LITE_SHMEM_BASE,
                                             RPMSG_LITE_LINK_ID,
                                             RL_NO_FLAGS,
                                             &debug);

    PRINTF("After rpmsg_lite_remote_init, NOT MCMGR_USED...RTOS, *my_rpmsg->sh_mem_base = 0x%x, debug = 0x%x\r\n",
                                                     my_rpmsg->sh_mem_base,
                                                     debug);
    
#endif /* MCMGR_USED */

    
    while (0 == rpmsg_lite_is_link_up(my_rpmsg))
        ;

    PRINTF("After rpmsg_lite_is_link_up...RTOS \r\n");
    
    my_queue = rpmsg_queue_create(my_rpmsg);

    PRINTF("After rpmsg_queue_create...RTOS \r\n");

    my_ept   = rpmsg_lite_create_ept(my_rpmsg, LOCAL_EPT_ADDR, rpmsg_queue_rx_cb, my_queue);
    
    PRINTF("After rpmsg_lite_create_ept...RTOS \r\n");

    (void)rpmsg_ns_announce(my_rpmsg, my_ept, RPMSG_LITE_NS_ANNOUNCE_STRING, RL_NS_CREATE);

    PRINTF("\r\nNameservice sent, ready for incoming messages...\r\n");

    for (;;)
    {
        /* Get RPMsg rx buffer with message */
        result =
            rpmsg_queue_recv_nocopy(my_rpmsg, my_queue, (uint32_t *)&remote_addr, (char **)&rx_buf, &len, RL_BLOCK);
        if (result != 0)
        {
            assert(false);
        }

        /* Copy string from RPMsg rx buffer */
        assert(len < sizeof(app_buf));
        memcpy(app_buf, rx_buf, len);
        app_buf[len] = 0; /* End string by '\0' */

        /* BTC Remove printfs so they are not included in throughput test */
     /*   
        if ((len == 2) && (app_buf[0] == 0xd) && (app_buf[1] == 0xa))
            PRINTF("Get New Line From Master Side...RTOS \r\n");
        else
            PRINTF("Get Message From Master Side...RTOS  : \"%s\" [len : %d]\r\n", app_buf, len);
     */   

 

#ifdef ROUND_ROBIN_TEST
        /* Get tx buffer from RPMsg */
        tx_buf = rpmsg_lite_alloc_tx_buffer(my_rpmsg, &size, RL_BLOCK);
        assert(tx_buf);
        /* Copy string to RPMsg tx buffer */
        memcpy(tx_buf, app_buf, len);
        /* Echo back received message with nocopy send */
        result = rpmsg_lite_send_nocopy(my_rpmsg, my_ept, remote_addr, tx_buf, len);
        if (result != 0)
        {
            assert(false);
        }
       /* Release held RPMsg rx buffer */
        result = rpmsg_queue_nocopy_free(my_rpmsg, rx_buf);
        if (result != 0)
        {
            assert(false);
        }
 #else /* streaming test */
        /* Keep track of the total bytes recieved, at 1MB, send 1 byte back to signal A53 */
        bytes_rec += len;
        if(bytes_rec > 1048576)
        {
            /* Echo back received message with nocopy send */
            result = rpmsg_lite_send_nocopy(my_rpmsg, my_ept, remote_addr, "R", 2);
            if (result != 0)
            {
                assert(false);
            }
        }    
#endif   
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Initialize standard SDK demo application pins */
    /* M7 has its local cache and enabled by default,
     * need to set smart subsystems (0x28000000 ~ 0x3FFFFFFF)
     * non-cacheable before accessing this address region */
    BOARD_InitMemory();

    /* Board specific RDC settings */
    BOARD_RdcInit();

    BOARD_InitBootPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    copyResourceTable();

#ifdef MCMGR_USED
    /* Initialize MCMGR before calling its API */
    (void)MCMGR_Init();
#endif /* MCMGR_USED */

    if (xTaskCreate(app_task, "APP_TASK", APP_TASK_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &app_task_handle) != pdPASS)
    {
        PRINTF("\r\nFailed to create application task\r\n");
        for (;;)
            ;
    }

    vTaskStartScheduler();

    PRINTF("Failed to start FreeRTOS on core0.\n");
    for (;;)
        ;
}
