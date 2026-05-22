.. _IO MUX Pin Functions:

.. csv-table:: IO Pin Default Configuration
    :header-rows: 1

    No.,Name,Power,At Reset,After Reset
    1,ANT,,,
    2,VDDA3,,,
    3,VDDA4,,,
    4,CHIP_PU,,,
    5,XTAL_32K_N/GPIO0,VDDPST_1,,
    6,XTAL_32K_P/GPIO1,VDDPST_1,,
    7,GPIO2,VDDPST_1,,
    8,GPIO3,VDDPST_1,,
    9,GPIO4,VDDPST_1,,
    10,GPIO5,VDDPST_1,,
    11,VDDPST_1,,,
    12,GPIO6,VDDPST_1,,
    13,GPIO7,VDDPST_1,,
    14,GPIO8,VDDPST_1,,IE
    15,GPIO9,VDDPST_1,,IE
    16,GPIO10,VDDPST_1,,IE
    17,GPIO11,VDDPST_1,,IE
    18,VREF_TOUCH,,,
    19,GPIO12,VDDPST_1,,IE
    20,GPIO13,VDDPST_1,,IE
    21,GPIO14,VDDPST_1,,IE
    22,GPIO15,VDDPST_1,,IE
    23,GPIO16,VDDPST_1,,IE
    24,GPIO17,VDDPST_1,,IE
    25,GPIO18,VDDPST_1,,IE
    26,GPIO19,VDDPST_1,,IE
    27,SDIO_DATA0,VDDPST_SD,,IE
    28,SDIO_DATA1,VDDPST_SD,,IE
    29,SDIO_DATA2,VDDPST_SD,,IE
    30,VDD_PSRAM_1P8_1,,,
    31,SDIO_DATA3,VDDPST_SD,,IE
    32,SDIO_CLK,VDDPST_SD,,IE
    33,SDIO_CMD,VDDPST_SD,,IE
    34,VDD_PSRAM_1P8_2,,,
    35,VDD_LDO_1P8,,,
    36,SPICS,VDD_SPI,WPU,"WPU, IE"
    37,SPIQ,VDD_SPI,WPU,"WPU, IE"
    38,SPIWP,VDD_SPI,WPU,"WPU, IE"
    39,VDD_SPI,,,
    40,SPIHD,VDD_SPI,WPU,"WPU, IE"
    41,SPICLK,VDD_SPI,WPU,"WPU, IE"
    42,SPID,VDD_SPI,WPU,"WPU, IE"
    43,VCCA/VDDPST_2,,,
    44,USB_DP,VDDPST_2,,
    45,USB_DM,VDDPST_2,,
    46,GPIO33,VDDPST_3,DRV=3,"USB_PU, IE, DRV=3"
    47,GPIO34,VDDPST_3,DRV=3,"USB_PU, IE, DRV=3"
    48,GPIO35,VDDPST_3,,IE
    49,GPIO36,VDDPST_3,IE,IE
    50,GPIO37,VDDPST_3,IE,IE
    51,GPIO38,VDDPST_3,IE,IE
    52,GPIO39,VDDPST_3,IE,IE
    53,GPIO40,VDDPST_3,IE,IE
    54,VDDPST_3,,,
    55,GPIO42,VDDPST_3,,IE
    56,GPIO43,VDDPST_3,,IE
    57,GPIO44,VDDPST_3,,IE
    58,GPIO45,VDDPST_3,,IE
    59,GPIO46,VDDPST_3,,IE
    60,GPIO47,VDDPST_3,,IE
    61,GPIO48,VDDPST_3,,
    62,GPIO49,VDDPST_3,,
    63,VREF_ADC,,,
    64,VDDPST_4,,,
    65,GPIO50,VDDPST_4,,
    66,GPIO51,VDDPST_4,,
    67,GPIO52,VDDPST_4,,IE
    68,GPIO53,VDDPST_4,,IE
    69,MTDO,VDDPST_4,,IE
    70,MTCK,VDDPST_4,,IE
    71,MTDI,VDDPST_4,,IE
    72,MTMS,VDDPST_4,,IE
    73,GPIO58,VDDPST_4,,IE
    74,GPIO59,VDDPST_4,,IE
    75,GPIO60,VDDPST_4,"WPU, IE","WPU, IE"
    76,GPIO61,VDDPST_4,"WPU, IE","WPU, IE"
    77,VDDA1,,,
    78,XTAL_N,,,
    79,XTAL_P,,,
    80,VDDA2,,,
    81,GND,,,

- IE -- input enabled
- WPU -- internal weak pull-up resistor enabled
- DRV -- drive strength

  - Values 0 ~ 3 correspond to approximately 5, 10, 20, and 40 mA respectively.
  - The default drive current of GPIO33 and GPIO34 is 40 mA. The default drive current of all other IO pins is 20 mA.

- USB_PU -- USB pull-up resistor enabled

  - USB pins (GPIO33 and GPIO34) are configured for the USB function by default. Whether these pins are pulled up is determined by the USB pull-up resistor. The USB pull-up is controlled by USB_SERIAL_JTAG_DP/DM_PULLUP, and the USB pull-up resistor value can be controlled through the USB_SERIAL_JTAG_PULLUP_VALUE bit.
  - When the USB function is disabled, the USB pins are used as regular GPIOs, with their internal weak pull-up and pull-down resistors disabled by default. They can be configured through IO_MUX_GPIOn_MCU_WPU/WPD.
