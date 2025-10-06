idf_component_register(SRCS "DACDriver.c" "LCDDriver.c" "I2CDriver.c" "SDCardRead.c" "hello_world_main.c"
                       PRIV_REQUIRES spi_flash
                       PRIV_REQUIRES esp_driver_sdmmc
                       PRIV_REQUIRES fatfs
                       PRIV_REQUIRES vfs
                       PRIV_REQUIRES driver
                       PRIV_REQUIRES esp_driver_dac
                       INCLUDE_DIRS "")
