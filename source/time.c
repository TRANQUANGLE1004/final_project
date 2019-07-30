#include "time.h"

void setTime(Times* myTime, uint8_t _s, uint8_t _m, uint8_t _h){
    myTime->second = _s;
    myTime->minute = _m;
    myTime->hour   = _h;
}

void setDate(Dates* myDate, uint8_t _d, uint8_t _m, uint16_t _y){
    myDate->day = _d;
    myDate->month = _m;
    myDate->year = _y;
}
//FIXME: test me

void upgradeTime(Times* myTime,Dates* myDate){
    ++myTime->ms;
    if(myTime->ms==101){
        myTime->second ++;
        myTime->ms = 0;
    if(myTime->second == 60){
        ++myTime->minute;
        myTime->second = 0;
        if(myTime->minute == 60){
            ++myTime->hour;
            myTime->minute =0;
            if(myTime->hour ==24) {
                ++myDate->day;
                myTime->hour = 0;
                switch (myDate->month)
                {
                case 1:
                    if(myDate->day==32){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;
                case 2:
                    if(myDate->year%4==0&&myDate->year%100!=0){
                        if(myDate->day==29){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    }
                    else {
                        if(myDate->day==30){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    }
                    break;
                case 3:
                    if(myDate->day==32){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;
                case 4:
                    if(myDate->day==31){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break; 
                case 5:
                    if(myDate->day==32){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;    
                case 6:
                    if(myDate->day==31){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;    
                case 7:
                    if(myDate->day==32){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;
                case 8:
                    if(myDate->day==32){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;
                case 9:
                    if(myDate->day==31){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;  
                case 10:
                    if(myDate->day==32){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;
                case 11:
                    if(myDate->day==31){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;
                case 12:
                    if(myDate->day==32){
                        ++myDate->month;
                        myDate->day = 1;
                        if(myDate->month == 13){
                            ++myDate->year;
                            myDate->month = 1;
                        }
                    }
                    break;              
                default:
                    break;
                }
            }
        }
    }
    }
    
}

void getTime(Times* _dest,Times _source){
    _dest->second = _source.second;
    _dest->minute = _source.minute;
    _dest->hour = _source.hour;
    _dest->ms = _source.ms;
}
void getDate(Dates* _dest,Dates _source){
    _dest->day = _source.day;
    _dest->month = _source.month;
    _dest->year = _source.year;
}