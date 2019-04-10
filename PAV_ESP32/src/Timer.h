
#ifndef Timer_H
#define Timer_H

#include <stdio.h>
#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"
#include <types.h>
#include "esp_system.h"

#include "driver/timer.h"
#include "soc/timer_group_reg.h"

typedef struct  {
    timer_group_t timer_group;
    timer_idx_t timer_num;
    timer_config_t timer_config;
    timer_isr_handle_t timer_intr;
    double period;
} timers;

bool Timer_Init();

void IRAM_ATTR timer00_isr(void *arg);

#endif