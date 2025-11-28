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
    * - SPI Boot
      - 任意值
      - 1
    * - Joint Download Boot [#]_
      - 1
      - 0

.. [#] Joint Download Boot 支持下列几种下载方式：

    - USB-Serial-JTAG Download Boot
    - UART Download Boot