/*
   @brief to control and organise all audio processing functions and analysis. 
   This includes I2S calls for communicating with the microphone, FFT for analysis and comparision of readings.
   @author James Hassan 11991559
   @date 2019-03-29
*/
#include "AP.h"

#include "driver/i2s.h"
#include "freertos/queue.h"
#include "driver/adc.h"

static const int i2s_num = 0; // i2s port number

static const i2s_config_t i2s_config = {
     .mode = I2S_MODE_MASTER | I2S_MODE_RX,
     .sample_rate = 44100,
     .bits_per_sample = 16,
     .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
     .communication_format = I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB,
     .intr_alloc_flags = 0, // default interrupt priority
     .dma_buf_count = 8,
     .dma_buf_len = 64,
     .use_apll = true
};

static const i2s_pin_config_t pin_config = {
    .ws_io_num = 25,
    // .data_out_num = 26,
    // .data_in_num = I2S_PIN_NO_CHANGE,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = 26,
    .bck_io_num = 27

};

#define ADC1_TEST_CHANNEL (ADC1_CHANNEL_0)
#define I2S_ADC_UNIT              ADC_UNIT_1

ADC2_CHANNEL_9



//Init
void AP_Init()
{
    
    i2s_driver_install(i2s_num, &i2s_config, 0, NULL);   //install and start i2s driver

    i2s_set_pin(i2s_num, &pin_config); // Set the actual I2S GPIO pins

    i2s_set_sample_rates(i2s_num, i2s_config.sample_rate); //set sample rates

    //i2s_driver_uninstall(i2s_num); //stop & destroy i2s driver
}

//Set

//Get

//ISR