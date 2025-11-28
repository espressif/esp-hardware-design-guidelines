.. list-table:: Boot Mode Control
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 40 20 20 20
    :align: center

    * - Boot Mode
      - GPIO26
      - GPIO27
      - GPIO28
    * - Default Config
      - – (Floating)
      - 1 (Pull-up)
      - 1 (Pull-up)
    * - SPI Boot (default)
      - Any value
      - Any value
      - 1
    * - Joint Download Boot 0 [#]_
      - Any value
      - 1
      - 0
    * - Joint Download Boot 1 [#]_
      - 0
      - 0
      - 0

.. [#] Joint Download Boot 0 mode supports the following download methods:

    - USB-Serial-JTAG Download Boot
    - UART Download Boot
    - SPI Slave Download Boot (chip revision v0.1 only)

.. [#] Joint Download Boot 1 mode supports the following download methods:

    - UART Download Boot
    - SDIO Download Boot
