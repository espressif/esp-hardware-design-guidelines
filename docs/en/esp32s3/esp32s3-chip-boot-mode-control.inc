.. list-table:: Boot Mode Control
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 50 25 25
    :align: center

    * - Boot Mode
      - GPIO0
      - GPIO46
    * - Default Config
      - 1 (Pull-up)
      - 0 (Pull-down)
    * - SPI Boot (default)
      - 1
      - Any value
    * - Joint Download Boot \ :sup:`1`
      - 0
      - 0

\ :sup:`1` Joint Download Boot mode supports the following download methods:

    - USB Download Boot:

        - USB-Serial-JTAG Download Boot
        - USB-OTG Download Boot

    - UART Download Boot

\ :sup:`2` In addition to SPI Boot and Joint Download Boot modes, {IDF_TARGET_NAME} also supports SPI Download Boot mode. For details, please see `{IDF_TARGET_NAME} Technical Reference Manual <{IDF_TARGET_TRM_EN_URL}>`__ > Chapter *Chip Boot Control*.