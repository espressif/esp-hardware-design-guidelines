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
    * - SPI Boot (default)
      - 任意值
      - 1
    * - Joint Download Boot [#]_
      - 1
      - 0
    * - 无效组合 [#]_
      - 0
      - 0

.. [#] Joint Download Boot 模式下支持 UART Download Boot 下载方式。除了 SPI Boot 和 Joint Download Boot 模式，{IDF_TARGET_NAME} 还支持 SPI Download Boot 模式，详见 `{IDF_TARGET_NAME} 技术参考手册 <{IDF_TARGET_TRM_CN_URL}>`__ > 章节 *芯片 Boot 控制*。
.. [#] 该组合会触发意外行为，应当避免。
