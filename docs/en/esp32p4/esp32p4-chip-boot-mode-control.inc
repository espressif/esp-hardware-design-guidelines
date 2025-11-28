.. list-table:: Chip Boot Mode Control
    :name: tab-chip-boot-mode-control
    :widths: 20 10 10 10 10
    :header-rows: 1

    * - Boot Mode
      - GPIO35
      - GPIO36
      - GPIO37
      - GPIO38

    * - SPI Boot Mode (Default)
      - 1
      - Any value
      - Any value
      - Any value

    * - Joint Download Mode [#]_
      - 0
      - 1
      - Any value
      - Any value

.. [#] The following download methods are supported under Joint Download Mode:

       - USB Download Boot:

         * USB-Serial-JTAG Download Boot
         * USB 2.0 OTG Download Boot

       - UART Download Boot
       - SPI Slave Download Boot