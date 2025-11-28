{IDF_TARGET_VDD_POWER:default="VDD_SPI", esp32="VDD_SDIO"}

{IDF_TARGET_VDD_POWER_PIN:default=" ", esp32c5="（管脚 29）", esp32c61="（管脚 23）", esp32c6="（管脚 23）"}

{IDF_TARGET_VDD_POWER_SOURCE:default="待定", esp32c3="VDD3P3_CPU", esp32c6="VDDPST2", esp32c5="VDDPST2", esp32c61="VDDPST2"}

{IDF_TARGET_VDD_POWER_CAP:default="待定", esp32c3="一个 1 μF 电容", esp32c6="0.1 μF 和 1 μF 电容", esp32c5="一个 1 μF 电容", esp32c61="一个 1 μF 电容"}

{IDF_TARGET_RSPI_VALUE:default="待定", esp32="6", esp32s2="5", esp32s3="14"}

{IDF_TARGET_PSRAM: default="待定", esp32c6="",esp32c5="/PSRAM", esp32c61="/PSRAM"}

管脚 {IDF_TARGET_VDD_POWER}{IDF_TARGET_VDD_POWER_PIN}作为输出电源时，由 {IDF_TARGET_VDD_POWER_SOURCE} 通过 R\ :sub:`SPI` 电阻后供电，电压典型值为 3.3 V。因此，{IDF_TARGET_VDD_POWER} 相对 {IDF_TARGET_VDD_POWER_SOURCE} 会有一定电压降。建议在靠近 {IDF_TARGET_VDD_POWER} 管脚处添加 {IDF_TARGET_VDD_POWER_CAP}。

{IDF_TARGET_VDD_POWER} 也可以连接到外部电源，由外部电源输入供电。

当 {IDF_TARGET_VDD_POWER} 无需为外部供电时，亦可作为 GPIO 使用。

.. only:: esp32c5 or esp32c61 or esp32c6

    推荐使用 {IDF_TARGET_VDD_POWER} 输出电源给封装外或封装内 flash{IDF_TARGET_PSRAM} 供电。

.. only:: esp32c5 or esp32c61 or esp32c6

    .. attention::

        当使用 {IDF_TARGET_VDD_POWER} 给封装内或封装外的 3.3 V flash{IDF_TARGET_PSRAM} 供电时，考虑到上面提到的电压降，为了满足 flash{IDF_TARGET_PSRAM} 的工作电压要求，请保证 {IDF_TARGET_VDD_POWER_SOURCE} 在 3.0 V 以上。

.. only:: not esp32c5 and not esp32c61 and not esp32c6

    .. attention::

        当使用 {IDF_TARGET_VDD_POWER} 给封装内或封装外的 3.3 V flash 供电时，需要满足 flash 的工作电压要求，一般应保证电压在 3.0 V 以上。此时，{IDF_TARGET_VDD_POWER} 不能用作 GPIO。
