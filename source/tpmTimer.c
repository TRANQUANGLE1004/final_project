#include"tpmTimer.h"

void tpmTimerInit(void){
    //TODO:
    // choose clock for tpm module
	tpm_config_t tpmInfo;
    CLOCK_SetTpmClock(2U); // choose mcgFLLCLK or mcgPLLCLK/2
    // 
    TPM_GetDefaultConfig(&tpmInfo);
    //
    tpmInfo.prescale = TPM_PRESCALER;
    TPM_Init(TPM0, &tpmInfo);
    // setting period
    TPM_SetTimerPeriod(TPM0, MSEC_TO_COUNT(500U, TPM_SOURCE_CLOCK));
    TPM_EnableInterrupts(TPM0, kTPM_TimeOverflowInterruptEnable);
}
