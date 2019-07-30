#include "interruptFunc.h"

uint32_t getBit(uint32_t _reg,uint32_t _localtion){
    return (_reg>>_localtion)&1u;
}

void intButton1SwitchState();


void PORTC_PORTD_IRQHandler(void){
	if(getBit(FLAG_ISR_PORTC_PORTD,SW_3_PIN)==1){ //sw3 event
		//toggle led red
		PTE->PTOR |= 1u<<29;
		//func
		intButton3SwitchState();
		//clear flag
		GPIO_PortClearInterruptFlags(SW_GPIO, 1U << SW_3_PIN);
	}
	else if (getBit(FLAG_ISR_PORTC_PORTD,SW_1_PIN)==1){ //sw1 event
		PTD->PTOR |= 1u<<5u; //toggle led yellow
		//
		intButton1SwitchState();
		//clear flag
		GPIO_PortClearInterruptFlags(SW_GPIO, 1U << SW_1_PIN);
	}
	else {

	}
}

void TPM0_IRQHandler(void){
    //toggle red led
    PTE->PTOR = 1u<<29;
	upgradeTime(&myTimes,&myDates);
	SegLCD_DisplayTime(myTimes.minute,myTimes.second);
    //clear Flag
    TPM_ClearStatusFlags(TPM0, kTPM_TimeOverflowFlag);
	//************************************************************************
	
}

void enableInterrupt(){
	EnableIRQ(PORTC_PORTD_IRQn);
	EnableIRQ(TPM0_IRQn);
}

void intButton1SwitchState(){
	switch (state)
  {
  case 0:
      switch (flag)
      {
      case 0:
        flag = 1;
        break;
      case 1:
        flag = 2;
        break;  
      case 2:
        flag = 1;
        break;
      default:
        break;
      }
    break;
  case 1:
    switch (flag)
    {
    case 0:
      flag = 1;
      break;
    case 1:
      flag = 2;
      break;  
    case 2:
      flag = 1;
      break;
    default:
      break;
    }
    break;  
  case 2:
      switch (flag)
      {
      case 0:
        flag = 2;
        break;
      case 1: //show time
        switch (subFlag)
        {
        case 0:  // config hour
          ++myTimeConf.hour;
          if(myTimeConf.hour==24) myTimeConf.hour = 0;
          break;
        case 1: // config minute
          ++myTimeConf.minute;
          if(myTimeConf.minute==60) myTimeConf.minute = 0;
          break;
        case 2: // config second
          ++myTimeConf.second;
          if(myTimeConf.second==60) myTimeConf.second =0;
          break;  
        default:
          break;
        }
        break;
      case 2:
        flag = 1;
        break;
        break;  
      default:
        break;  
      }
    break;

  case 3:
    //
    switch (flag)
      {
      case 0:
        flag = 2;
        break;
      case 1: //show time
        switch (subFlag)
        {
        case 0:  // config hour
          ++myDateConf.day;
          if(myDateConf.day==32) myDateConf.day = 0;
          break;
        case 1: // config minute
          ++myDateConf.month;
          if(myDateConf.month==13) myDateConf.month = 0;
          break;
        case 2: // config second
          ++myDateConf.year;
          if(myDateConf.year==2030) myDateConf.year = 2019;
        default:
          break;
        }
        break;
      case 2:
        flag = 1;
        break;
        break;  
      default:
        break;  
      }
    //
    break;  
  default:
    break;
  }
}

void intButton3SwitchState(){
	switch (state)
  {
  case 0:
    switch (flag)
    {
    case 0:
      state = 1;
      flag = 0;
      break;
    case 1:
      flag = 0;
      break;  
    case 2:
      flag = 0;
      break;
      default:
      break;
    }
    break;
  case 1:
    switch (flag)
    {
    case 0:
      state = 2;
      flag = 0;
      break;
    case 1:
      flag = 0;
      break;  
    case 2:
      flag = 0;
      break;  
    default:
      break;
    }
    break;  
  case 2:
    switch (flag)
    {
    case 0:
      state = 3;
      flag = 0;
      break;
    case 1: //show time
      switch (subFlag)
      {
      case 0:  // config hour
        subFlag = 1;
        break;
      case 1: // config minute
        subFlag = 2;
        break;
      case 2: // config second
        flag = 2;
        subFlag = 0;
        break;  
      default:
        break; 
      } 
      break;
    case 2:
      flag = 0;
      break;  
    default:
      break;

  	}
    break;
  case 3:
      switch (flag)
    {
    case 0:
      state = 0;
      flag = 0;
      break;
    case 1: //show time
      switch (subFlag)
      {
      case 0:  // config hour
        subFlag = 1;
        break;
      case 1: // config minute
        subFlag = 2;
        break;
      case 2: // config second
        flag = 2;
        subFlag = 0;
        break;  
      default:
        break; 
      } 
      break;
    case 2:
      flag = 0;
      break;  
    default:
    break;
    }
  default:
    break;
}
}