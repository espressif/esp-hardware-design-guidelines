.. list-table:: 芯片与封装内 Quad SPI Flash 的管脚对应关系
    :name: tab-chip-flash-pin-mapping
    :header-rows: 1
    :widths: 50 50
    :align: center

    * - ESP32-S3FN8/ESP32-S3FH4R2
      - 封装内 Flash (Quad SPI)
    * - SPICLK
      - CLK
    * - SPICS0
      - CS#
    * - SPID
      - DI
    * - SPIQ
      - DO
    * - SPIWP
      - WP#
    * - SPIHD
      - HOLD#

.. list-table:: 芯片与封装内 Quad SPI PSRAM 的管脚对应关系
    :name: tab-chip-psram-quad-pin-mapping
    :header-rows: 1
    :widths: 50 50
    :align: center

    * - ESP32-S3R2/ESP32-S3FH4R2
      - 封装内 PSRAM (2 MB, Quad SPI)
    * - SPICLK
      - CLK
    * - SPICS1
      - CE#
    * - SPID
      - SI/SIO0
    * - SPIQ
      - SO/SIO1
    * - SPIWP
      - SIO2
    * - SPIHD
      - SIO3

.. list-table:: 芯片与封装内 Octal SPI PSRAM 的管脚对应关系
    :name: tab-chip-psram-octal-pin-mapping
    :header-rows: 1
    :widths: 50 50
    :align: center

    * - ESP32-S3R8/ESP32-S3R8V
      - 封装内 PSRAM (8 MB, Octal SPI)
    * - SPICLK
      - CLK
    * - SPICS1
      - CE#
    * - SPID
      - DQ0
    * - SPIQ
      - DQ1
    * - SPIWP
      - DQ2
    * - SPIHD
      - DQ3
    * - GPIO33
      - DQ4
    * - GPIO34
      - DQ5
    * - GPIO35
      - DQ6
    * - GPIO36
      - DQ7
    * - GPIO37
      - DQS/DM