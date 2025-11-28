.. list-table:: Boot Mode Control
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 40 20 20 20
    :align: center

    * - Boot Mode
      - GPIO2 [#]_
      - GPIO8
      - GPIO9
    * - Default Config
      - – (Floating)
      - – (Floating)
      - 1 (Pull-up)
    * - SPI Boot (default)
      - 1
      - Any value
      - 1
    * - Joint Download Boot [#]_
      - 1
      - 1
      - 0

.. [#] GPIO2 actually does not determine SPI Boot and Joint Download Boot mode, but it is recommended to pull this pin up due to glitches.
.. [#] Joint Download Boot mode supports the following download methods:

        - USB-Serial-JTAG Download Boot
        - UART Download Boot
