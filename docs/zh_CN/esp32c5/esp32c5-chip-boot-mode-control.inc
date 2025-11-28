.. list-table:: 芯片启动模式控制
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 40 20 20 20
    :align: center

    * - 启动模式
      - GPIO26
      - GPIO27
      - GPIO28
    * - 默认配置
      - –（浮空）
      - 1（上拉）
      - 1（上拉）
    * - SPI Boot（默认）
      - 任意值
      - 任意值
      - 1
    * - Joint Download Boot 0 [#]_
      - 任意值
      - 1
      - 0
    * - Joint Download Boot 1 [#]_
      - 0
      - 0
      - 0

.. [#] Joint Download Boot 0 模式下支持以下下载方式：

    - USB-Serial-JTAG Download Boot
    - UART Download Boot
    - SPI Slave Download Boot（仅限芯片版本 v0.1）

.. [#] Joint Download Boot 1 模式下支持以下下载方式：

    - UART Download Boot
    - SDIO Download Boot
