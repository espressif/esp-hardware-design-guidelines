.. list-table:: 芯片启动模式控制
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 50 25 25
    :align: center

    * - 启动模式
      - GPIO0
      - GPIO2
    * - 默认配置
      - 1
      - 0
    * - SPI Boot
      - 1
      - 任意值
    * - Joint Download Boot [#]_
      - 0
      - 0

.. [#] Joint Download Boot 支持下列几种下载方式：

    - UART Download Boot
    - SDIO Download Boot
