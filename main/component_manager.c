#include <stdio.h>
#include "cmp.h"
#include "lvgl.h"
#include "lvgl_port.h"  // Ensure this is included for LVGL initialization
#include "waveshare_rgb_lcd_port.h"
#include "ui.h"

void app_main(void)
{
    cmp_hello();

    ESP_LOGI(TAG, "Free heap: %d, Free PSRAM: %d", heap_caps_get_free_size(MALLOC_CAP_8BIT), heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
    ESP_LOGI(TAG, "LVGL_PORT_BUFFER_MALLOC_CAPS: 0x%x", LVGL_PORT_BUFFER_MALLOC_CAPS);

    waveshare_esp32_s3_rgb_lcd_init();

    ui_init(); // Call the UI initialization
}
