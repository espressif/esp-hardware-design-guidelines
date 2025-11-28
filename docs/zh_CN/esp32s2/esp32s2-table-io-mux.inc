.. _IO MUX Pin Functions:

.. list-table:: IO MUX 管脚功能
   :header-rows: 1
   :widths: 10 10 10 10 10 10 10 10 20

   * - 管脚序号
     - 管脚名称
     - 管脚类型
     - 电源域
     - 复位时
     - 复位后
     - 数字功能 0
     - RTC
     - 模拟
   * - 1
     - VDDA
     - 电源
     -
     -
     -
     -
     -
     -
   * - 2
     - LNA_IN
     - 电源
     -
     -
     -
     -
     -
     -
   * - 3
     - VDD3P3
     - 电源
     -
     -
     -
     -
     -
     -
   * - 4
     - VDD3P3
     - 电源
     -
     -
     -
     -
     -
     -
   * - 5
     - GPIO0
     - IO
     - VDD3P3_RTC_IO
     - IE, WPU
     - IE, WPU
     - IO MUX
     - RTC
     -
   * - 6
     - GPIO1
     - IO
     - VDD3P3_RTC_IO
     - IE
     - IE
     - IO MUX
     - RTC
     - 模拟
   * - 7
     - GPIO2
     - IO
     - VDD3P3_RTC_IO
     - IE
     - IE
     - IO MUX
     - RTC
     - 模拟
   * - 8
     - GPIO3
     - IO
     - VDD3P3_RTC_IO
     - IE
     -
     - IO MUX
     - RTC
     - 模拟
   * - 9
     - GPIO4
     - IO
     - VDD3P3_RTC_IO
     - IE
     -
     - IO MUX
     - RTC
     - 模拟
   * - 10
     - GPIO5
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - 模拟
   * - 11
     - GPIO6
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - 模拟
   * - 12
     - GPIO7
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - 模拟
   * - 13
     - GPIO8
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - 模拟
   * - 14
     - GPIO9
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - 模拟
   * - 15
     - GPIO10
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - 模拟
   * - 16
     - GPIO11
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - 模拟
   * - 17
     - GPIO12
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - 模拟
   * - 18
     - GPIO13
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - 模拟
   * - 19
     - GPIO14
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - 模拟
   * - 20
     - VDD3P3_RTC
     - 电源
     -
     -
     -
     -
     -
     -
   * - 21
     - XTAL_32K_P
     - 模拟
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - 模拟
   * - 22
     - XTAL_32K_N
     - 模拟
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - 模拟
   * - 23
     - DAC_1
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - 模拟
   * - 24
     - DAC_2
     - IO
     - VDD3P3_RTC_IO
     -
     - IE, WPU
     - IO MUX
     - RTC
     - 模拟
   * - 25
     - GPIO19
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - 模拟
   * - 26
     - GPIO20
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - 模拟
   * - 27
     - VDD3P3_RTC_IO
     - 电源
     -
     -
     -
     -
     -
     -
   * - 28
     - GPIO21
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     -
   * - 29
     - SPICS1
     - IO
     - VDD_SPI
     - IE, WPU
     - IE, WPU
     - IO MUX
     -
     -
   * - 30
     - VDD_SPI
     - 电源
     -
     -
     -
     -
     -
     -
   * - 31
     - SPIHD
     - IO
     - VDD_SPI
     - IE, WPU
     - IE, WPU
     - IO MUX
     -
     -
   * - 32
     - SPIWP
     - IO
     - VDD_SPI
     - IE, WPU
     - IE, WPU
     - IO MUX
     -
     -
   * - 33
     - SPICS0
     - IO
     - VDD_SPI
     - IE, WPU
     - IE, WPU
     - IO MUX
     -
     -
   * - 34
     - SPICLK
     - IO
     - VDD_SPI
     - IE, WPU
     - IE, WPU
     - IO MUX
     -
     -
   * - 35
     - SPIQ
     - IO
     - VDD_SPI
     - IE, WPU
     - IE, WPU
     - IO MUX
     -
     -
   * - 36
     - SPID
     - IO
     - VDD_SPI
     - IE, WPU
     - IE, WPU
     - IO MUX
     -
     -
   * - 37
     - GPIO33
     - IO
     - VDD_SPI / VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 38
     - GPIO34
     - IO
     - VDD_SPI / VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 39
     - GPIO35
     - IO
     - VDD_SPI / VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 40
     - GPIO36
     - IO
     - VDD_SPI / VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 41
     - GPIO37
     - IO
     - VDD_SPI / VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 42
     - GPIO38
     - IO
     - VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 43
     - MTCK
     - IO
     - VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 44
     - MTDO
     - IO
     - VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 45
     - VDD3P3_CPU
     - 电源
     -
     -
     -
     -
     -
     -
   * - 46
     - MTDI
     - IO
     - VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 47
     - MTMS
     - IO
     - VDD3P3_CPU
     -
     - IE
     - IO MUX
     -
     -
   * - 48
     - U0TXD
     - IO
     - VDD3P3_CPU
     - IE, WPU
     - IE, WPU
     - IO MUX
     -
     -
   * - 49
     - U0RXD
     - IO
     - VDD3P3_CPU
     - IE, WPU
     - IE, WPU
     - IO MUX
     -
     -
   * - 50
     - GPIO45
     - IO
     - VDD3P3_CPU
     - IE, WPD
     - IE, WPD
     - IO MUX
     -
     -
   * - 51
     - VDDA
     - 电源
     -
     -
     -
     -
     -
     -
   * - 52
     - XTAL_N
     - IO
     -
     -
     -
     -
     -
     -
   * - 53
     - XTAL_P
     - IO
     -
     -
     -
     -
     -
     -
   * - 54
     - VDDA
     - 电源
     -
     -
     -
     -
     -
     -
   * - 55
     - GPIO46
     - IO
     - VDD3P3_CPU
     - IE, WPD
     - IE, WPD
     - IO MUX
     -
     -
   * - 56
     - CHIP_PU
     - 模拟
     -
     -
     -
     -
     -
     -
   * - 57
     - GND
     - 电源
     -
     -
     -
     -
     -
     -