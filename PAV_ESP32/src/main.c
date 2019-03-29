#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "ff.h"
#include "driver/i2s.h"
#include "driver/adc.h"

void app_main()
{
    for (;;)
    {
        printf("Hello World\n ");
        vTaskDelay(1000/portTICK_PERIOD_MS);
        //esp_restart();
    }
}