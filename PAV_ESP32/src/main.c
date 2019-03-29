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
// My files
#include "AP.h"
#include "RTC.h"


static void setup()
{
    //setup and initializations of devices, pins and microcontroller functions

}

static void device_Init()
{
    // Initialise the device for it's operation 
}

void app_main()
{
    for (;;)
    {
        setup();
        APInit();

        // printf("Hello World\n ");
        // vTaskDelay(1000/portTICK_PERIOD_MS);
        //esp_restart();
    }
}