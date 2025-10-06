#include "..\..\hal\include\hal\i2c_types.h"
#include "..\..\driver\i2c\include\driver\i2c.h"

//#include "hal\include\hal\i2c_types.h"
//#include "i2c.h"
#include "I2CDriver.h"
#include "portmacro.h"


const uint8_t TURN_ON_DISPLAY = 0x0C;
const uint8_t TURN_OFF_DISPLAY  = 0x08;
const uint8_t LCD_DISP_ADDR = 0x27;

void LCDWrite()
{
    esp_err_t err = ESP_OK;
    uint8_t dataarr[1];
    dataarr[0] = TURN_OFF_DISPLAY;
    i2c_cmd_handle_t i2c_cmd = i2c_cmd_link_create();
    err = i2c_master_start(i2c_cmd);
     printf("RETURNED WITH CODE %d", err);
     err = i2c_master_write_byte(i2c_cmd,  (LCD_DISP_ADDR << 1) | I2C_MASTER_WRITE, true);
     printf("RETURNED WITH CODE %d", err);
     err =  i2c_master_write(i2c_cmd, &dataarr[0], sizeof(dataarr), true);
     printf("RETURNED WITH CODE %d", err);
    err = i2c_master_cmd_begin(I2C_NUM_0, i2c_cmd, portMAX_DELAY);
    {
        printf("RETURNED WITH CODE %d", err);
    }
    vTaskDelay( 500 / portTICK_PERIOD_MS);
    i2c_master_stop(i2c_cmd);
    i2c_cmd_link_delete(i2c_cmd);
}