/*
   @brief to control and organise all audio processing functions and analysis. 
   This includes I2S calls for communicating with the microphone, FFT for analysis and comparision of readings.
   @author James Hassan 11991559
   @date 2019-03-29
*/
#ifndef AP_H
#define AP_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"  //FreeRTOS library
#include "freertos/task.h"      // "freertos/FreeRTOS.h" MUST apear before this!
#include "esp_system.h"
#include "driver/i2s.h"         //i2s library

//Init
void AP_Init();

void AP_FFT();

//Set

//Get
void adc_read_task(void* arg);


//ISR

#endif