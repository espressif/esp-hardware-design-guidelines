.. list-table:: 芯片启动模式控制
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 50 25 25
    :align: center

    * - **启动模式**
      - **GPIO61**
      - **GPIO60**
    * - **SPI Boot（默认）**
      - **1**
      - 任意值
    * - Joint Download Boot
      - 0
      - 1

.. note::

  - **加粗** 表示默认值和默认配置。
  - Joint Download Boot 模式下支持以下下载方式：

    - USB-Serial-JTAG Download Boot
    - USB-OTG Download Boot
    - UART Download Boot
    - GPSPI Download Boot


除了 SPI Boot 和 Joint Download Boot 模式，{IDF_TARGET_NAME} 还支持 SPI Download Boot 模式。