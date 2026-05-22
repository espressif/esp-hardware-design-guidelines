.. list-table:: Chip Boot Mode Control
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 50 25 25
    :align: center

    * - **Boot Mode**
      - **GPIO61**
      - **GPIO60**
    * - **SPI Boot (default)**
      - **1**
      - Any value
    * - Joint Download Boot
      - 0
      - 1

.. note::

  - **Bold** indicates default values and default configurations.
  - The Joint Download Boot mode supports the following download methods:

    - USB-Serial-JTAG Download Boot
    - USB-OTG Download Boot
    - UART Download Boot
    - GPSPI Download Boot


In addition to SPI Boot and Joint Download Boot modes, {IDF_TARGET_NAME} also supports SPI Download Boot mode.
