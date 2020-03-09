/*
 * Copyright 2017-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

#include "board.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

#ifdef SPEAR_MX8

/* M40_I2C0_SCL (number AM44), M40_UART0_RX */
#define BOARD_DEBUG_UART_RX_PERIPHERAL                                M40__UART0   /*!< Device name: M40__UART0 */
#define BOARD_DEBUG_UART_RX_SIGNAL                                       uart_rx   /*!< M40__UART0 signal: uart_rx */
#define BOARD_DEBUG_UART_RX_PIN_NAME                                M40_I2C0_SCL   /*!< Pin name */
#define BOARD_DEBUG_UART_RX_PIN_FUNCTION_ID                    SC_P_M40_I2C0_SCL   /*!< Pin function id */
#define BOARD_DEBUG_UART_RX_PIN_MUX                                           1U   /*!< mux settings */
#define BOARD_DEBUG_UART_RX_LABEL                                 "M40_UART0_RX"   /*!< Label */
#define BOARD_DEBUG_UART_RX_NAME                                  "M40_UART0_RX"   /*!< Identifier name */

/* M40_I2C0_SDA (number AU51), M40_UART0_TX */
#define BOARD_DEBUG_UART_TX_PERIPHERAL                                M40__UART0   /*!< Device name: M40__UART0 */
#define BOARD_DEBUG_UART_TX_SIGNAL                                       uart_tx   /*!< M40__UART0 signal: uart_tx */
#define BOARD_DEBUG_UART_TX_PIN_NAME                                M40_I2C0_SDA   /*!< Pin name */
#define BOARD_DEBUG_UART_TX_PIN_FUNCTION_ID                    SC_P_M40_I2C0_SDA   /*!< Pin function id */
#define BOARD_DEBUG_UART_TX_PIN_MUX                                           1U   /*!< mux settings */
#define BOARD_DEBUG_UART_TX_LABEL                                 "M40_UART0_TX"   /*!< Label */
#define BOARD_DEBUG_UART_TX_NAME                                  "M40_UART0_TX"   /*!< Identifier name */

#else /* defines for VAR-SOM-MX8 */

/* M40_GPIO0_00 (number AR47), DMA_UART4_RX */
#define BOARD_DEBUG_UART_RX_PERIPHERAL                                DMA__UART4   /*!< Device name: DMA__UART4 */
#define BOARD_DEBUG_UART_RX_SIGNAL                                       uart_rx   /*!< DMA__UART4 signal: uart_rx */
#define BOARD_DEBUG_UART_RX_PIN_NAME                                M40_GPIO0_00   /*!< Pin name */
#define BOARD_DEBUG_UART_RX_PIN_FUNCTION_ID                    SC_P_M40_GPIO0_00   /*!< Pin function id */
#define BOARD_DEBUG_UART_RX_PIN_MUX                                           2U   /*!< mux settings */
#define BOARD_DEBUG_UART_RX_LABEL                                 "DMA_UART4_RX"   /*!< Label */
#define BOARD_DEBUG_UART_RX_NAME                                  "DMA_UART4_RX"   /*!< Identifier name */

/* M40_GPIO0_01 (number AU53), DMA_UART4_TX */
#define BOARD_DEBUG_UART_TX_PERIPHERAL                                DMA__UART4   /*!< Device name: DMA__UART4 */
#define BOARD_DEBUG_UART_TX_SIGNAL                                       uart_tx   /*!< DMA__UART4 signal: uart_tx */
#define BOARD_DEBUG_UART_TX_PIN_NAME                                M40_GPIO0_01   /*!< Pin name */
#define BOARD_DEBUG_UART_TX_PIN_FUNCTION_ID                    SC_P_M40_GPIO0_01   /*!< Pin function id */
#define BOARD_DEBUG_UART_TX_PIN_MUX                                           2U   /*!< mux settings */
#define BOARD_DEBUG_UART_TX_LABEL                                 "DMA_UART4_TX"   /*!< Label */
#define BOARD_DEBUG_UART_TX_NAME                                  "DMA_UART4_TX"   /*!< Identifier name */

#endif /* SPEAR_MX8 */

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif


/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 * @param ipc scfw ipchandle.
 *
 */
void BOARD_InitPins(sc_ipc_t ipc);                         /*!< Function assigned for the core: Cortex-M4F[cm4_0] */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
