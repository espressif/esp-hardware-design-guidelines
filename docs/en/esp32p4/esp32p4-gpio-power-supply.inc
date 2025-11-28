.. list-table::
    :header-rows: 1
    :widths: 5 15 5 15 15 15 30
    :align: center

    * - Pin No.
      - Pin Name
      - Direction
      - Voltage (V)
      - Max. Current (mA)
      - IO Pin
      - Capacitors (μF)

    * - 9
      - VDD_LP
      - Input
      - 3.0 ~ 3.6
      - 100
      - LP IO
      - 0.1
    * - 21
      - VDD_IO_0
      - Input
      - 1.65 ~ 1.95/3.0 ~ 3.6
      - 100
      - HP IO
      - 0.1
    * - 62
      - VDD_IO_4
      - Input
      - 1.65 ~ 1.95/3.0 ~ 3.6
      - 100
      - HP IO
      - 0.1
    * - 85
      - VDD_IO_5 [#]_
      - Input
      - 1.65 ~ 1.95/3.0 ~ 3.6
      - 100
      - HP IO
      - 0.1
    * - 96
      - VDD_IO_6
      - Input
      - 1.65 ~ 1.95/3.0 ~ 3.6
      - 100
      - HP IO
      - 0.1

.. [#] If VDD_IO_5 is used as the IO power supply for SD 3.0 interface, please refer to :ref:`esp32p4-sdio` for the circuit reference.
