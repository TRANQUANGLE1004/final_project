#ifndef _TIME_H_
#define _TIME_H_

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef struct Time
{   
    uint8_t ms;
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
}Times;

typedef struct Date
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
}Dates;
// setting method
void setTime(Times* myTime, uint8_t _s, uint8_t _m, uint8_t _h);
void setDate(Dates* myDate, uint8_t _d, uint8_t _m, uint16_t _y);
void upgradeTime(Times* myTime,Dates* myDate);

// getting method FIXME: test xem cach get value 

void getTime(Times* _dest,Times _source);
void getDate(Dates* _dest,Dates _source);

#endif