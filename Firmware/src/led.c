#include <stdint.h>
#include "tl_common.h"
#include "drivers.h"
#include "stack/ble/ble.h"
#include "drivers/8258/flash.h"
#include "led.h"
#include "main.h"

_attribute_ram_code_ void init_led(void)
{
    gpio_setup_up_down_resistor(LED_BLUE, PM_PIN_PULLUP_1M);
    gpio_write(LED_BLUE, 0);
    gpio_set_func(LED_BLUE, AS_GPIO);
    gpio_set_output_en(LED_BLUE, 1);
    gpio_set_input_en(LED_BLUE, 0);

    gpio_set_func(BUTTON_IN, AS_GPIO);
    gpio_set_output_en(BUTTON_IN, 0);
    gpio_set_input_en(BUTTON_IN, 1);

    //gpio_setup_up_down_resistor(PIR_IN, PM_PIN_PULLDOWN_100K);
    //gpio_write(PIR_IN, 1);
    gpio_set_func(PIR_IN, AS_GPIO);
    gpio_set_output_en(PIR_IN, 0);
    gpio_set_input_en(PIR_IN, 1);
}

_attribute_ram_code_ void set_led_color(uint8_t color)
{
    gpio_write(LED_BLUE,!color);
}
