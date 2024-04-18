#include <drivers/8258/gpio_8258.h>
#include "app_config.h"
#include "common/types.h"

static unsigned int value[5] = { 0 };
extern u8 ctrl[2];

void app_light_init() 
{
    gpio_set_func(GPIO_PC2, AS_GPIO);
	gpio_set_func(GPIO_PC3, AS_GPIO);
	gpio_set_func(GPIO_PC4, AS_GPIO);
	gpio_set_func(GPIO_PB4, AS_GPIO);
	gpio_set_func(GPIO_PB5, AS_GPIO);

	gpio_set_output_en(GPIO_PC2, 1);
	gpio_set_output_en(GPIO_PC3, 1);
	gpio_set_output_en(GPIO_PC4, 1);
	gpio_set_output_en(GPIO_PB4, 1);
	gpio_set_output_en(GPIO_PB5, 1);

	gpio_set_input_en(GPIO_PC2, 0); 
	gpio_set_input_en(GPIO_PC3, 0); 
	gpio_set_input_en(GPIO_PC4, 0); 
	gpio_set_input_en(GPIO_PB4, 0); 
	gpio_set_input_en(GPIO_PB5, 0); 

	gpio_set_func(GPIO_PD2, AS_GPIO);
	gpio_setup_up_down_resistor(GPIO_PD2, PM_PIN_PULLUP_10K);
	gpio_set_output_en(GPIO_PD2, 0);
	gpio_set_input_en(GPIO_PD2, 1);
}

void app_light_loop() 
{
    gpio_write(GPIO_PC2, value[0]); 
	gpio_write(GPIO_PC3, value[1]); 
	gpio_write(GPIO_PC4, value[2]); 
	gpio_write(GPIO_PB4, value[3]); 
	gpio_write(GPIO_PB5, value[4]);
}

void app_light_on()
{
    value[LIGHT_COLD] = 1;
    cai_ctrl_read_callback(0);
    bls_att_pushNotifyData(CAT_CTRL_VALUE_H, ctrl, sizeof(ctrl));
}

void app_light_off()
{
    value[LIGHT_COLD] = 0;
    cai_ctrl_read_callback(0);
    bls_att_pushNotifyData(CAT_CTRL_VALUE_H, ctrl, sizeof(ctrl));
}

unsigned int app_light_get()
{
    return value[LIGHT_COLD];
}

void app_light_adv()
{
    value[LIGHT_BLUE] = 1;
	value[LIGHT_GREEN] = 0;
    value[LIGHT_RED] = 0;
}

void app_light_error()
{
    value[LIGHT_BLUE] = 0;
	value[LIGHT_GREEN] = 0;
    value[LIGHT_RED] = 1;
}

void app_light_connect()
{
    value[LIGHT_BLUE] = 0;
	value[LIGHT_GREEN] = 1;
    value[LIGHT_RED] = 0;
}