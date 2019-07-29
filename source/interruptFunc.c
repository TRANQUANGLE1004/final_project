#include "interruptFunc.h"

uint32_t getBit(uint32_t _reg,uint32_t _localtion){
    return (_reg>>_localtion)&1u;
}

void PORTC_PORTD_IRQHandler(void){
	if(getBit(FLAG_ISR_PORTC_PORTD,SW_3_PIN)==1){ //sw3 event
		//toggle led red
		PTE->PTOR |= 1u<<29;
		//clear flag
		GPIO_PortClearInterruptFlags(SW_GPIO, 1U << SW_3_PIN);
	}
	else if (getBit(FLAG_ISR_PORTC_PORTD,SW_1_PIN)==1){ //sw1 event
		PTD->PTOR |= 1u<<5u;
		//clear flag
		GPIO_PortClearInterruptFlags(SW_GPIO, 1U << SW_1_PIN);
	}
	else {

	}
}

void TPM0_IRQHandler(void){
    //toggle red led
    PTE->PTOR = 1u<<29;
    //clear Flag
    TPM_ClearStatusFlags(TPM0, kTPM_TimeOverflowFlag);
}
