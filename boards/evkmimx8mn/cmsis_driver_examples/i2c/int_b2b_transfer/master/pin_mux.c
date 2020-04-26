/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v6.0
processor: MIMX8MN6xxxJZ
package_id: MIMX8MN6DVTJZ
mcu_data: ksdk2_0
processor_version: 0.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"

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
- options: {callFromInitBoot: 'false', coreID: m7}
- pin_list:
  - {pin_num: F19, peripheral: UART4, signal: uart_rx, pin_signal: UART4_RXD, PE: Disabled, FSEL: FAST0, DSE: X6_0}
  - {pin_num: F18, peripheral: UART4, signal: uart_tx, pin_signal: UART4_TXD, PE: Disabled, FSEL: FAST0, DSE: X6_0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {                                /*!< Function assigned for the core: Cortex-M7F[m7] */
    IOMUXC_SetPinMux(IOMUXC_UART4_RXD_UART4_RX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_UART4_RXD_UART4_RX, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(6U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U));
    IOMUXC_SetPinMux(IOMUXC_UART4_TXD_UART4_TX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_UART4_TXD_UART4_TX, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(6U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U));
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
I2C3_DeinitPins:
- options: {callFromInitBoot: 'false', coreID: m7}
- pin_list:
  - {pin_num: E10, peripheral: GPIO5, signal: 'gpio_io, 18', pin_signal: I2C3_SCL}
  - {pin_num: F10, peripheral: GPIO5, signal: 'gpio_io, 19', pin_signal: I2C3_SDA}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : I2C3_DeinitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void I2C3_DeinitPins(void) {                               /*!< Function assigned for the core: Cortex-M7F[m7] */
    IOMUXC_SetPinMux(IOMUXC_I2C3_SCL_GPIO5_IO18, 0U);
    IOMUXC_SetPinMux(IOMUXC_I2C3_SDA_GPIO5_IO19, 0U);
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
I2C3_InitPins:
- options: {callFromInitBoot: 'false', coreID: m7}
- pin_list:
  - {pin_num: E10, peripheral: I2C3, signal: i2c_scl, pin_signal: I2C3_SCL, PE: Disabled, SION: ENABLED, HYS: Enabled, FSEL: FAST0, DSE: X6_0}
  - {pin_num: F10, peripheral: I2C3, signal: i2c_sda, pin_signal: I2C3_SDA, PE: Disabled, SION: ENABLED, HYS: Enabled, FSEL: FAST0, DSE: X6_0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : I2C3_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void I2C3_InitPins(void) {                                 /*!< Function assigned for the core: Cortex-M7F[m7] */
    IOMUXC_SetPinMux(IOMUXC_I2C3_SCL_I2C3_SCL, 1U);
    IOMUXC_SetPinConfig(IOMUXC_I2C3_SCL_I2C3_SCL, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(6U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_I2C3_SDA_I2C3_SDA, 1U);
    IOMUXC_SetPinConfig(IOMUXC_I2C3_SDA_I2C3_SDA, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(6U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
