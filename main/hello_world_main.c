/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "esp_log.h"
#include "..\..\..\components\esp_driver_sdmmc\include\driver\sdmmc_host.h"
#include "..\..\..\components\sdmmc\include\sdmmc_cmd.h"
#include "SDCardRead.h"

sdmmc_card_t sd_card;
   sdmmc_host_t  sd_card_host = SDMMC_HOST_DEFAULT();
      sdmmc_slot_config_t  slot_config = SDMMC_SLOT_CONFIG_DEFAULT();
 const char* tag = "SDCardReaderModdddule";

esp_err_t init_sd_host(sdmmc_slot_config_t* slot_config)
{
   esp_err_t ret = sdmmc_host_init();
   if(ret != ESP_OK)
   {
      ESP_LOGI(tag, "Failed WITH CODE %d!", ret);
   }
   ret = sdmmc_host_init_slot(SDMMC_HOST_SLOT_0, slot_config);

   if(ret != ESP_OK)
   {
         ESP_LOGI(tag, "Failed with code %d!", ret);
   }
return ret;
}

esp_err_t init_sd_card(sdmmc_host_t* sd_card_host)
{
   return sdmmc_card_init(sd_card_host, &sd_card);
}

void app_main(void)
{ 

  ESP_LOGI(tag, "Failed WITH CODE ");
   sdmmc_host_init();
  ESP_LOGI(tag, "Failed WITH CODE ");

  slot_config.width = 1;
  slot_config.d2 = 32;
   ESP_LOGI(tag, "Failed WITH CODE ");
  sdmmc_host_init_slot(SDMMC_HOST_SLOT_1, &slot_config);
  ESP_LOGI(tag, "Failed WITH CODE ");
  sdmmc_card_init(&sd_card_host, &sd_card);
  ESP_LOGI(tag, "Failed WITH CODE ");
  esp_err_t ret  = sdmmc_get_status(&sd_card);
  if(ret == ESP_OK)
  {
   ESP_LOGI(tag, "CARD INFO MFG Date: %d SN: %d NAME: %s", sd_card.cid.date, sd_card.cid.serial, sd_card.cid.name);
  }
  else
  {
   ESP_LOGI(tag, "FAILED TO GET CARD INFO!");
  }

  ESP_LOGI(tag, "HERER");
   mount_to_sd_card();
    ESP_LOGI(tag, "AFTER");
   return;
}
//e: 379 SN: 1899340017
//NFO MFG Date: 379 SN: 1899340025 NAME: SD32G