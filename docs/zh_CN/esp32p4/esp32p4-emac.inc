EMAC RMII 接口 GPIO 配置请见下表。

.. list-table:: EMAC 接口配置
   :header-rows: 1
   :widths: 5 10

   * - EMAC 信号
     - 管脚名称
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

建议在 RMII CLK 线上预留串联电阻用于调节。

请注意 RMII 接口中的时钟信号仅为输入，如果要使用时钟输出的方案，请使用 REF_50M_CLK_PAD 信号 (GPIO23/GPIO39)。