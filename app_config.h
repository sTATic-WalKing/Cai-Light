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

typedef enum
{
	ATT_H_START = 0,

	GAP_H,
	GAP_DEVICE_NAME_CHARACTER_H,
	GAP_DEVICE_NAME_VALUE_H,

	GATT_H,
	GATT_SERVICE_CHANGED_CHARACTER_H,
	GATT_SERVICE_CHANGED_VALUE_H,
    GATT_SERVICE_CHANGED_CCCD_H,

    CAI_H,
    CAT_CTRL_CHARACTER_H,
    CAT_CTRL_VALUE_H,
    CAT_CTRL_CCCD_H,

	ATT_H_END,

} ATT_HANDLE;

int cai_ctrl_read_callback(void *p);


#if defined(__cplusplus)
}
#endif
