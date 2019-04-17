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
#include "esp_adc_cal.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spi_flash.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_partition.h"

static const int i2s_num = 0; // i2s port number

static const i2s_config_t i2s_config = {
     .mode = I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_ADC_BUILT_IN,
     .sample_rate = 44100,
     .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
     .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
     .communication_format = I2S_COMM_FORMAT_I2S_MSB, //I2S_COMM_FORMAT_I2S | 
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
    .data_in_num = 36,
    .bck_io_num = 26

};

#define I2S_ADC_UNIT ADC_UNIT_1
#define I2S_ADC_CHANNEL ADC1_CHANNEL_0


//Init
void AP_Init()
{
    int err;
    err = i2s_driver_install(i2s_num, &i2s_config, 0, NULL);   //install and start i2s driver
    printf("Install == %d\n",err);
 
    err = i2s_set_pin(i2s_num, &pin_config); // Set the actual I2S GPIO pins
    printf("Set Pin == %d\n",err);

    err = i2s_set_sample_rates(i2s_num, i2s_config.sample_rate); //set sample rates
    printf("Set Sample Rate == %d\n",err);

    err = i2s_set_adc_mode(I2S_ADC_UNIT, I2S_ADC_CHANNEL);
    printf("ADC Mode == %d\n",err);

    // err = i2s_adc_enable(i2s_num);
    // printf("ADC Enable == %d\n",err);
    //i2s_driver_uninstall(i2s_num); //stop & destroy i2s driver
}

//Set

//Get
void adc_read_task(void* arg)
{
    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_11db);
    esp_adc_cal_characteristics_t characteristics;
    esp_adc_cal_characterize(I2S_ADC_UNIT, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 125, &characteristics);
    while(1) {
        uint32_t voltage;
        esp_adc_cal_get_voltage(I2S_ADC_CHANNEL, &characteristics, &voltage);
        ESP_LOGI("ADC", "%d mV", voltage);
        vTaskDelay(200 / portTICK_RATE_MS);
    }
}

//ISR