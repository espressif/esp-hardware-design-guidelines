.. list-table:: {IDF_TARGET_NAME} 芯片与封装外 flash 的管脚对应关系 [1]_
   :name: tab-chip-flash-pin-mapping
   :header-rows: 1
   :widths: 25 25 25 25 25
   :align: center

   * - 管脚序号
     - 管脚名称
     - 单线 SPI Flash
     - 双线 SPI Flash
     - 四线 SPI Flash
   * - 26
     - SPICLK
     - CLK
     - CLK
     - CLK
   * - 20
     - SPICS0 [2]_
     - CS#
     - CS#
     - CS#
   * - 27
     - SPID
     - MOSI
     - SIO0 [3]_
     - SIO0
   * - 22
     - SPIQ
     - MISO
     - SIO1
     - SIO1
   * - 23
     - SPIWP
     - WP#
     -
     - SIO2
   * - 25
     - SPIHD
     - HOLD#
     -
     - SIO3

.. [1] 仅当芯片内部未封装 flash 时，才可外接 flash
.. [2] SPICS0 用于访问 flash
.. [3] SIO：串行输入输出 (Serial Data Input and Output)


.. list-table:: {IDF_TARGET_NAME} 芯片与封装外 PSRAM 的管脚对应关系 [4]_
   :name: tab-chip-psram-pin-mapping
   :header-rows: 1
   :widths: 25 25 25 25
   :align: center

   * - 管脚序号
     - 管脚名称
     - 单线 SPI PSRAM
     - 四线 SPI PSRAM
   * - 26
     - SPICLK
     - CLK
     - CLK
   * - 19
     - SPICS1 [5]_
     - CE#
     - CE#
   * - 27
     - SPID
     - SI [6]_
     - SIO0
   * - 22
     - SPIQ
     - SO [7]_
     - SIO1
   * - 23
     - SPIWP
     -
     - SIO2
   * - 25
     - SPIHD
     -
     - SIO3

.. [4] 仅当芯片内部未封装 PSRAM 时，才可以外接 PSRAM，如果不外接 PSRAM，这些管脚不可以用作 GPIO 管脚
.. [5] SPICS1 用于访问 PSRAM
.. [6] SI：串行输入 (Serial Data Input)，功能等同 MOSI
.. [7] SO：串行输出 (Serial Data Output)，功能等同 MISO

