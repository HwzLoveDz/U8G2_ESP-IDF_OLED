#include <driver/gpio.h>
#include <driver/spi_master.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <string.h>
#include <u8g2.h>

#include "sdkconfig.h"
#include "u8g2_esp32_hal.h"

// SDA - GPIO21
#define PIN_SDA I2C_MASTER_SDA_IO

// SCL - GPIO22
#define PIN_SCL I2C_MASTER_SCL_IO

static const char *TAG = "ssd1306";

u8g2_t u8g2; // a structure which will contain all the data for one display

void app_main(void)
{
	u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
	u8g2_esp32_hal.sda  = PIN_SDA;
	u8g2_esp32_hal.scl  = PIN_SCL;
	u8g2_esp32_hal_init(u8g2_esp32_hal);
    u8g2_Setup_ssd1306_i2c_128x32_univision_f(&u8g2, U8G2_R2, /* u8x8_byte_sw_i2c */ u8g2_esp32_i2c_byte_cb, u8x8_gpio_and_delay_lpc11u3x); // init u8g2 structure
    // u8g2_Setup_ssd1306_128x32_univision_1 [page buffer, size = 128 bytes]
    // u8g2_Setup_ssd1306_128x32_univision_2 [page buffer, size = 256 bytes]
    // u8g2_Setup_ssd1306_128x32_univision_f [full framebuffer, size = 512 bytes]
	u8x8_SetI2CAddress(&u8g2.u8x8, 0x78);

    ESP_LOGI(TAG, "u8g2_InitDisplay");
    u8g2_InitDisplay(&u8g2);     // send init sequence to the display, display is in sleep mode after this,
    // u8g2_InitInterface(&u8g2); // just init the interface, do not reset the display, do not send any data to the display
    u8g2_SetPowerSave(&u8g2, 0); // wake up display

	u8g2_ClearBuffer(&u8g2);

	u8g2_DrawBox(&u8g2, 10, 26, 80,6);
	u8g2_DrawFrame(&u8g2, 10,26,100,6);

    u8g2_SetFont(&u8g2, u8g2_font_sticker100complete_te);
    u8g2_DrawStr(&u8g2, 2,17,"Hello ESP-IDF!");
	
	u8g2_SendBuffer(&u8g2);

	vTaskDelete(NULL);
}

