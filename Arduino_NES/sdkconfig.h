#ifndef _SDKCONFIG_H_
#define _SDKCONFIG_H_

#define CONFIG_HW_LCD_TYPE 2
#define CONFIG_HW_LCD_IPS 1
#define CONFIG_HW_LCD_MISO_GPIO 19
#define CONFIG_HW_LCD_MOSI_GPIO 23
#define CONFIG_HW_LCD_CLK_GPIO 18
#define CONFIG_HW_LCD_CS_GPIO 5
#define CONFIG_HW_LCD_DC_GPIO 21
#define CONFIG_HW_LCD_RST_GPIO -1
#define CONFIG_HW_LCD_BL_GPIO 14
//#define CONFIG_HW_INV_BL
#define CONFIG_HW_LCD_CLOCK_SPEED 40
//#define CONFIG_HW_LCD_ROTATE_180

#define CONFIG_SOUND_ENA 1

#define CONFIG_HW_CONTROLLER_GPIO 1
#define CONFIG_HW_GPIO_UP 35
#define CONFIG_HW_GPIO_DOWN 35
#define CONFIG_HW_GPIO_LEFT 34
#define CONFIG_HW_GPIO_RIGHT 34
#define CONFIG_HW_GPIO_MENU 13
#define CONFIG_HW_GPIO_AUDIO 0
#define CONFIG_HW_GPIO_SELECT 27
#define CONFIG_HW_GPIO_START 39
#define CONFIG_HW_GPIO_A 32
#define CONFIG_HW_GPIO_B 33

//#define CONFIG_HW_CONTROLLER_I2C_GP

//#define CONFIG_HW_CONTROLLER_I2C_KB

// #define CONFIG_HW_CONTROLLER_PSX
// #define CONFIG_HW_PSX_CLK
// #define CONFIG_HW_PSX_DAT
// #define CONFIG_HW_PSX_ATT
// #define CONFIG_HW_PSX_CMD

#endif