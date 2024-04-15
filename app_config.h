#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

#define BLE_NAME 'L', 'i'
#define BLE_NAME_SIZE 2

#define LIGHT_COLD 4
#define LIGHT_WARM 3
#define LIGHT_RED 1
#define LIGHT_GREEN 2
#define LIGHT_BLUE 0

#define CAI_SERVICE 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
#define CAI_CTRL 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01

#define HCI_LOG_FW_EN 1
#define DEBUG_INFO_TX_PIN UART_TX_PB1
#define TL_LOG_LEVEL TL_LOG_LEVEL_MAX

#include <vendor/common/default_config.h>

#if defined(__cplusplus)
}
#endif
