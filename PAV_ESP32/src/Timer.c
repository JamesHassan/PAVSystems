/*
   @brief to control the inbuilt timers to influence functions periodically
   @author James Hassan 11991559
   @date 2019-04-05
*/

#include "timer.h"

// timer defines
#define MAX_NUM_TIMERS 4
#define TIMER_DIVDER 8000   // to convert to 100uS from an 80MHz clk
#define TIMER_SCALE (TIMER_BASE_CLK/TIMER_DIVDER) // 


// timers timer00 = 
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



//Init
bool Timer_Init(timers timerGN,void (*usrFn)(void*), void* usrArg)
{
    // taskENTER_CRITICAL(); //??

    // @TODO: add a for loop and an aray of timers 
    // using the built in timer.h library from the drivers, initialise
    int err;
    err = timer_init(timerGN.timer_group, timerGN.timer_num, &timerGN.timer_config);
    printf("timer_init == %d\n",err);
    err = timer_set_counter_value(timerGN.timer_group, timerGN.timer_num, (uint64_t)(timerGN.period*TIMER_SCALE));
    printf("timer_set_counter_value == %d\n",err);

    err = timer_set_alarm_value(timerGN.timer_group, timerGN.timer_num, 0);
    printf("timer_set_alarm_value == %d\n",err);
    
    printf("timer_total_init == %d\n",err);



    usrArgTimer00 = usrArg;
    usrFnTimer00 = usrFn;

    // taskEXiT_CRITICAL(); //??
    // timer_start(timerGN.timer_group, timerGN.timer_num);

    return true;

}

void IRAM_ATTR timer00_isr(void *arg)
{
    printf("Wifi Connect\n");

    
    // if (usrFnTimer00)
    // (*usrFnTimer00)(usrArgTimer00);
    //timer_set_alarm();
    // Set to reset the interupt flag
    TIMERG0.int_clr_timers.t0 = 1;

}
// //Set
// void Timer_Set(const uint8_t hours, const uint8_t minutes, const uint8_t seconds)
// {

// }

// //Enable
// void Timer_Enable(const bool enable)
// {


// }

//ISR