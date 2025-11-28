.. list-table:: Pin-to-Pin Mapping Between Chip and In-Package Quad SPI Flash
    :name: tab-chip-flash-pin-mapping
    :header-rows: 1
    :widths: 50 50
    :align: center

    * - ESP32-S3FN8/ESP32-S3FH4R2
      - In-Package Flash (Quad SPI)
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

.. list-table:: Pin-to-Pin Mapping Between Chip and In-Package Quad SPI PSRAM
    :name: tab-chip-psram-quad-pin-mapping
    :header-rows: 1
    :widths: 50 50
    :align: center

    * - ESP32-S3R2/ESP32-S3FH4R2
      - In-Package PSRAM (2 MB, Quad SPI)
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

.. list-table:: Pin-to-Pin Mapping Between Chip and In-Package Octal SPI PSRAM
    :name: tab-chip-psram-octal-pin-mapping
    :header-rows: 1
    :widths: 50 50
    :align: center

    * - ESP32-S3R8/ESP32-S3R8V
      - In-Package PSRAM (8 MB, Octal SPI)
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