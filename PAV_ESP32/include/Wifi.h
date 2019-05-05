/*
   @brief to manage and connect wireless to the base station at periodic intervals. 
   @author James Hassan 11991559
   @date 2019-03-29
*/
#ifndef WIFI_H
#define WIFI_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"

/*Router*/
#define WIFI_SSID "PAV Systems"
#define WIFI_PASSWORD "pavsystem5"
/*******/

/*Home*/
// #define WIFI_SSID "Hampstead Homies_2.4GHz"
// #define WIFI_PASSWORD "IMGLADYOUEXIST"
/******/

EventGroupHandle_t wifi_event_group;

/* @brief For doing different activities reagrding the state the WIFI reciever is in.
@param void *ctx is only used for the initialization.
@param system_event_t *event is used to check what state/event has occured regarding the sucess or failure in setting up the device as STA.*/
esp_err_t WIFI_event_handler(void *ctx, system_event_t *event);

/* @brief Sets up the required functions and modes for any Wifi function.*/
void WIFI_Init();

/* @brief Connects the device to pre-defined router pertaining to #define WIFI_SSID #define WIFI_PASSWORD.*/
void WIFI_Connect();

/* @brief Prints the IP address and stops wifi.
@param void* pvParam is a pointer to any arguments passed in.*/
void WIFI_IP(void *pvParam);

#endif