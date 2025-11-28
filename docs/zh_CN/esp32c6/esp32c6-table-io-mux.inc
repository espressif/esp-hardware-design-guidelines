.. _IO MUX Pin Functions:

.. list-table:: IO MUX 管脚功能
   :header-rows: 1
   :widths: 10 10 10 10 10

   * - 管脚序号
     - 管脚名称
     - 供电管脚
     - 复位时
     - 复位后
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
     - IE, USB_PU
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

- IE -- 输入使能
- WPU -- 内部弱上拉电阻使能
- WPD -- 内部弱下拉电阻使能
- USB_PU -- USB 上拉电阻使能*

  * USB 管脚（GPIO12 和 GPIO13）默认开启 USB 功能，此时管脚是否上拉由 USB 上拉电阻决定。USB 上拉电阻由 ``USB_SERIAL_JTAG_DP/DM_PULLUP`` 控制，具体阻值可通过 ``USB_SERIAL_JTAG_PULLUP_VALUE`` 位控制，详见 `{IDF_TARGET_NAME} 技术参考手册 <{IDF_TARGET_TRM_CN_URL}>`__ > 章节 *USB 串口/JTAG 控制器*。
  
  * USB 管脚关闭 USB 功能时，用作普通 GPIO。复位时 GPIO13 管脚内部弱上下拉电阻默认禁用。复位后 GPIO13 管脚内部弱上拉电阻默认使能。管脚内部上下拉电阻可通过 ``IO_MUX_FUN_WPU/WPD`` 配置，详见 `{IDF_TARGET_NAME} 技术参考手册 <{IDF_TARGET_TRM_CN_URL}>`__ > 章节 *IO MUX 和 GPIO 交换矩阵*。

