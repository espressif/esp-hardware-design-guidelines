.. _IO MUX Pin Functions:

.. list-table:: IO MUX Pin Functions
   :header-rows: 1
   :widths: 10 10 10 10 10 10 10 10 20

   * - Pin No
     - Pin Name
     - Pin Type
     - Pin Providing Power
     - At Reset
     - After Reset
     - Digital Function0
     - RTC
     - Analog
   * - 1
     - VDDA
     - Power
     -
     -
     -
     -
     -
     -
   * - 2
     - LNA_IN
     - Analog
     -
     -
     -
     -
     -
     -
   * - 3
     - VDD3P3
     - Power
     -
     -
     -
     -
     -
     -
   * - 4
     - VDD3P3
     - Power
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
     - Analog
   * - 7
     - GPIO2
     - IO
     - VDD3P3_RTC_IO
     - IE
     - IE
     - IO MUX
     - RTC
     - Analog
   * - 8
     - GPIO3
     - IO
     - VDD3P3_RTC_IO
     - IE
     -
     - IO MUX
     - RTC
     - Analog
   * - 9
     - GPIO4
     - IO
     - VDD3P3_RTC_IO
     - IE
     -
     - IO MUX
     - RTC
     - Analog
   * - 10
     - GPIO5
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - Analog
   * - 11
     - GPIO6
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - Analog
   * - 12
     - GPIO7
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - Analog
   * - 13
     - GPIO8
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - Analog
   * - 14
     - GPIO9
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - Analog
   * - 15
     - GPIO10
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - Analog
   * - 16
     - GPIO11
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - Analog
   * - 17
     - GPIO12
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - Analog
   * - 18
     - GPIO13
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - Analog
   * - 19
     - GPIO14
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - Analog
   * - 20
     - VDD3P3_RTC
     - Power
     -
     -
     -
     -
     -
     -
   * - 21
     - XTAL_32K_P
     - Analog
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - Analog
   * - 22
     - XTAL_32K_N
     - Analog
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - Analog
   * - 23
     - DAC_1
     - IO
     - VDD3P3_RTC_IO
     -
     - IE
     - IO MUX
     - RTC
     - Analog
   * - 24
     - DAC_2
     - IO
     - VDD3P3_RTC_IO
     -
     - IE, WPU
     - IO MUX
     - RTC
     - Analog
   * - 25
     - GPIO19
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - Analog
   * - 26
     - GPIO20
     - IO
     - VDD3P3_RTC_IO
     -
     -
     - IO MUX
     - RTC
     - Analog
   * - 27
     - VDD3P3_RTC_IO
     - Power
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
     - Power
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
     - Power
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
     - Power
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
     - Power
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
     - Analog
     -
     -
     -
     -
     -
     -
   * - 57
     - GND
     - Power
     -
     -
     -
     -
     -
     -