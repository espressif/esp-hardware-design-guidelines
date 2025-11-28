.. _IO MUX Pin Functions:

.. list-table:: IO MUX Pin Functions
   :header-rows: 1
   :widths: 10 15 15 15 15

   * - Pin No
     - Pin Name
     - Pin Providing Power
     - At Reset
     - After Reset
   * - 1
     - ANT
     -
     -
     -
   * - 2
     - VDDA3P3
     -
     -
     -
   * - 3
     - VDDA3P3
     -
     -
     -
   * - 4
     - CHIP_PU
     -
     -
     -
   * - 5
     - VDDPST1
     -
     -
     -
   * - 6
     - XTAL_32K_P
     - VDDPST1
     -
     -
   * - 7
     - XTAL_32K_N
     - VDDPST1
     -
     -
   * - 8
     - GPIO2
     - VDDPST1
     - IE
     - IE
   * - 9
     - GPIO3
     - VDDPST1
     - IE
     - IE
   * - 10
     - MTMS
     - VDDPST1
     - IE
     - IE
   * - 11
     - MTDI
     - VDDPST1
     - IE
     - IE
   * - 12
     - MTCK
     - VDDPST1
     -
     - IE, WPU
   * - 13
     - MTDO
     - VDDPST1
     -
     - IE
   * - 14
     - GPIO8
     - VDDPST2
     - IE
     - IE
   * - 15
     - GPIO9
     - VDDPST2
     - IE, WPU
     - IE, WPU
   * - 16
     - GPIO10
     - VDDPST2
     -
     - IE
   * - 17
     - GPIO11
     - VDDPST2
     -
     - IE
   * - 18
     - GPIO12
     - VDDPST2
     -
     - IE
   * - 19
     - GPIO13
     - VDDPST2
     -
     - IE, WPU
   * - 20
     - SPICS0
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 21
     - SPIQ
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 22
     - SPIWP
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 23
     - VDD_SPI
     -
     -
     -
   * - 24
     - SPIHD
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 25
     - SPICLK
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 26
     - SPID
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 27
     - GPIO15
     - VDDPST2
     - IE
     - IE
   * - 28
     - VDDPST2
     -
     -
     -
   * - 29
     - U0TXD
     - VDDPST2
     -
     - WPU
   * - 30
     - U0RXD
     - VDDPST2
     -
     - IE, WPU
   * - 31
     - SDIO_CMD
     - VDDPST2
     - WPU
     - IE
   * - 32
     - SDIO_CLK
     - VDDPST2
     - WPU
     - IE
   * - 33
     - SDIO_DATA0
     - VDDPST2
     - WPU
     - IE
   * - 34
     - SDIO_DATA1
     - VDDPST2
     - WPU
     - IE
   * - 35
     - SDIO_DATA2
     - VDDPST2
     - WPU
     - IE
   * - 36
     - SDIO_DATA3
     - VDDPST2
     - WPU
     - IE
   * - 37
     - VDDA1
     -
     -
     -
   * - 38
     - XTAL_N
     -
     -
     -
   * - 39
     - XTAL_P
     -
     -
     -
   * - 40
     - VDDA2
     -
     -
     -
   * - 41
     - GND
     -
     -
     -

- IE -- input enabled  
- WPU -- internal weak pull-up resistor enabled  
- WPD -- internal weak pull-down resistor enabled  
- USB_PU -- USB pull-up resistor enabled

  * By default, the USB function is enabled for USB pins (i.e., GPIO12 and GPIO13), and the pin pull-up is decided by the USB pull-up resistor. The USB pull-up resistor is controlled by ``USB_SERIAL_JTAG_DP/DM_PULLUP`` and the pull-up value is controlled by ``USB_SERIAL_JTAG_PULLUP_VALUE``. For details, see `{IDF_TARGET_NAME} Technical Reference Manual <{IDF_TARGET_TRM_EN_URL}>`__ > Chapter *USB Serial/JTAG Controller*.

  * When the USB function is disabled, USB pins are used as regular GPIOs. At reset, GPIO13's internal weak pull-up resistor is disabled by default. After reset, GPIO13's internal weak pull-up resistor is enabled by default. A pin's internal weak pull-up and pull-down resistors are configurable by ``IO_MUX_FUN_WPU/WPD``. For details, see :`{IDF_TARGET_NAME} Technical Reference Manual <{IDF_TARGET_TRM_EN_URL}>`__ > Chapter *IO MUX and GPIO Matrix*.
