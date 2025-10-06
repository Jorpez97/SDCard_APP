
#include "..\..\hal\include\hal\i2c_types.h"

//#include "hal\include\hal\i2c_types.h"
#include "..\..\driver\i2c\include\driver\i2c.h"
#include "I2CDriver.h"



//Global Objects

i2c_config_t i2c_config;
const int32_t i2c_port_num = 0;

void config_i2c_driver()
{
   esp_err_t ret = ESP_OK;

   i2c_config.mode = I2C_MODE_MASTER;
   i2c_config.scl_io_num = 25; //Change THIS!!
   i2c_config.sda_pullup_en = GPIO_PULLUP_ENABLE;
   i2c_config.sda_io_num  = 26; // CHANG THIS
   i2c_config.scl_pullup_en = GPIO_PULLUP_ENABLE;
   i2c_config.master.clk_speed = 100000; // CHANGE THIS
   ret = i2c_param_config(I2C_NUM_0, &i2c_config);
    printf("RETURNED WITH CODE %d", ret);
   ret = i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER,0,0,0);
 printf("RETURNED WITH CODE %d", ret);
}