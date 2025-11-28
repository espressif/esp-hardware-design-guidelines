.. _IO MUX Pin Functions:

.. csv-table:: IO Pin Default Configuration
    :header-rows: 1

    No.,Name,Power,At Reset,After Reset
    1,LNA_IN,,
    2,VDD3P3,,
    3,VDD3P3,,
    4,CHIP_PU,VDD3P3_RTC,,
    5,GPIO0,VDD3P3_RTC,"IE, WPU","IE, WPU"
    6,GPIO1,VDD3P3_RTC,IE,IE
    7,GPIO2,VDD3P3_RTC,IE,IE
    8,GPIO3,VDD3P3_RTC,IE,IE
    9,GPIO4,VDD3P3_RTC,,
    10,GPIO5,VDD3P3_RTC,,
    11,GPIO6,VDD3P3_RTC,,
    12,GPIO7,VDD3P3_RTC,,
    13,GPIO8,VDD3P3_RTC,,
    14,GPIO9,VDD3P3_RTC,,IE
    15,GPIO10,VDD3P3_RTC,,IE
    16,GPIO11,VDD3P3_RTC,,IE
    17,GPIO12,VDD3P3_RTC,,IE
    18,GPIO13,VDD3P3_RTC,,IE
    19,GPIO14,VDD3P3_RTC,,IE
    20,VDD3P3_RTC,,,
    21,XTAL_32K_P,VDD3P3_RTC,,
    22,XTAL_32K_N,VDD3P3_RTC,,
    23,GPIO17,VDD3P3_RTC,,IE
    24,GPIO18,VDD3P3_RTC,,IE
    25,GPIO19,VDD3P3_RTC,,
    26,GPIO20,VDD3P3_RTC,USB_PU,USB_PU
    27,GPIO21,VDD3P3_RTC,,
    28,SPICS1,VDD_SPI,"IE, WPU","IE, WPU"
    29,VDD_SPI,,,
    30,SPIHD,VDD_SPI,"IE, WPU","IE, WPU"
    31,SPIWP,VDD_SPI,"IE, WPU","IE, WPU"
    32,SPICS0,VDD_SPI,"IE, WPU","IE, WPU"
    33,SPICLK,VDD_SPI,"IE, WPU","IE, WPU"
    34,SPIQ,VDD_SPI,"IE, WPU","IE, WPU"
    35,SPID,VDD_SPI,"IE, WPU","IE, WPU"
    36,SPICLK_N,VDD_SPI / VDD3P3_CPU,IE,IE
    37,SPICLK_P,VDD_SPI / VDD3P3_CPU,IE,IE
    38,GPIO33,VDD_SPI / VDD3P3_CPU,,IE
    39,GPIO34,VDD_SPI / VDD3P3_CPU,,IE
    40,GPIO35,VDD_SPI / VDD3P3_CPU,,IE
    41,GPIO36,VDD_SPI / VDD3P3_CPU,,IE
    42,GPIO37,VDD_SPI / VDD3P3_CPU,,IE
    43,GPIO38,VDD3P3_CPU,,IE
    44,MTCK,VDD3P3_CPU,,IE
    45,MTDO,VDD3P3_CPU,,IE
    46,VDD3P3_CPU,,
    47,MTDI,VDD3P3_CPU,,IE
    48,MTMS,VDD3P3_CPU,,IE
    49,U0TXD,VDD3P3_CPU,"IE, WPU","IE, WPU"
    50,U0RXD,VDD3P3_CPU,"IE, WPU","IE, WPU"
    51,GPIO45,VDD3P3_CPU,"IE, WPD","IE, WPD"
    52,GPIO46,VDD3P3_CPU,"IE, WPD","IE, WPD"
    53,XTAL_N,,
    54,XTAL_P,,
    55,VDDA,,
    56,VDDA,,
    57,GND,,

- IE -- input enabled
- WPU -- internal weak pull-up resistor enabled
- WPD -- internal weak pull-down resistor enabled
- USB_PU -- USB pull-up resistor enabled

    - By default, the USB function is enabled for USB pins (i.e., GPIO19 and GPIO20), and the pin pull-up is decided by the USB pull-up resistor. The USB pull-up resistor is controlled by USB_SERIAL_JTAG_DP/DM_PULLUP and the pull-up value is controlled by USB_SERIAL_JTAG_PULLUP_VALUE. For details, see `{IDF_TARGET_NAME} Technical Reference Manual <{IDF_TARGET_TRM_EN_URL}>`__ > Chapter *USB Serial/JTAG Controller*.
    - When the USB function is disabled, USB pins are used as regular GPIOs and the pin's internal weak pull-up and pull-down resistors are disabled by default (configurable by IO_MUX_FUN_WPU/WPD)

