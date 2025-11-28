.. list-table:: 芯片启动模式控制
    :name: tab-chip-boot-mode-control
    :widths: 20 10 10 10 10
    :header-rows: 1

    * - 启动模式
      - GPIO35
      - GPIO36
      - GPIO37
      - GPIO38

    * - SPI Boot 模式（默认）
      - 1
      - 任意值
      - 任意值
      - 任意值

    * - Joint Download 模式 [#]_
      - 0
      - 1
      - 任意值
      - 任意值

.. [#] Joint Download 模式下支持以下下载模式：

       - USB Download Boot:

         * USB-Serial-JTAG Download Boot
         * USB 2.0 OTG Download Boot

       - UART Download Boot
       - SPI Slave Download Boot