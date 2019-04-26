/*
   @brief to manage and connect wireless to the base station at periodic intervals. 
   @author James Hassan 11991559
   @date 2019-04-26
*/

#include "Wifi.h"

void WIFI_Connect()
{
   wifi_config_t cfg = {
      .sta = {
         .ssid = WIFI_SSID,
         .password = WIFI_PASSWORD
      },
   };
   ESP_ERROR_CHECK( esp_wifi_disconnect() );
   ESP_ERROR_CHECK( esp_wifi_set_config(ESP_IF_WIFI_STA, &cfg) );
   ESP_ERROR_CHECK( esp_wifi_connect() );
}

esp_err_t Wifi_event_handler(void *ctx, system_event_t *event)
{
   switch(event->event_id) {
      case SYSTEM_EVENT_STA_START:
      WIFI_Connect();
      break;
   case SYSTEM_EVENT_STA_GOT_IP:
      xEventGroupSetBits(wifi_event_group, BIT0);
      break;
   case SYSTEM_EVENT_STA_DISCONNECTED:
      esp_wifi_connect();
      xEventGroupClearBits(wifi_event_group, BIT0);
      break;
   default:
      break;
   }
   return ESP_OK;
}
//Init
void WIFI_Init()
{

   esp_log_level_set("wifi", ESP_LOG_NONE); // disable wifi driver logging
   tcpip_adapter_init();
   wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
   ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
   ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
   ESP_ERROR_CHECK( esp_wifi_start() );
   WIFI_Connect();

}
 
void printWiFiIP(void *pvParam){
    printf("printWiFiIP task started \n");
    while(1){
        xEventGroupWaitBits(wifi_event_group,BIT0,true,true,portMAX_DELAY);
        tcpip_adapter_ip_info_t ip_info;
	    ESP_ERROR_CHECK(tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_STA, &ip_info));
	    printf("IP :  %s\n", ip4addr_ntoa(&ip_info.ip));
    }
}
//Set

//Get

//ISR