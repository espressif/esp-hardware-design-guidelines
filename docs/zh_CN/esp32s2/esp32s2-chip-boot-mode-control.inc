.. list-table:: 芯片启动模式控制
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 50 25 25
    :align: center

    * - 启动模式
      - GPIO0
      - GPIO46
    * - 默认配置
      - 1（上拉）
      - 0（下拉）
    * - SPI Boot
      - 1
      - 任意值
    * - Download Boot
      - 0
      - 0
    * - 无效组合 [#]_
      - 0
      - 1

.. [#] 该组合会触发意外行为，应当避免。
