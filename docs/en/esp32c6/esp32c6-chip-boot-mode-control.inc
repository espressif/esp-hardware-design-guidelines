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
    * - Download Boot
      - 1
      - 0
    * - Invalid combination [#]_
      - 0
      - 0

.. [#] This combination triggers unexpected behavior and should be avoided.