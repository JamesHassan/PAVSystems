
#ifndef Timer_H
#define Timer_H

#include <stdio.h>
#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"
#include <types.h>

#include "esp_system.h"
#include "esp_types.h"
#include "esp_attr.h"

#include "driver/timer.h"
#include "soc/timer_group_reg.h"


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "soc/timer_group_struct.h"
#include "driver/periph_ctrl.h"

#include "driver/gpio.h"

#include "AP.h"
#include "Wifi.h"

typedef struct  {
    timer_group_t timer_group;
    timer_idx_t timer_num;
    timer_config_t timer_config;
    timer_isr_handle_t timer_intr;
    double period;
} timers_t;

// timer defines
#define MAX_NUM_TIMERS 4
#define TIMER_DIVDER 8000   // to convert to 100uS from an 80MHz clk
#define TIMER_SCALE (TIMER_BASE_CLK/TIMER_DIVDER) // 

xQueueHandle timer_queue;

void IRAM_ATTR timer00_isr(void *arg);

bool Timer_Init(timers_t timerGN,void (*usrFn)(void*), void* usrArg, xQueueHandle timer_queue);

void timer00_evt(void *arg);

#endif