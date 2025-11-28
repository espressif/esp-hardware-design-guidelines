.. _IO MUX Pin Functions:

.. list-table:: IO Pin Default Functions
   :header-rows: 1
   :widths: 20 20 20 20 20

   * - Pin No
     - Pin Name
     - Pin Providing Power
     - At Reset
     - After Reset
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
     -
     -
   * - 9
     - MTMS
     - VDDPST1
     - IE
     - IE
   * - 10
     - MTDI
     - VDDPST1
     - IE
     - IE
   * - 11
     - MTCK
     - VDDPST1
     -
     - IE
   * - 12
     - MTDO
     - VDDPST1
     -
     - IE
   * - 13
     - SDIO_CMD
     - VDDPST2
     -
     - IE
   * - 14
     - SDIO_CLK
     - VDDPST2
     -
     - IE
   * - 15
     - SDIO_DATA0
     - VDDPST2
     -
     - IE
   * - 16
     - SDIO_DATA1
     - VDDPST2
     -
     - IE
   * - 17
     - SDIO_DATA2
     - VDDPST2
     -
     - IE
   * - 18
     - SDIO_DATA3
     - VDDPST2
     -
     - IE
   * - 19
     - SPICS1
     - VDD_SPI/VDDPST2
     -
     -
   * - 20
     - SPICS0
     - VDD_SPI/VDDPST2
     -
     -
   * - 22
     - SPIQ
     - VDD_SPI/VDDPST2
     -
     -
   * - 23
     - SPIWP
     - VDD_SPI/VDDPST2
     -
     -
   * - 24
     - VDD_SPI
     - VDDPST2
     -
     -
   * - 25
     - SPIHD
     - VDD_SPI/VDDPST2
     -
     -
   * - 26
     - SPICLK
     - VDD_SPI/VDDPST2
     -
     -
   * - 27
     - SPID
     - VDD_SPI/VDDPST2
     -
     -
   * - 28
     - USB_D-
     - VDDPST2
     -
     - IE
   * - 29
     - USB_D+
     - VDDPST2
     - USB_PU
     - IE,USB_PU
   * - 30
     - GPIO24
     - VDDPST2
     -
     -
   * - 31
     - GPIO8
     - VDDPST2
     - IE
     - IE
   * - 32
     - GPIO9
     - VDDPST2
     - IE,WPU
     - IE,WPU
   * - 33
     - U0RXD
     - VDDPST2
     -
     - IE,WPU
   * - 34
     - U0TXD
     - VDDPST2
     -
     - IE,WPU
   * - 35
     - GPIO29
     - VDDPST2
     -
     -
   * - 36
     - GPIO7
     - VDDPST2
     - IE
     - IE

- IE -- input enabled
- WPU -- internal weak pull-up resistor enabled
- USB_PU -- USB pull-up resistor enabled
