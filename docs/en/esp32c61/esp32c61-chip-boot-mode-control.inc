.. list-table:: Boot Mode Control
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 40 20 20
    :align: center


    * - Boot Mode
      - GPIO8
      - GPIO9
    * - SPI Boot (default)
      - Any value
      - 1
    * - Joint Download Boot
      - 1
      - 0


Joint Download Boot supports the following download methods:

   - USB-Serial-JTAG Download Boot
   - UART Download Boot
   - SPI Slave 2.0 Download Boot
