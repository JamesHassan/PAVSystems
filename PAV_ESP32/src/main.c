/*
   @brief the main module for the PAV project.
   @author James Hassan 11991559
   @date 2019-03-29
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "ff.h"
#include "driver/i2s.h"
#include "driver/adc.h"
#include "driver/timer.h"
// My files
#include "AP.h"
#include "RTC.h"
#include "Timer.h"
#include "Wifi.h"


// Defines
// Timer
#define MAX_NUM_TIMERS 4
#define TIMER_DIVDER 8000   // to convert to 100uS from an 80MHz clk
#define TIMER_SCALE (TIMER_BASE_CLK/TIMER_DIVDER) // 

timers_t timer00 = 
{
    .timer_group = TIMER_GROUP_0,
    .timer_num = TIMER_0,
    .timer_config.alarm_en = TIMER_ALARM_EN,      /*!< Timer alarm enable */
    .timer_config.counter_en = TIMER_PAUSE,    /*!< Counter enable */
    .timer_config.intr_type = TIMER_INTR_LEVEL, /*!< Interrupt mode */
    // .timer_config.counter_dir = TIMER_COUNT_DOWN, /*!< Counter direction  */
    .timer_config.counter_dir = TIMER_COUNT_UP, /*!< Counter direction  */
    .timer_config.auto_reload = TIMER_AUTORELOAD_EN,   /*!< Timer auto-reload */
    .timer_config.divider = TIMER_DIVDER,
    //.timer_intr = timer00_isr,
    .period = 30,
};

timers_t timer01 = 
{
    .timer_group = TIMER_GROUP_0,
    .timer_num = TIMER_1,
    .timer_config.alarm_en = TIMER_ALARM_EN,      /*!< Timer alarm enable */
    .timer_config.counter_en = TIMER_PAUSE,    /*!< Counter enable */
    .timer_config.intr_type = TIMER_INTR_LEVEL, /*!< Interrupt mode */
    // .timer_config.counter_dir = TIMER_COUNT_DOWN, /*!< Counter direction  */
    .timer_config.counter_dir = TIMER_COUNT_UP, /*!< Counter direction  */
    .timer_config.auto_reload = TIMER_AUTORELOAD_EN,   /*!< Timer auto-reload */
    .timer_config.divider = TIMER_DIVDER,
    //.timer_intr = timer00_isr,
    .period = 0.05,
};

// Callback Functions
void Timer00CallBack(void* arg)
{
    printf("Wifi Connect\n");
}

static void setup()
{
    int err;
    //setup and initializations of devices, pins and microcontroller functions
    
    // Initialize NVS - required for Wifi operation
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );

    RTC_Init();
    AP_Init();
    
    ESP_ERROR_CHECK( esp_event_loop_init(Wifi_event_handler, NULL) );
    wifi_event_group = xEventGroupCreate();
    WIFI_Init();
    /* Timers stuff, currently commented out because its done messing up*/
    timer_queue = xQueueCreate(10, sizeof(timers_t));
    err = Timer_Init(timer00, Timer00CallBack, NULL, timer_queue); //timer00.timer_config.alarm_en;
    printf("timer_init == %d\n",err);
    err = Timer_Init(timer01, Timer00CallBack, NULL, timer_queue); //timer00.timer_config.alarm_en;
    printf("timer_init == %d\n",err);
 
}

static void device_Init()
{
    // Initialise the device for it's operation 
}

void app_main()
{
    setup();
    
    xTaskCreate(&printWiFiIP,"printWiFiIP",2048,NULL,5,NULL);
    // xTaskCreate(adc_read_task, "ADC read task", 2048, NULL, 5, NULL);    
    xTaskCreate(timer00_evt,"timer00_evt", 2048, NULL, 5, NULL);


    // for (;;)
    // {
        
    // }
}