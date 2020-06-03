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

#define TFT_BL 14
Arduino_DataBus *bus = new Arduino_ESP32SPI(21 /* DC */, 5 /* CS */, SCK, MOSI, MISO);
Arduino_ST7789 *gfx = new Arduino_ST7789(bus, -1 /* RST */, 1 /* rotation */, true /* IPS */);

extern "C"
{
#include "nofrendo.h"
}

extern uint16_t myPalette[];
uint16_t buf[32];

extern "C" void lcd_write_frame(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t *data[])
{
    if (data == NULL)
    {
        gfx->fillRect(x, y, width, height, BLACK);
    }
    else
    {
        uint8_t n, l;
        uint16_t i, len;
        const uint8_t *d;
        uint16_t *p;
        gfx->startWrite();
        gfx->writeAddrWindow(x, y, width, height);
        for (i = 0; i < height; i++)
        {
            l = 32;
            d = data[i];
            len = width;
            while (len)
            {
                p = buf;
                if (len < 32)
                {
                    l = len;
                }
                n = l;
                while (n--)
                {
                    *(p++) = myPalette[*(d++)];
                }
                gfx->writePixels(buf, l);
                len -= l;
            }
        }
        gfx->endWrite();
    }
}

extern "C" void lcd_init()
{
    gfx->begin();
    gfx->fillScreen(BLACK);
#if defined(TFT_BL)
    pinMode(TFT_BL, OUTPUT);    // sets the pin as output
    digitalWrite(TFT_BL, HIGH); // power on
#endif
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
