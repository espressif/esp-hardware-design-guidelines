注意图 :ref:`fig-chip-core-schematic` 显示的是四线、3.3 V、封装外 flash/PSRAM 的连接方式。

- 当使用八线、1.8 V 或 3.3 V、封装内或封装外 flash/PSRAM 时，GPIO33 ~ GPIO37 会被额外占用，不建议用于其他功能。
- 当使用封装内 SPI flash/PSRAM，并且已经通过 VDD_SPI_FORCE eFuse 将 VDD_SPI 配置为 1.8 V 或 3.3 V 时，GPIO45 不再影响 VDD_SPI 电压。这种情况下，R1 可以选择性上件。其他情况下，按 `{IDF_TARGET_NAME} 系列芯片技术规格书 <{IDF_TARGET_DATASHEET_CN_URL}#cd-pins-strap-vdd-spi>`__ > 章节 *VDD\_SPI 电压控制* > 表格 *VDD_SPI 电压控制* 选择 R1 是否上件。
- 八线、1.8 V、封装外 flash/PSRAM 的连接方式如图 :ref:`fig-esp32-s3-core-sch-external-1v8-spi8` 所示。
- 使用封装内 flash/PSRAM 时，无需上件 SPI 走线上的电阻，也无需关注 SPI 走线。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/esp32s3-sche-ext-1v8-spi8.png
    :name: fig-esp32-s3-core-sch-external-1v8-spi8
    :align: center
    :width: 90%
    :alt: {IDF_TARGET_NAME} 封装外八线 1.8 V Flash/PSRAM 核心电路图

    {IDF_TARGET_NAME} 封装外八线 1.8 V Flash/PSRAM 核心电路图