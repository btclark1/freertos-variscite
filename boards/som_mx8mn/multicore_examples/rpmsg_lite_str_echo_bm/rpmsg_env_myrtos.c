/*
Bare-Metal
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rpmsg_env.h"
#include "rpmsg_lite.h"
#include "rpmsg_ns.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_uart.h"

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

#define STRING_BUFFER_CNT 3

typedef struct
{
    unsigned long src;
    void* data;
    int len;
} app_message_t;

static app_message_t app_msg[STRING_BUFFER_CNT];
static char app_buf[512]; /* Each RPMSG buffer can carry less than 512 payload */
static uint8_t app_idx = 0;
static uint8_t handler_idx = 0;
static volatile int32_t msg_count = 0;

struct rpmsg_lite_instance *volatile my_rpmsg;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

static void rpmsg_enable_rx_int(bool enable)
{
    if (enable)
    {
        if ((--msg_count) == 0)
            env_enable_interrupt(my_rpmsg->rvq->vq_queue_index); 
    }
    else
    {
        if ((msg_count++) == 0)
            env_disable_interrupt(my_rpmsg->rvq->vq_queue_index); 

    }
}

int32_t rx_cb_function(void *payload, uint32_t payload_len, uint32_t src, void *priv)
{
    /*
     * Temperorily Disable  Receive Interrupt to avoid master
     * sending too many messages and remote will fail to keep pace
     * to consume (flow control)
     */
    rpmsg_enable_rx_int(false);

    PRINTF("\r\nIn rx_cb_function....\r\n");


    /* Hold the RPMsg rx buffer to be used in main loop */
// ??    rpmsg_hold_rx_buffer(rp_chnl, data);
    app_msg[handler_idx].src = src;
    app_msg[handler_idx].data = payload;
    app_msg[handler_idx].len = payload_len;

    /* Move to next free message index */
    handler_idx = (handler_idx + 1) % STRING_BUFFER_CNT;

    return(0);
}
/*!
 * @brief Main function
 */
int main(void)
{
    rl_ept_rx_cb_t rx_cb_function = 0;

    volatile uint32_t remote_addr;
    struct rpmsg_lite_endpoint *volatile my_ept;

    uint32_t len;
    int32_t result;
    void *tx_buf;
    uint32_t size;

    uint32_t debug = 0;


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

   /* Print the initial banner */
    PRINTF("\r\nRPMSG String Echo .... API Demo...BM - NOT MCMGR_USED- by BTC...\r\n");
    my_rpmsg = rpmsg_lite_remote_init((void *)RPMSG_LITE_SHMEM_BASE,
                                         RPMSG_LITE_LINK_ID,
                                         RL_NO_FLAGS,
                                         &debug);

 
    PRINTF("After env_init, ...BM ,  *my_rpmsg->sh_mem_base = 0x%x, debug = 0x%x\r\n",
                                                     my_rpmsg->sh_mem_base, debug);   
    debug = 0;
    while (0 == rpmsg_lite_is_link_up(my_rpmsg))
    {
        debug++;
    }
    PRINTF("After rpmsg_lite_is_link_up  ...BM loops = %d\r\n", debug);

    my_ept   = rpmsg_lite_create_ept(my_rpmsg, 
                                        LOCAL_EPT_ADDR,
                                        rx_cb_function,                                        
                                        app_msg);
                                        
    PRINTF("After rpmsg_lite_create_ept...BM .. my_ept = \r\n");

    (void)rpmsg_ns_announce(my_rpmsg, my_ept, RPMSG_LITE_NS_ANNOUNCE_STRING, RL_NS_CREATE);

    PRINTF("\r\nNameservice sent, ready for incoming messages...\r\n");

    for (;;)
    {
        /* Wait for message to be available */
        while (msg_count == 0)
        {}
     
        len = app_msg[app_idx].len;
        assert(len < sizeof(app_buf));
        
        /* Copy string from RPMsg rx buffer */
        memcpy(app_buf, app_msg[app_idx].data, len);
        app_buf[len] = 0; /* End string by '\0' */
 
        /* BTC Remove printfs so they are not included in throughput test */        
        if ((len == 2) && (app_buf[0] == 0xd) && (app_buf[1] == 0xa))
            PRINTF("Get New Line From Master Side...BM \r\n");
        else
            PRINTF("Get Message From Master Side...BM  : \"%s\" [len : %d]\r\n", app_buf, len);
        

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
 
        result =  rpmsg_lite_release_rx_buffer(my_rpmsg, app_msg[app_idx].data);
        app_idx = (app_idx + 1) % STRING_BUFFER_CNT;
        if (result != 0)
        {
            assert(false);
        }

        /* Once a message is consumed, minus the msg_count and might enable interrupt again */
        rpmsg_enable_rx_int(true);
    }
}
