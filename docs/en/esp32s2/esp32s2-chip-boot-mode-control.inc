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
    * - SPI Boot
      - 1
      - Any value
    * - Download Boot
      - 0
      - 0
    * - Invalid combination [#]_
      - 0
      - 1

.. [#] This combination triggers unexpected behavior and should be avoided.
