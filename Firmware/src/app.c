#include <stdint.h>
#include "tl_common.h"
#include "app.h"
#include "main.h"
#include "drivers.h"
#include "stack/ble/ble.h"
#include "vendor/common/blt_common.h"

#include "battery.h"
#include "ble.h"
#include "flash.h"
#include "ota.h"
#include "time.h"

RAM uint8_t battery_level;
RAM uint16_t battery_mv;
RAM int16_t temperature;

RAM uint8_t should_update_adv = 0;
RAM uint32_t last_GPIO_second = 0;
extern uint16_t curr_adv_intervall;
// Settings
extern settings_struct settings;

_attribute_ram_code_ void user_init_normal(void)
{                            // this will get executed one time after power up
    random_generator_init(); // must
    init_time();
    init_ble();
    init_flash();
}

_attribute_ram_code_ void user_init_deepRetn(void)
{ // after sleep this will get executed
    blc_ll_initBasicMCU();
    rf_set_power_level_index(RF_POWER_P3p01dBm);
    blc_ll_recoverDeepRetention();
}

_attribute_ram_code_ void main_loop(void)
{
    blt_sdk_main_loop();
    handler_time();

    if (should_update_adv)
    {
        should_update_adv = 0;
        set_adv_data(gpio_read(BUTTON_IN) ? 1 : 0, gpio_read(PIR_IN) ? 1 : 0, battery_level, battery_mv);
        ble_send_battery(battery_level);
        ble_send_temp(gpio_read(BUTTON_IN) ? 1 : 0);
    }

    if (time_reached_period(Timer_CH_1, 60))
    {
        battery_mv = get_battery_mv();
        battery_level = get_battery_level(battery_mv);
	    printf("Battery: %dmV Temp: %dC°\r\n", battery_mv, 0xABC1);
        set_adv_data(0xABC1, gpio_read(PIR_IN) ? 1 : 0, battery_level, battery_mv);
        ble_send_battery(battery_level);
        ble_send_temp(0xABC1);
    }

    if (!ble_get_connected() && (curr_adv_intervall != ADVERTISING_INTERVAL))
    {
        if (get_time() - last_GPIO_second >= 10)
        {
	        printf("Stopping Fast Advertising now, Time: %d LastGpio: %d\r\n", get_time(), last_GPIO_second);
            app_switch_to_indirect_adv(ADVERTISING_INTERVAL);
        }
    }

    blt_pm_proc();
}
