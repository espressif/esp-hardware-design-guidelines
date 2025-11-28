.. list-table:: 芯片与封装内 flash 的管脚对应关系
    :name: tab-chip-flash-pin-mapping
    :header-rows: 1
    :widths: 25 25 25 25
    :align: center

    * - 管脚名称
      - 单线 SPI flash
      - 双线 SPI flash
      - 四线 SPI flash
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

.. list-table:: 芯片与封装内 PSRAM 的管脚对应关系
    :name: tab-chip-psram-quad-pin-mapping
    :header-rows: 1
    :widths: 30 30 30
    :align: center

    * - 管脚名称
      - 单线 SPI PSRAM
      - 四线 SPI PSRAM
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
