Refer to the table below for the GPIO configuration of the EMAC RMII interface.

.. list-table:: EMAC Interface Configuration
   :header-rows: 1
   :widths: 5 10

   * - Signal
     - Pin Name
   * - RMII\_RXDV
     - GPIO28, GPIO45, GPIO51
   * - RMII\_RXD0
     - GPIO29, GPIO46, GPIO52
   * - RMII\_RXD1
     - GPIO30, GPIO47, GPIO53
   * - RMII\_RXER
     - GPIO31, GPIO48, GPIO54
   * - RMII\_CLK
     - GPIO32, GPIO44, GPIO50
   * - RMII\_TXEN
     - GPIO33, GPIO40, GPIO49
   * - RMII\_TXD0
     - GPIO34, GPIO41
   * - RMII\_TXD1
     - GPIO35, GPIO42
   * - RMII\_TXER
     - GPIO36, GPIO43

It is recommended to populate a series resistor on the RMII CLK line.

Please note that the clock signal in the RMII interface is input-only. If you need a clock output  solution, please use the REF_50M_CLK_PAD signal (GPIO23/GPIO39).