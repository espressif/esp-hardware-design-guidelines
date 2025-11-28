.. list-table:: Pin Mapping Between Chip and Off-Package Flash for {IDF_TARGET_NAME} [1]_
   :name: tab-chip-flash-pin-mapping
   :header-rows: 1
   :widths: 25 25 25 25 25
   :align: center

   * - Pin No
     - Pin Name
     - Single SPI flash
     - Dual SPI flash
     - Quad SPI flash
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

.. [1] An off-package flash can only be connected if the chip variant does not have in-package flash.
.. [2] SPICS0 is used to access flash
.. [3] SIO: Serial Data Input and Output


.. list-table:: Pin Mapping Between Chip and Off-Package PSRAM for {IDF_TARGET_NAME} [4]_
   :name: tab-chip-psram-pin-mapping
   :header-rows: 1
   :widths: 25 25 25 25
   :align: center

   * - Pin No
     - Pin Name
     - Single SPI PSRAM
     - Quad SPI PSRAM
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

.. [4] An off-package PSRAM can only be connected if the chip variant does not have in-package PSRAM. If PSRAM is not connected, these pins cannot be used as GPIO pins.
.. [5] SPICS1 is used to access PSRAM
.. [6] SI: Serial Data Input, equivalent to MOSI
.. [7] SO: Serial Data Output, equivalent to MISO
