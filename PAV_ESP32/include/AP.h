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
#include "freertos/queue.h"

#include "esp_adc_cal.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_partition.h"

#include "driver/i2s.h"         //i2s library
#include "driver/adc.h"
#include "driver/gpio.h"
#include "math.h"
#include "fft.h"

/* @brief Sets up the FTM before first use.*/
void AP_Init();

void AP_FFT();

//Get
void adc_read_task(void* arg);

#endif