/*

    The Code here does (tries to do) the following:
    1) Look at the SD Card File System
    2) Read contents from a file inside an SD Card
    
*/
#include "..\..\..\components\sdmmc\include\sdmmc_cmd.h"
#include "esp_log.h"
#include "..\..\..\components\fatfs\vfs\esp_vfs_fat.h"
#include "..\..\..\components\esp_driver_sdmmc\include\driver\sdmmc_host.h"
#include <stdio.h>                      // for fopen, fclose, fread, etc.
#include <dirent.h>

const char* mmc_path = "/sdcard";
extern sdmmc_card_t* sd_card;
extern  const char* tag;
  extern sdmmc_host_t  sd_card_host;

esp_err_t mount_to_sd_card()
{
  
    extern   sdmmc_slot_config_t  slot_config;
    esp_vfs_fat_mount_config_t mount_config = VFS_FAT_MOUNT_DEFAULT_CONFIG();
    esp_err_t ret = esp_vfs_fat_sdmmc_mount(mmc_path, &sd_card_host, (void*)&slot_config, &mount_config, NULL);

    if(ret != ESP_OK)
    {
        ESP_LOGI(tag, "SDMMC mount failed with code: %d", ret);
    return ret;
    }
    DIR* dir = opendir("/sdcard");
if (!dir) {
    ESP_LOGE(tag, "Failed to open directory");
    return ESP_FAIL;
}

struct dirent* entry;
while ((entry = readdir(dir)) != NULL) {
    ESP_LOGI(tag, "File found: %s", entry->d_name);
}
closedir(dir);

    FILE* fp = fopen("/sdcard/HelloW.txt", "r");
    if(fp == NULL)
    {
        ESP_LOGI(tag, "CANT OPEN FILE");
        return ret;
    }
    char buffer[50];
    // Read one line from the file
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Read line: %s", buffer);
    } else {
        printf("Could not read line (possibly empty file or error).\n");
    }

    // Close the file
    fclose(fp);
    //Now try to read from SD CArd
return ret;
}
