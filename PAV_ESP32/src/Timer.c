/*
   @brief to control the inbuilt timers to influence functions periodically
   @author James Hassan 11991559
   @date 2019-04-05
*/

#include "Timer.h"

// timer defines
#define MAX_NUM_TIMERS 4
#define TIMER_DIVDER 8000   // to convert to 100uS from an 80MHz clk
#define TIMER_SCALE (TIMER_BASE_CLK/TIMER_DIVDER) // 

xQueueHandle local_timer_queue;

int isr_reg = 1;

// timers_t timer00 = 
// {
//     .timer_group = TIMER_GROUP_0,
//     .timer_num = TIMER_0,
//     .timer_config.alarm_en = TIMER_ALARM_EN,      /*!< Timer alarm enable */
//     .timer_config.counter_en = TIMER_PAUSE,    /*!< Counter enable */
//     .timer_config.intr_type = TIMER_INTR_LEVEL, /*!< Interrupt mode */
//     .timer_config.counter_dir = TIMER_COUNT_DOWN, /*!< Counter direction  */
//     .timer_config.auto_reload = TIMER_AUTORELOAD_EN,   /*!< Timer auto-reload */
//     .timer_config.divider = TIMER_DIVDER,
//     .timer_intr = 0,
//     .period = 10,
// };

//Variables
static void *usrArgTimer00;
static void (*usrFnTimer00)(void*);

void IRAM_ATTR timer00_isr(void *arg)
{
    //printf("Wifi Connect\n");

    int timer_num = (int)arg;
    timers_t evt;
    evt.timer_num = timer_num;

    uint32_t intr_status = TIMERG0.int_st_timers.val;

    if((intr_status & BIT(timer_num)) ){//&& 0 == TIMER_0) {
        TIMERG0.hw_timer[timer_num].update = 1;
        if (timer_num == 0)
            TIMERG0.int_clr_timers.t0 = 1;
        else if (timer_num == 1)
            TIMERG0.int_clr_timers.t1 = 1;
        TIMERG0.hw_timer[timer_num].config.alarm_en = 1;
    }
    intr_status = TIMERG0.int_st_timers.val;
    xQueueSendFromISR(timer_queue, &evt, NULL);

}

//Init
bool Timer_Init(timers_t timerGN,void (*usrFn)(void*), void* usrArg, xQueueHandle timer_queue)
{
    // taskENTER_CRITICAL(); //??

    // @TODO: add a for loop and an aray of timers 
    // using the built in timer.h library from the drivers, initialise
    int err;
    // timer_config_t config;
    // config.alarm_en = TIMER_ALARM_EN,      /*!< Timer alarm enable */
    // config.counter_en = TIMER_PAUSE,    /*!< Counter enable */
    // config.intr_type = TIMER_INTR_LEVEL, /*!< Interrupt mode */
    // // .timer_config.counter_dir = TIMER_COUNT_DOWN, /*!< Counter direction  */
    // config.counter_dir = TIMER_COUNT_UP, /*!< Counter direction  */
    // config.auto_reload = TIMER_AUTORELOAD_EN,   /*!< Timer auto-reload */
    // config.divider = TIMER_DIVDER,

    // Config
    ESP_ERROR_CHECK(timer_init(timerGN.timer_group, timerGN.timer_num, &timerGN.timer_config));
    // err = timer_init(timerGN.timer_group, timerGN.timer_num, &timerGN.timer_config); // &config); //
    // printf("timer_init == %d\n",err);
    // // uint64_t temp = 
    printf("Timer_Val == %d\n",(int)(timerGN.period*TIMER_SCALE));
    // Timer Pause
    ESP_ERROR_CHECK(timer_pause(timerGN.timer_group, timerGN.timer_num));
    err = timer_pause(timerGN.timer_group, timerGN.timer_num);
    printf("timer_pause == %d\n",err);

    /****Counter DOWN*****/

    // err = timer_set_counter_value(timerGN.timer_group, timerGN.timer_num, (uint64_t)(timerGN.period*TIMER_SCALE));
    // printf("timer_set_counter_value == %d\n",err);

    // err = timer_set_alarm_value(timerGN.timer_group, timerGN.timer_num, 0);
    // printf("timer_set_alarm_value == %d\n",err);
    /*********************/
    /*****Counter UP******/
    // Set counter value
    ESP_ERROR_CHECK(timer_set_counter_value(timerGN.timer_group, timerGN.timer_num, 0));
    // err = timer_set_counter_value(timerGN.timer_group, timerGN.timer_num, 0);
    // printf("timer_set_counter_value == %d\n",err);
    // Set Alarm Value
    ESP_ERROR_CHECK(timer_set_alarm_value(timerGN.timer_group, timerGN.timer_num, (uint64_t)(timerGN.period*TIMER_SCALE)));
    // err = timer_set_alarm_value(timerGN.timer_group, timerGN.timer_num, (uint64_t)(timerGN.period*TIMER_SCALE));
    // printf("timer_set_alarm_value == %d\n",err);
    /*********************/
    // Enable interupt
    ESP_ERROR_CHECK(timer_enable_intr(timerGN.timer_group,timerGN.timer_num));
    // err = timer_enable_intr(timerGN.timer_group,timerGN.timer_num);
    // printf("timer_enable_intr == %d\n",err);
    // // Set ISR
    // printf("timer_isr_register == %d\n",isr_reg);

    ESP_ERROR_CHECK(timer_isr_register(timerGN.timer_group,timerGN.timer_num,timer00_isr,(void *) timerGN.timer_num,ESP_INTR_FLAG_IRAM, NULL));
    // if (isr_reg)
    //     isr_reg = timer_isr_register(timerGN.timer_group,timerGN.timer_num,timer00_isr,(void *) timerGN.timer_num,ESP_INTR_FLAG_IRAM, NULL);
    // printf("timer_isr_register == %d\n",isr_reg);
    //Timer START!
    ESP_ERROR_CHECK(timer_start(timerGN.timer_group, timerGN.timer_num));
    // err = timer_start(timerGN.timer_group, timerGN.timer_num);
    // printf("timer_start == %d\n",err);

    return true;

}

void timer00_evt(void *arg)
{
    while (1) {
        timers_t tempTimer;
        if (xQueueReceive(timer_queue, &tempTimer, portMAX_DELAY))
        {
            printf("Group[%d], timer[%d] alarm event\n", tempTimer.timer_group, tempTimer.timer_num);

            /* Print the timer values as visible by this task */
            printf("-------- TASK TIME --------\n");
            uint64_t task_counter_value;
            timer_get_counter_value(tempTimer.timer_group, tempTimer.timer_num, &task_counter_value);
        }
    }
}

void timer01_evt(void *arg)
{
    while (1) {
        timers_t tempTimer;
        if (xQueueReceive(timer_queue, &tempTimer, portMAX_DELAY))
        {
            printf("Group[%d], timer[%d] alarm event\n", tempTimer.timer_group, tempTimer.timer_num);

            /* Print the timer values as visible by this task */
            printf("-------- TASK TIME --------\n");
            uint64_t task_counter_value;
            timer_get_counter_value(tempTimer.timer_group, tempTimer.timer_num, &task_counter_value);
        }
    }
}