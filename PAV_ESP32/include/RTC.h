/*
  @brief to utalise the inbuilt Real Time Clock (RTC) for control and operation, recording the time of events
  @author James Hassan 11991559
  @date 2019-03-29
*/

#ifndef RTC_H
#define RTC_H

#include <stdio.h>
#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"
#include <types.h>
#include "esp_system.h"
#include "driver/rtc_cntl.h"
#include "driver/rtc_io.h"


//Init
bool RTC_Init();
//Set
void RTC_Set(const uint8_t hours, const uint8_t minutes, const uint8_t seconds);

//Get
void RTC_Get(uint8_t* const hours, uint8_t* const minutes, uint8_t* const seconds);

//ISR
#endif