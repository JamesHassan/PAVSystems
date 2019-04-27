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
#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spi_flash.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_partition.h"

#include "AlarmSample.h"

static const int i2s_num = 0; // i2s port number

// double OriAlrm[] = {-0.00153, -0.00156, -0.00150, -0.00165, -0.00192, -0.00122, -0.00116, -0.00171, -0.00150, -0.00159, -0.00156, -0.00150, -0.00131, -0.00201, -0.00226, -0.00208, -0.00134, -0.00113, -0.00092, -0.00082, -0.00049, -0.00012, -0.00021, 0.00003, -0.00043, 0.00021, -0.00006, 0.00012, 0.00015, 0.00043, 0.00046, -0.00015, 0.00092, 0.00079, 0.00015, 0.00021, 0.00021, 0.00027, 0.00070, -0.00012, 0.00082, 0.00061, 0.00150, 0.00244, 0.00134, 0.00104, 0.00104, 0.00104, 0.00070, 0.00095, 0.00104, 0.00146, 0.00119, 0.00150, 0.00198, 0.00146, 0.00128, 0.00119, 0.00098, 0.00043, 0.00131, 0.00110, 0.00104, 0.00098, 0.00110, 0.00162, 0.00201, 0.00131, 0.00156, 0.00223, 0.00250, 0.00272, 0.00266, 0.00266, 0.00241, 0.00223, 0.00177, 0.00238, 0.00208, 0.00122, 0.00177, 0.00134, 0.00125, 0.00122, 0.00122, 0.00107, 0.00031, 0.00040, 0.00070, 0.00061, 0.00089, 0.00049, 0.00027, -0.00009, 0.00006, -0.00003, -0.00037, 0.00067, 0.00058, 0.00067, 0.00107, 0.00107, 0.00082, 0.00043, 0.00055, -0.00021, -0.00015, 0.00046, 0.00027, 0.00073, 0.00052, 0.00043, 0.00031, 0.00098, 0.00043, 0.00055, 0.00073, 0.00055, 0.00037, 0.00125, 0.00079, 0.00037, 0.00006, 0.00021, 0.00027, 0.00089, 0.00049, 0.00095, 0.00089, 0.00034, 0.00070, 0.00058, 0.00073, 0.00061, 0.00040, 0.00034, 0.00034, 0.00027, 0.00031, 0.00064, 0.00031, 0.00027, -0.00027, 0.00027, -0.00034, 0.00018, 0.00024, 0.00089, -0.00018, 0.00073, 0.00067, 0.00024, -0.00006, -0.00043, 0.00009, -0.00012, -0.00006, -0.00031, -0.00021, -0.00058, -0.00034, -0.00021, -0.00027, -0.00003, 0.00034, 0.00012, -0.00009, 0.00027, 0.00043, 0.00012, 0.00046, 0.00018, -0.00046, -0.00037, -0.00012, -0.00015, 0.00015, 0.00067, 0.00034, 0.00018, 0.00079, 0.00085, 0.00073, 0.00006, -0.00015, -0.00003, 0.00021, -0.00018, -0.00119, -0.00137, -0.00143, -0.00180, -0.00150, -0.00177, -0.00238, -0.00235, -0.00174, -0.00208, -0.00211, -0.00293, -0.00272, -0.00293, -0.00305, -0.00256, -0.00281, -0.00269, -0.00278, -0.00195, -0.00208, -0.00287, -0.00275, -0.00330, -0.00308, -0.00250, -0.00269, -0.00323, -0.00311, -0.00333, -0.00323, -0.00320, -0.00357, -0.00385};

#define I2S_READ_LENGTH  (16 * 1024)

static const i2s_config_t i2s_config = {
     .mode = I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_ADC_BUILT_IN,
     .sample_rate = 44100,
     .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
     .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
     .communication_format = I2S_COMM_FORMAT_I2S_MSB, //I2S_COMM_FORMAT_I2S | 
     .intr_alloc_flags = 0, // default interrupt priority
     .dma_buf_count = 16,
     .dma_buf_len = 1024,
     .use_apll = true
};

int counter = 0;

uint16_t rXDma[2] = {0};

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
    err = i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);   //install and start i2s driver
    printf("Install == %d\n",err);
 
    err = i2s_set_pin(I2S_NUM_0, &pin_config); // Set the actual I2S GPIO pins
    printf("Set Pin == %d\n",err);

    err = i2s_set_sample_rates(I2S_NUM_0, i2s_config.sample_rate); //set sample rates
    printf("Set Sample Rate == %d\n",err);

    err = i2s_set_adc_mode(I2S_ADC_UNIT, I2S_ADC_CHANNEL);
    printf("ADC Mode == %d\n",err);
    printf ("A Value from sample: %f\n", OriAlrm[2]);

    // err = i2s_adc_enable(I2S_NUM_0);
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
    esp_adc_cal_characterize(I2S_ADC_UNIT, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 3300, &characteristics);
    size_t bytes_read;

    while(1) {
        // //int i = i2s_adc_start();
        // i2s_read(I2S_NUM_0, &rXDma, i2s_config.dma_buf_len, I2S_READ_LENGTH, portMAX_DELAY);

        // i2s_read(I2S_NUM_0, &rXDma, sizeof(rXDma), &bytes_read, 15);
        // // //i = i2s_adc_stop();
        // printf("Read Val: %d\n",rXDma[counter]);
        // counter++;

        // i2s_adc_disable(I2S_NUM_0);
        // vTaskDelay(200 / portTICK_RATE_MS);
        // i2s_adc_enable(I2S_NUM_0);
        uint32_t voltage;
        esp_adc_cal_get_voltage(I2S_ADC_CHANNEL, &characteristics, &voltage);
        ESP_LOGI("ADC", "%d mV", voltage);
        vTaskDelay(200 / portTICK_RATE_MS);
    }
}

//ISR