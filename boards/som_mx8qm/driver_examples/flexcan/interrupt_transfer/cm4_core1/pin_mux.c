/*
 * Copyright 2017-2019 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v5.0
processor: MIMX8QM6xxxFF
package_id: MIMX8QM6AVUFF
mcu_data: ksdk2_0
processor_version: 5.0.0
board: VAR-SOM-MX8-STK
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "pin_mux.h"
#include "fsl_common.h"
#include "main/imx8qm_pads.h"
#include "svc/pad/pad_api.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'false', coreID: cm4_1}
- pin_list:
  - {pin_num: BE35, peripheral: DMA__UART2, signal: uart_rx, pin_signal: LVDS0_I2C1_SDA, sw_config: sw_config_0}
  - {pin_num: BE37, peripheral: DMA__UART2, signal: uart_tx, pin_signal: LVDS0_I2C1_SCL, sw_config: sw_config_0}
  - {pin_num: C5, peripheral: DMA__FLEXCAN0, signal: flexcan_rx, pin_signal: FLEXCAN0_RX, sw_config: sw_config_0}
  - {pin_num: H6, peripheral: DMA__FLEXCAN0, signal: flexcan_tx, pin_signal: FLEXCAN0_TX, sw_config: sw_config_0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(sc_ipc_t ipc)                          /*!< Function assigned for the core: Cortex-M4F[cm4_1] */
{
  sc_err_t err = SC_ERR_NONE;

  err = sc_pad_set_all(ipc, BOARD_DEBUG_UART_RX_PIN_FUNCTION_ID, BOARD_DEBUG_UART_RX_PIN_MUX, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x40 ,SC_PAD_WAKEUP_OFF);/* IOMUXD register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
  err = sc_pad_set_all(ipc, BOARD_DEBUG_UART_TX_PIN_FUNCTION_ID, BOARD_DEBUG_UART_TX_PIN_MUX, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x40 ,SC_PAD_WAKEUP_OFF);/* IOMUXD register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
  err = sc_pad_set_all(ipc, BOARD_BB_CAN0_RX_PIN_FUNCTION_ID, 0U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x40 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_FLEXCAN0_RX register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
  err = sc_pad_set_all(ipc, BOARD_BB_CAN0_TX_PIN_FUNCTION_ID, 0U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x40 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_FLEXCAN0_TX register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_I2C_ConfigurePins:
- options: {callFromInitBoot: 'false', coreID: cm4_1}
- pin_list:
  - {pin_num: AR45, peripheral: M41__I2C0, signal: i2c_scl, pin_signal: M41_I2C0_SCL}
  - {pin_num: AU49, peripheral: M41__I2C0, signal: i2c_sda, pin_signal: M41_I2C0_SDA}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_I2C_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_I2C_ConfigurePins(sc_ipc_t ipc)                 /*!< Function assigned for the core: Cortex-M4F[cm4_1] */
{
  sc_err_t err = SC_ERR_NONE;

  err = sc_pad_set_all(ipc, BOARD_BB_M41_I2C0_1V8_SCL_PIN_FUNCTION_ID, 0U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x20 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_M41_I2C0_SCL register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
  err = sc_pad_set_all(ipc, BOARD_BB_M41_I2C0_1V8_SDA_PIN_FUNCTION_ID, 0U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x20 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_M41_I2C0_SDA register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_GPIO_ConfigurePins:
- options: {callFromInitBoot: 'false', coreID: cm4_1}
- pin_list:
  - {pin_num: AU49, peripheral: M41__GPIO0, signal: 'gpio_io, 03', pin_signal: M41_I2C0_SDA, identifier: ''}
  - {pin_num: AR45, peripheral: M41__GPIO0, signal: 'gpio_io, 02', pin_signal: M41_I2C0_SCL, identifier: ''}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_GPIO_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_GPIO_ConfigurePins(sc_ipc_t ipc)                /*!< Function assigned for the core: Cortex-M4F[cm4_1] */
{
  sc_err_t err = SC_ERR_NONE;

  err = sc_pad_set_all(ipc, SC_P_M41_I2C0_SCL, 2U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x20 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_M41_I2C0_SCL register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
  err = sc_pad_set_all(ipc, SC_P_M41_I2C0_SDA, 2U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x20 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_M41_I2C0_SDA register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
