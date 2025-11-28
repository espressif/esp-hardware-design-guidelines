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
    * - SPI Boot（默认）
      - 1
      - 任意值
    * - Joint Download Boot \ :sup:`1`
      - 0
      - 0

\ :sup:`1` Joint Download Boot 模式支持下列几种下载方式：

    - USB Download Boot:

        - USB-Serial-JTAG Download Boot
        - USB-OTG Download Boot

    - UART Download Boot

\ :sup:`2` 除了 SPI Boot 和 Joint Download Boot 模式，{IDF_TARGET_NAME} 还支持 SPI Download Boot 模式，详见 `{IDF_TARGET_NAME} 技术参考手册 <{IDF_TARGET_TRM_CN_URL}>`__ > 章节 *芯片 Boot 控制*。