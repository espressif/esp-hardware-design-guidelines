.. _IO MUX Pin Functions:

.. list-table:: IO Pin Default Functions
   :header-rows: 1
   :widths: 20 20 20 20 20

   * - Pin No
     - Pin Name
     - Pin Providing Power
     - At Reset
     - After Reset
   * - 9
     - XTAL_32K_P I
     - VDDPST1
     -
     -
   * - 10
     - XTAL_32K_N
     - VDDPST1
     -
     -
   * - 11
     - MTMS
     - VDDPST1
     - IE
     - IE
   * - 12
     - MTDI
     - VDDPST1
     - IE
     - IE
   * - 13
     - MTCK
     - VDDPST1
     -
     - IE, WPU
   * - 14
     - MTDO
     - VDDPST1
     - IE
     - IE
   * - 15
     - GPIO6
     - VDDPST1
     - IE
     - IE
   * - 16
     - GPIO7
     - VDDPST1
     - IE
     - IE
   * - 17
     - GPIO8
     - VDDPST1
     -
     - IE
   * - 18
     - GPIO9
     - VDDPST1
     -
     - IE
   * - 19
     - GPIO10
     - VDDPST1
     -
     - IE
   * - 20
     - U0TXD
     - VDDPST1
     -
     - WPU
   * - 21
     - U0RXD
     - VDDPST1
     -
     - IE, WPU
   * - 22
     - GPIO13
     - VDDPST2
     -
     - IE
   * - 23
     - GPIO14
     - VDDPST2
     - USB_PU
     - IE, USB_PU
   * - 25
     - SPICS1
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 26
     - SPICS0
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 27
     - SPIQ
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 28
     - SPIWP
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 29
     - VDD_SPI
     -
     -
     -
   * - 30
     - SPIHD
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 31
     - SPICLK
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 32
     - SPID
     - VDD_SPI
     - WPU
     - IE, WPU
   * - 33
     - GPIO23
     - VDDPST3
     - 
     - IE
   * - 34
     - GPIO24
     - VDDPST3
     - 
     - IE
   * - 35
     - GPIO25
     - VDDPST3
     - IE
     - IE
   * - 36
     - GPIO26
     - VDDPST3
     - IE
     - IE
   * - 37
     - GPIO27
     - VDDPST3
     - IE, WPU
     - IE, WPU
   * - 38
     - GPIO28
     - VDDPST3
     - IE, WPU
     - IE, WPU

- IE -- input enabled
- WPU -- internal weak pull-up resistor enabled
