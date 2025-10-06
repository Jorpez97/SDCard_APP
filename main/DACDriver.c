//Doing the Cosine Wave as an example

#include "driver/dac_cosine.h"

dac_cosine_config_t cos_cfg;
dac_cosine_handle_t ret_handle;

void cosineDac(){
    
  esp_err_t ret =  dac_cosine_new_channel(&cos_cfg, &ret_handle);
 printf("RETURNED WITH CODE %d", ret);
  ret =  dac_cosine_start(ret_handle);
  printf("RETURNED WITH CODE %d", ret);

}