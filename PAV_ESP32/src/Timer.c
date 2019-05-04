/*
   @brief to control the inbuilt timers to influence functions periodically
   @author James Hassan 11991559
   @date 2019-04-05
*/

#include "Timer.h"

void IRAM_ATTR timer00_isr(void *arg)
{
    int timer_num = (int)arg;
    timers_t evt;
    evt.timer_num = timer_num;
    evt.timer_group = 0;

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

    // int err;
    // Config
    ESP_ERROR_CHECK(timer_init(timerGN.timer_group, timerGN.timer_num, &timerGN.timer_config));
    // err = timer_init(timerGN.timer_group, timerGN.timer_num, &timerGN.timer_config); // &config); //
    // printf("timer_init == %d\n",err);
    // // uint64_t temp = 
    printf("Timer_Val == %d\n",(int)(timerGN.period*TIMER_SCALE));
    // Timer Pause
    ESP_ERROR_CHECK(timer_pause(timerGN.timer_group, timerGN.timer_num));
    // err = timer_pause(timerGN.timer_group, timerGN.timer_num);
    // printf("timer_pause == %d\n",err);

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
            // printf("Group[%d], timer[%d] alarm event\n", tempTimer.timer_group, tempTimer.timer_num);

            // /* Print the timer values as visible by this task */
            // printf("-------- TASK TIME --------\n");
            // uint64_t task_counter_value;
            // timer_get_counter_value(tempTimer.timer_group, tempTimer.timer_num, &task_counter_value);
            // printf("%d\n",(int)task_counter_value);
            if (tempTimer.timer_num == 0)
            {
                // Connect to wifi, send info and disconnect
                // WIFI_Init();
                // printf("WIfi Inited\n");
                ESP_ERROR_CHECK(esp_wifi_start());

                // ESP_ERROR_CHECK(esp_wifi_deinit());
                // printf("WIfi De-nited\n");

            }
            else if (tempTimer.timer_num == 1)
            {
                // FFT
                AP_FFT();

                // For checking jitter
                int level = gpio_get_level(GPIO_NUM_16);
                // Analyse data
                if (level)
                    gpio_set_level(GPIO_NUM_16, 0);
                else
                {
                    gpio_set_level(GPIO_NUM_16, 1);

                }
            }
        }
    }
}