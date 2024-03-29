/*
  @brief to manage and connect wireless to the base station at periodic intervals. 
  @author James Hassan 11991559
  @date 2019-04-26
  Influenced by user: sankarcheppali at https://github.com/sankarcheppali/esp_idf_esp32_posts/blob/master/wifi_connect/main/wifi_connect.c
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
  ESP_ERROR_CHECK(esp_wifi_disconnect());
  ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &cfg));
  ESP_ERROR_CHECK(esp_wifi_connect());
}

esp_err_t WIFI_event_handler(void *ctx, system_event_t *event)
{
  switch(event->event_id) 
  {
    case SYSTEM_EVENT_STA_START:
      WIFI_Connect();
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      xEventGroupSetBits(WIFI_connect_group, BIT0);
      break;
    default:
      break;
  }
  return ESP_OK;
}
//Init
void WIFI_Init()
{
  esp_log_level_set("WIFI", ESP_LOG_NONE);
  tcpip_adapter_init();
  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&cfg));
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_start());
  WIFI_Connect();
}
 
void WIFI_IP(void *pvParam)
{
  while(1)
  {
    // Wait on event group/semaphore
    xEventGroupWaitBits(WIFI_connect_group,BIT0,true,true,portMAX_DELAY);
    // Display Ip Address
    tcpip_adapter_ip_info_t ip_info;
    ESP_ERROR_CHECK(tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_STA, &ip_info));
    printf("IP: %s\n", ip4addr_ntoa(&ip_info.ip));
    // Turn off Wifi
    ESP_ERROR_CHECK(esp_wifi_stop());
    // ESP_ERROR_CHECK(esp_wifi_deinit()); // fails on second entry
    printf("WIFI Stopped\n");
  }
}
