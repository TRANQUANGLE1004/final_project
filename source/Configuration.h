#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_
#include"MKL46Z4.h"
// ************************************Define Periperal*********************************
#define LED_RED_PORT            PORTE
#define LED_RED_PIN             29
#define LED_YELLOW_PORT         PORTD
#define LED_YELLOW_PIN          5
#define SW_1_PORT               PORTC
#define SW_3_PORT               PORTC
#define SW_1_PIN                3
#define SW_3_PIN                12
#define SW_GPIO                 GPIOC
// ************************************Define Interrupt handler******************************
#define FLAG_ISR_PORTC_PORTD    PORTC->ISFR
#endif