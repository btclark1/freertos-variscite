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

/* LVDS0_I2C1_SDA (number BE35), DMA_UART2_RX */
#define BOARD_DEBUG_UART_RX_PERIPHERAL                                DMA__UART2   /*!< Device name: DMA__UART2 */
#define BOARD_DEBUG_UART_RX_SIGNAL                                       uart_rx   /*!< DMA__UART2 signal: uart_rx */
#define BOARD_DEBUG_UART_RX_PIN_NAME                              LVDS0_I2C1_SDA   /*!< Pin name */
#define BOARD_DEBUG_UART_RX_PIN_FUNCTION_ID                  SC_P_LVDS0_I2C1_SDA   /*!< Pin function id */
#define BOARD_DEBUG_UART_RX_PIN_MUX                                           1U   /*!< mux settings */
#define BOARD_DEBUG_UART_RX_LABEL                                 "DMA_UART2_RX"   /*!< Label */
#define BOARD_DEBUG_UART_RX_NAME                                  "DMA_UART2_RX"   /*!< Identifier name */

/* LVDS0_I2C1_SCL (number BE37), DMA_UART2_TX */
#define BOARD_DEBUG_UART_TX_PERIPHERAL                                DMA__UART2   /*!< Device name: DMA__UART2 */
#define BOARD_DEBUG_UART_TX_SIGNAL                                       uart_tx   /*!< DMA__UART2 signal: uart_tx */
#define BOARD_DEBUG_UART_TX_PIN_NAME                              LVDS0_I2C1_SCL   /*!< Pin name */
#define BOARD_DEBUG_UART_TX_PIN_FUNCTION_ID                  SC_P_LVDS0_I2C1_SCL   /*!< Pin function id */
#define BOARD_DEBUG_UART_TX_PIN_MUX                                           1U   /*!< mux settings */
#define BOARD_DEBUG_UART_TX_LABEL                                 "DMA_UART2_TX"   /*!< Label */
#define BOARD_DEBUG_UART_TX_NAME                                  "DMA_UART2_TX"   /*!< Identifier name */

/* M41_I2C0_SCL (number AR45), BB_M41_I2C0_1V8_SCL */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SCL_PERIPHERAL                  M41__I2C0   /*!< Device name: M41__I2C0 */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SCL_SIGNAL                        i2c_scl   /*!< M41__I2C0 signal: i2c_scl */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SCL_PIN_NAME                 M41_I2C0_SCL   /*!< Pin name */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SCL_PIN_FUNCTION_ID     SC_P_M41_I2C0_SCL   /*!< Pin function id */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SCL_LABEL           "BB_M41_I2C0_1V8_SCL"   /*!< Label */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SCL_NAME            "BB_M41_I2C0_1V8_SCL"   /*!< Identifier name */

/* M41_I2C0_SDA (number AU49), BB_M41_I2C0_1V8_SDA */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SDA_PERIPHERAL                  M41__I2C0   /*!< Device name: M41__I2C0 */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SDA_SIGNAL                        i2c_sda   /*!< M41__I2C0 signal: i2c_sda */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SDA_PIN_NAME                 M41_I2C0_SDA   /*!< Pin name */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SDA_PIN_FUNCTION_ID     SC_P_M41_I2C0_SDA   /*!< Pin function id */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SDA_LABEL           "BB_M41_I2C0_1V8_SDA"   /*!< Label */
#define BOARD_INITPINS_BB_M41_I2C0_1V8_SDA_NAME            "BB_M41_I2C0_1V8_SDA"   /*!< Identifier name */

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
void BOARD_InitPins(sc_ipc_t ipc);                         /*!< Function assigned for the core: Cortex-M4F[cm4_1] */

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
