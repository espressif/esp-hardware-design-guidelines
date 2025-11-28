注意图 :ref:`fig-chip-core-schematic` 显示的是四线、3.3 V、封装外 flash/PSRAM 的连接方式。

- PSRAM 的 SCLK 可以为任意空闲 GPIO（需要软件配置），建议优先配置为 GPIO17，或者和 flash 共用时钟线，即 SD_CLK。
- 当使用 ESP32-D0WDR2-V3（内封四线、3.3 V PSRAM）时，连接外部 flash 的方式如图 :ref:`fig-chip-core-schematic` 所示，GPIO16 需要添加上拉，上拉典型值为 10 kΩ。
- 当使用内置 ESP32-D0WDR2-V3 的模组时，因为 VDD_SDIO 没有拉出模组，GPIO16 的上拉需要连接至外部 3.3 V 电源，此时会有额外的功耗。如果对低功耗有要求，上拉电阻最大值是 1 MΩ。
- 当使用 ESP32-U4WDH（内封四线、3.3 V flash）时，内部连接 flash 的方式如图 :ref:`fig-esp32-u4wdh-core-schematic` 所示。
- 使用封装内 flash/PSRAM 时，无需上件 SPI 走线上的电阻，也无需关注 SPI 走线。
- R9 是否需要上件请按 `{IDF_TARGET_NAME} 系列芯片技术规格书 <{IDF_TARGET_DATASHEET_CN_URL}>`__ > 章节 *内置 LDO (VDD_SDIO) 电压控制* 选择。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/esp32-sche-u4wdh-core.png
    :name: fig-esp32-u4wdh-core-schematic
    :align: center
    :width: 90%
    :alt: {IDF_TARGET_NAME} 内封四线 3.3 V Flash 核心电路图

    {IDF_TARGET_NAME} 内封四线 3.3 V Flash 核心电路图