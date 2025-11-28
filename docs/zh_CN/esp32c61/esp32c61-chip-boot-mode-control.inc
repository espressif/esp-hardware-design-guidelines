.. list-table:: 芯片启动模式控制
    :name: tab-chip-boot-mode-control
    :header-rows: 1
    :widths: 40 20 20
    :align: center


    * - 启动模式
      - GPIO8
      - GPIO9
    * - SPI Boot（默认）
      - 任意值
      - 1
    * - Joint Download Boot
      - 1
      - 0


Joint Download Boot 模式下支持以下下载方式：

   - USB-Serial-JTAG Download Boot
   - UART Download Boot
   - SPI Slave 2.0 Download Boot
