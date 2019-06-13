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
#include "esp_spi_flash.h"

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
  .period = 30, // 30s timer
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
  .period = 0.05, //50ms timer
};

/* Sets-up all functions and mode for normal operation*/
static void setup()
{
  int err;
  //setup and initializations of devices, pins and microcontroller functions
  
  // Initialize NVS - required for Wifi operation
  esp_err_t nvserr = nvs_flash_init();
  if (nvserr == ESP_ERR_NVS_NO_FREE_PAGES || nvserr == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    nvserr = nvs_flash_init();
  }
  ESP_ERROR_CHECK(nvserr);

  // RTC_Init(); // Isn't used and doesn't work - messes with printf
  AP_Init();
  
  ESP_ERROR_CHECK(esp_event_loop_init(WIFI_event_handler, NULL));
  WIFI_connect_group = xEventGroupCreate();
  WIFI_Init();

  timer_queue = xQueueCreate(10, sizeof(timers_t));
  err = Timer_Init(timer00);
  printf("timer_init == %d\n",err);
  err = Timer_Init(timer01); 
  printf("timer_init == %d\n",err);
  
  // Set PIN 16 for IO jitter checking
  gpio_config_t pin16;
  pin16.pin_bit_mask = GPIO_SEL_16;
  pin16.mode = GPIO_MODE_INPUT_OUTPUT;
  pin16.pull_up_en = GPIO_PULLUP_ENABLE;
  pin16.pull_down_en = GPIO_PULLDOWN_ENABLE;
  pin16.intr_type = GPIO_INTR_DISABLE;
  ESP_ERROR_CHECK(gpio_config(&pin16));
}

void app_main()
{
  setup();
  
  xTaskCreate(&WIFI_IP,"WIFI_IP",2048,NULL,5,NULL);
  // xTaskCreate(adc_read_task, "ADC read task", 2048, NULL, 5, NULL);    
  xTaskCreate(timer0_evt,"timer0_evt", 2048, NULL, 5, NULL);

}