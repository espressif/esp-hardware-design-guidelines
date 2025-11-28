.. list-table:: Boot Mode Control
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 50 25 25
    :align: center

    * - Boot Mode
      - GPIO0
      - GPIO2
    * - Default Config
      - 1
      - 0
    * - SPI Boot
      - 1
      - Any value
    * - Joint Download Boot [#]_
      - 0
      - 0

.. [#] Joint Download Boot mode supports the following download methods:

    - UART Download Boot
    - SDIO Download Boot
