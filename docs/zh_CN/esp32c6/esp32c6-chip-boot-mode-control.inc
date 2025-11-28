.. list-table:: 芯片启动模式控制
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 50 25 25
    :align: center

    * - 启动模式
      - GPIO8
      - GPIO9
    * - 默认配置
      - –（浮空）
      - 1（上拉）
    * - SPI Boot（默认）
      - 任意值
      - 1
    * - Download Boot
      - 1
      - 0
    * - 无效组合 [#]_
      - 0
      - 0

.. [#] 该组合会触发意外行为，应当避免。