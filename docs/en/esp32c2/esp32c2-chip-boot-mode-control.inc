.. list-table:: Boot Mode Control
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 50 25 25
    :align: center

    * - Boot Mode
      - GPIO8
      - GPIO9
    * - Default Config
      - – (Floating)
      - 1 (Pull-up)
    * - SPI Boot (default)
      - Any value
      - 1
    * - Joint Download Boot [#]_
      - 1
      - 0
    * - Invalid combination [#]_
      - 0
      - 0

.. [#] Joint Download Boot mode supports UART Download Boot download method. In addition to SPI Boot and Joint Download Boot modes, {IDF_TARGET_NAME} also supports SPI Download Boot mode. For details, please see `{IDF_TARGET_NAME} Technical Reference Manual <{IDF_TARGET_TRM_EN_URL}>`__ > Chapter *Chip Boot Control*.
.. [#] This combination triggers unexpected behavior and should be avoided.
