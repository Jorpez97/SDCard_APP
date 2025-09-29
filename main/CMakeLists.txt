idf_component_register(SRCS "SDCardRead.c" "hello_world_main.c"
                       PRIV_REQUIRES spi_flash
                       PRIV_REQUIRES esp_driver_sdmmc
                       PRIV_REQUIRES fatfs
                       PRIV_REQUIRES vfs
                       INCLUDE_DIRS "")
