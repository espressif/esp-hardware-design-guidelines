.. list-table:: 芯片启动模式控制
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 40 20 20 20
    :align: center

    * - 启动模式
      - GPIO2 [#]_
      - GPIO8
      - GPIO9
    * - 默认配置
      - –（浮空）
      - –（浮空）
      - 1（上拉）
    * - SPI Boot (default)
      - 1
      - 任意值
      - 1
    * - Joint Download Boot [#]_
      - 1
      - 1
      - 0

.. [#] GPIO2 实际不控制 SPI Boot 和 Joint Download Boot 模式，但由于管脚毛刺强烈建议将此管脚上拉。
.. [#] Joint Download Boot 模式下支持以下下载方式：

        - USB-Serial-JTAG Download Boot
        - UART Download Boot
