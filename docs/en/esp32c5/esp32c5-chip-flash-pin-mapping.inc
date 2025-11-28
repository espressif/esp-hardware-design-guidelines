.. list-table:: Pin-to-Pin Mapping Between Chip and In-Package Flash
    :name: tab-chip-flash-pin-mapping
    :header-rows: 1
    :widths: 25 25 25 25
    :align: center

    * - Pin Name
      - Single SPI flash
      - Dual SPI flash
      - Quad SPI flash
    * - SPICLK
      - CLK
      - CLK
      - CLK
    * - SPICS0
      - CS#
      - CS#
      - CS#
    * - SPID
      - MOSI
      - SIO0
      - SIO0
    * - SPIQ
      - MISO
      - SIO1
      - SIO1
    * - SPIWP
      - WP#
      -
      - SIO2
    * - SPIHD
      - HOLD#
      -
      - SIO3

.. list-table:: Pin-to-Pin Mapping Between Chip and In-Package PSRAM
    :name: tab-chip-psram-quad-pin-mapping
    :header-rows: 1
    :widths: 30 30 30
    :align: center

    * - Pin Name
      - Single SPI PSRAM
      - Quad SPI PSRAM
    * - SPICLK
      - CLK
      - CLK
    * - SPICS1
      - CE#
      - CE#
    * - SPID
      - SI
      - SIO0
    * - SPIQ
      - SO
      - SIO1
    * - SPIWP
      -
      - SIO2
    * - SPIHD
      -
      - SIO3
