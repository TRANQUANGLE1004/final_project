#ifndef _INTERRUPPT_H_
#define _INTERRUPPT_H_
//
#include"MKL46Z4.h"
#include"Configuration.h"
#include "fsl_tpm.h"
#include"globalVal.h"
#include"Seg_LCD.h"
#include"time.h"
//
uint32_t getBit(uint32_t _reg,uint32_t _localtion);
//
void PORTC_PORTD_IRQHandler(void);
void TPM0_IRQHandler(void);
void enableInterrupt();


#endif