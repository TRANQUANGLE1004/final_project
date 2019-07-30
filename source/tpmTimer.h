#ifndef _TPM_TIMER_H_
#define _TPM_TIMER_H_
// include
#include "MKL46Z4.h"
#include "fsl_tpm.h"
#include "fsl_clock.h"
// define here:
#define TPM_PRESCALER       kTPM_Prescale_Divide_128
#define TPM_SOURCE_CLOCK    (8000000/128)

//

void tpmTimerInit(void);

#endif
