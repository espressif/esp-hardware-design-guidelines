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
    * - SPI Boot
      - Any value
      - 1
    * - Joint Download Boot [#]_
      - 1
      - 0

.. [#] Joint Download Boot mode supports the following download methods:

    - USB-Serial-JTAG Download Boot
    - UART Download Boot