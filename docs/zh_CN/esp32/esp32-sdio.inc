{IDF_TARGET_NAME} 系列芯片集成了一个 SD/SDIO/MMC 主机控制器和一个 SD/SPI 从机控制器，符合工业标准 SDIO 2.0 规格。对于 SDIO 主机/从机控制器，{IDF_TARGET_NAME} 共有两组 slot 的 GPIO 可供使用，由于 slot0 中的 GPIO 默认连接了 flash，请按照下表 :ref:`tab-sdio` 中 slot1 的方式连接 GPIO 和信号线。

.. list-table:: SDIO 管脚分配
    :name: tab-sdio
    :header-rows: 1
    :widths: 10 10 10 10 10 10 10 30
    :align: center

    * -
      - CMD
      - CLK
      - DAT0
      - DAT1
      - DAT2
      - DAT3
      - Note
    * - Slot0
      - GPIO11
      - GPIO6
      - GPIO7
      - GPIO8
      - GPIO9
      - GPIO10
      - 默认连接 flash，不建议用作它用。
    * - Slot1
      - GPIO15
      - GPIO14
      - GPIO2
      - GPIO4
      - GPIO12
      - GPIO13
      - 和 JTAG、Touch 、EMAC、strapping 功能复用，使用时请注意。

按照 slot1 的方式连接时还需注意：

  - 当 {IDF_TARGET_NAME} 作为 SDIO 主机工作时，请在使用的管脚上添加上拉，未使用的管脚可以用作它用。
  - 当 {IDF_TARGET_NAME} 作为 SDIO 从机工作时，请在所有管脚上都添加上拉，无论这些管脚使用或未使用；未使用的管脚不可以用作它用。
  - 因为 SDIO GPIO 中有 strapping 管脚，SDIO 的上拉会导致一些冲突，具体的解决方法请参阅 `SD 上拉需求 <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/sd_pullup_requirements.html#sd-pull-up-requirements>`_。

更多关于 SDIO 的配置，请参阅 `API 参考 <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/api-reference/index.html>`_。