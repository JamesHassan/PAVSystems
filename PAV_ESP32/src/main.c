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

// Defines
// Timer
#define MAX_NUM_TIMERS 4
#define TIMER_DIVDER 8000   // to convert to 100uS from an 80MHz clk
#define TIMER_SCALE (TIMER_BASE_CLK/TIMER_DIVDER) // 

timers timer00 = 
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
    .timer_intr = 0,
    .period = 10,
};

xQueueHandle timer_queue;

// Callback Functions
void Timer00CallBack(void* arg)
{
    printf("Wifi Connect\n");
}

static void setup()
{
    int err;
    //setup and initializations of devices, pins and microcontroller functions
    RTC_Init();
    err = Timer_Init(timer00); //timer00.timer_config.alarm_en;
    printf("timer_init == %d\n",err);

    // err = timer_enable_intr(timer00.timer_group,timer00.timer_num);
    // printf("timer_enable_intr == %d\n",err);

    // err = timer_isr_register(timer00.timer_group,timer00.timer_num,timer00_isr,0,ESP_INTR_FLAG_IRAM, NULL);
    // // timer_isr_register(                                              void (*fn)(void*), void * arg, int intr_alloc_flags, timer_isr_handle_t *handle);
    // printf("timer_isr_register == %d\n",err);

    // err = timer_start(timer00.timer_group, timer00.timer_num);
    // printf("timer_start == %d\n",err);

    // timer_queue = xQueueCreate(10, sizeof(timers));
    // xTaskCreate(timer00_isr,"timer00_isr", 2048, NULL, 5, NULL);
 
}

static void device_Init()
{
    // Initialise the device for it's operation 
}

void app_main()
{
    
    setup();
    // Start a task to show what pads have been touched
    //xTaskCreate(&tp_example_read_task, "touch_pad_read_task", 2048, NULL, 5, NULL);

    for (;;)
    {
        APInit();

        // printf("Hello World\n ");
        // vTaskDelay(1000/portTICK_PERIOD_MS);
        //esp_restart();
    }
}