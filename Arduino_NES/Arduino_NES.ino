#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "esp_partition.h"

#include "Arduino_ESP32SPI.h"
#include "Arduino_Display.h" // Various display driver

extern "C"
{
#include "nofrendo.h"
}

extern "C" char *osd_getromdata()
{
    char *romdata;
    const esp_partition_t *part;
    spi_flash_mmap_handle_t hrom;
    esp_err_t err;
    nvs_flash_init();
    part = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_1, "app1");
    if (part == 0)
        printf("Couldn't find rom part!\n");
    err = esp_partition_mmap(part, 0, 0x140000, SPI_FLASH_MMAP_DATA, (const void **)&romdata, &hrom);
    if (err != ESP_OK)
        printf("Couldn't map rom part!\n");
    printf("Initialized. ROM@%p\n", romdata);
    return (char *)romdata;
}

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

void setup()
{
    nofrendo_main(0, NULL);
}

void loop()
{
    delay(1000); // just make the loop not too faster
}
