/*
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    final_project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL46Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
#include "Configuration.h"
#include "interruptFunc.h"
#include "tpmTimer.h"
#include "Seg_LCD.h"
#include "time.h"
/* TODO: insert other definitions and declarations here. */
volatile unsigned int count = 0;
volatile Times myTimes = {0,30,10,10};
volatile Dates myDates = {1,1,2019};
volatile Times myTimeConf;
volatile Dates myDateConf;
// status val
volatile uint8_t state = 0;
volatile uint8_t flag = 0;
volatile uint8_t subFlag = 0;
/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
	BOARD_InitLEDs();
    BOARD_InitButtons();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
    SegLCD_Init();
	// Init tpm timer
	tpmTimerInit();
    //Enable SW Interrupt
    PORT_SetPinInterruptConfig(SW_1_PORT,SW_1_PIN,kPORT_InterruptFallingEdge);
    PORT_SetPinInterruptConfig(SW_3_PORT,SW_3_PIN,kPORT_InterruptFallingEdge);
	//Enable timer tpm 
	TPM_StartTimer(TPM0, kTPM_SystemClock);
	//enable Global Interrupt 
	enableInterrupt();

    while(1){
    	switch (state) {
        case 0: // show time
            switch (flag)
            {
            case 0:
            printNumberLeft(0);
            getTime(&myTimeConf,myTimes); //  update timeConfig
            getDate(&myDateConf,myDates);
            break;
            case 1:
            SegLCD_DisplayTime(myTimes.hour,myTimes.minute);
            break;
            case 2:
            SegLCD_DisplayTime(myTimes.second,myTimes.ms);
            break;   
            default:
            break;
            }
            break;
        case 1: // show date
            switch (flag)
            {
            case 0:
            printNumberLeft(1);
            break;
            case 1:
            SegLCD_DisplayTime(myDates.day,myDates.month);
            break;
            case 2:
            printNumber(myDates.year);
            break;   
            default:
            break;
            }
            break;
        case 2: //setting time FIXME:
            switch (flag)
            {
            case 0:
            printNumberLeft(2);
            break;
            case 2:
            disableBlinkMode();
            //
            SegLCD_DisplayTime(myTimes.hour,myTimes.minute);
            break; 
            case 1:// get time and print
            // TODO: setting blinking
            enableBlinkMode();
            // print h: xx
            switch (subFlag)
            {
            case 0:  // config hour
                // print h:xx
                //TODO write function print menu config hour
                printNumber(myTimeConf.hour);
                // watting interrupt 
                break;
            case 1: // config minute
                //TODO write function print menu config minute
                printNumber(myTimeConf.minute);
                break;
            case 2: // config second
                //TODO write function print menu config second
                printNumber(myTimeConf.second);
                //FIXME update time : OK
                setTime(&myTimes,myTimeConf.second,myTimeConf.minute,myTimeConf.hour);
                break;  
            default:
                break;
            }
            //myLCD_SetBlinking(myLcd,LDD_SEGLCD_BLINK_OFF);
            break;   
            default:
            break;
            }
            break;

        case 3: //setting Date
            switch (flag)
            {
            case 0:
            printNumberLeft(3);
            break;
            case 2:
            //TODO: turn off blinking
            disableBlinkMode();
            // show date
            SegLCD_DisplayTime(myDates.day,myDates.month);
            break; 
            case 1:// get time and print
            //TODO: turn on blinking
            enableBlinkMode();
            // print h: xx
            switch (subFlag)
            {
            case 0:  // config day
                // print h:xx
            printNumber(myDateConf.day);
                // watting interrupt 
                break;
            case 1: // config month
                printNumber(myDateConf.month);
                break;
            case 2: // config year
                printNumber(myDateConf.year);
                setDate(&myDates,myDateConf.day,myDateConf.month,myDateConf.year);
                break;  
            default:
                break;
            }
            //myLCD_SetBlinking(myLcd,LDD_SEGLCD_BLINK_OFF);
            break;   
            default:
            break;
            }
            break;    
        default:
            break;
        }

    }
}

