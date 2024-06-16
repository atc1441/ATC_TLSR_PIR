#pragma once
#include <stdint.h>
#include "app_config.h"
#include "app.h"
#include "battery.h"
#include "ble.h"
#include "cmd_parser.h"
#include "flash.h"
#include "led.h"
#include "ota.h"
#include "uart.h"

#define LED_BLUE	GPIO_PB4

#define RXD 		GPIO_PB7
#define TXD			GPIO_PB1

#define BUTTON_IN   GPIO_PC3
#define PIR_IN      GPIO_PC2




// ADC = Port C4
