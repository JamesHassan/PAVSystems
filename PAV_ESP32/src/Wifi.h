/*
   @brief to manage and connect wireless to the base station at periodic intervals. 
   @author James Hassan 11991559
   @date 2019-03-29
*/
#ifndef WIFI_H
#define WIFI_H

// #include <stdio.h>
// #include "stdint.h"
// #include "stdlib.h"
// #include "stdbool.h"
// #include <types.h>
// #include "esp_system.h"
// #include "esp_types.h"
// #include "esp_attr.h"
// #include "esp_event.h"

// #include <string.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "freertos/event_groups.h"
// #include "esp_system.h"
// #include "esp_wifi.h"
// #include "esp_event_loop.h"
// #include "esp_log.h"
// #include "nvs_flash.h"

// #include "lwip/err.h"
// #include "lwip/sys.h"

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"

/*Router*/
#define WIFI_SSID "PAV Systems"
#define WIFI_PASSWORD "pavsystem5"
/*******/

/*Home*/
// #define WIFI_SSID "Hampstead Homies_2.4GHz"
// #define WIFI_PASSWORD "IMGLADYOUEXIST"
/******/

EventGroupHandle_t wifi_event_group;
// const int CONNECTED_BIT = BIT0;

// static const char *TAG = "Sensor 1";

esp_err_t Wifi_event_handler(void *ctx, system_event_t *event);
//Init
void WIFI_Init();

void WIFI_Connect();

void printWiFiIP(void *pvParam);

//Set

//Get

//ISR
#endif