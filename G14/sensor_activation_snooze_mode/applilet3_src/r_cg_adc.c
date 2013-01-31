/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_adc.c
* Version      : Applilet3 for RL78/G14 V1.01.01 [11 Oct 2011]
* Device(s)    : R5F104LE
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file implements device driver for ADC module.
* Creation Date: 08.01.2013
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_adc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_ADC_Create
* Description  : This function initializes the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Create(void)
{
//    ADCEN = 1U;  /* supply AD clock */
//    ADM0 = _00_AD_ADM0_INITIALVALUE;  /* disable AD conversion and clear ADM0 register */
//    ADMK = 1U;  /* disable INTAD interrupt */
//    ADIF = 0U;  /* clear INTAD interrupt flag */
//    /* Set INTAD low priority */
//    ADPR1 = 1U;
//    ADPR0 = 1U;
//    /* Set ANI0 - ANI2 pin as analog input */
//    PM2 |= 0xFFU;
//    ADM0 = _30_AD_CONVERSION_CLOCK_4 | _00_AD_TIME_MODE_NORMAL_1 | _00_AD_OPERMODE_SELECT;
//    ADM1 = _C0_AD_TRIGGER_HARDWARE_WAIT | _20_AD_CONVMODE_ONESELECT | _02_AD_TRIGGER_INTRTC;
//    ADM2 = _00_AD_POSITIVE_VDD | _00_AD_NEGATIVE_VSS | _08_AD_AREA_MODE_2_3 | _04_AD_WAKEUP_ON |
//           _00_AD_RESOLUTION_10BIT;
//    ADUL = _80_AD_ADUL_VALUE;
//    ADLL = _00_AD_ADLL_VALUE;
//    ADS = _02_AD_INPUT_CHANNEL_2;
}

/***********************************************************************************************************************
* Function Name: R_ADC_Start
* Description  : This function starts the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Start(void)
{
    ADIF = 0U;  /* clear INTAD interrupt flag */
    ADMK = 0U;  /* enable INTAD interrupt */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Stop
* Description  : This function stops the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Stop(void)
{
    ADCS = 0U;  /* disable AD conversion */
    ADMK = 1U;  /* disable INTAD interrupt */
    ADIF = 0U;  /* clear INTAD interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Set_OperationOn
* Description  : This function enables comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_OperationOn(void)
{
    ADCE = 1U;  /* enable AD comparator */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Set_OperationOff
* Description  : This function stops comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_OperationOff(void)
{
    ADCE = 0U;  /* disable AD comparator */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Get_Result
* Description  : This function returns the conversion result in the buffer.
* Arguments    : buffer -
*                    the address where to write the conversion result
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Get_Result(uint16_t * const buffer)
{
    *buffer = (uint16_t)(ADCR >> 6U);
}

/* Start user code for adding. Do not edit comment generated here */
/* use this modified version of the driver */
void ADC_Create(void)
{
    ADCEN = 1U;  /* supply AD clock */
    ADM0 = _00_AD_ADM0_INITIALVALUE;  /* disable AD conversion and clear ADM0 register */
    ADMK = 1U;  /* disable INTAD interrupt */
    ADIF = 0U;  /* clear INTAD interrupt flag */
    /* Set INTAD low priority */
    ADPR1 = 1U;
    ADPR0 = 1U;
    /* Set ANI0 - ANI2 pin as analog input pins */
    ADPC = 0x04;
    /* Set ANI0 - ANI2 pin as analog input */
    PM2 |= 0x07U;
    ADM0 = _18_AD_CONVERSION_CLOCK_8 | _00_AD_TIME_MODE_NORMAL_1 | _00_AD_OPERMODE_SELECT | _01_AD_COMPARATOR_ENABLE;
    ADM1 = _C0_AD_TRIGGER_HARDWARE_WAIT | _20_AD_CONVMODE_ONESELECT | _03_AD_TRIGGER_INTIT;
    ADM2 = _00_AD_POSITIVE_VDD | _00_AD_NEGATIVE_VSS | _08_AD_AREA_MODE_2_3 | _04_AD_WAKEUP_ON |
           _00_AD_RESOLUTION_10BIT;
    ADUL = _80_AD_ADUL_VALUE;
    ADLL = _00_AD_ADLL_VALUE;
    ADS = _02_AD_INPUT_CHANNEL_2;

}


/* End user code. Do not edit comment generated here */