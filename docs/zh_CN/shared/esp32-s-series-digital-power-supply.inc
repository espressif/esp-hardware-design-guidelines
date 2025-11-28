{IDF_TARGET_DIG_POWER_PIN:default="管脚 17 VDD3P3_CPU", esp32="管脚 37 VDD3P3_CPU", esp32s2="管脚 27 VDD3P3_RTC_IO 和管脚 45 VDD3P3_CPU", esp32s3="管脚 46 VDD3P3_CPU", esp32c6="管脚 5 VDDPST1 和管脚 28 VDDPST2", esp32h2="管脚 9 VDDPST1 和管脚 20 VDDPST2", esp32c5="VDDPST1（管脚 8）、VDDPST2（管脚 24）和 VDDPST3（管脚 39）"}

{IDF_TARGET_DIG_POWER_RTC_PIN:default="待定", esp32s3="管脚 20 VDD3P3_RTC", esp32="管脚 20 VDD3P3_RTC"}

{IDF_TARGET_DIG_POWER_PIN_VOL:default="3.0 V ~ 3.6 V", esp32="1.8 V ~ 3.6 V", esp32s2="3.0 V ~ 3.6 V 和 2.8 V ~ 3.6 V"}

{IDF_TARGET_VDD_POWER:default="VDD_SPI", esp32="VDD_SDIO"}

{IDF_TARGET_RSPI_VALUE:default="待定", esp32="6", esp32s2="5", esp32s3="14"}

{IDF_TARGET_VDD_STRAPPING_PIN:default="待定", esp32="MTDI", esp32s3="GPIO45"}

{IDF_TARGET_EFUSE_POWER_CTRL:default="待定", esp32="EFUSE_SDIO_FORCE", esp32s3="EFUSE_VDD_SPI_FORCE"}

{IDF_TARGET_EFUSE_TIEH:default="待定", esp32="EFUSE_SDIO_TIEH", esp32s3="EFUSE_VDD_SPI_TIEH"}

.. only:: esp32s3

  {IDF_TARGET_NAME} 的{IDF_TARGET_DIG_POWER_PIN} 为数字电源管脚，{IDF_TARGET_DIG_POWER_RTC_PIN} 为 RTC 及部分数字电源管脚，工作电压范围为 {IDF_TARGET_DIG_POWER_PIN_VOL}。建议在电路中靠近数字电源管脚处添加 0.1 μF 电容。

.. only:: esp32

  {IDF_TARGET_NAME} 的{IDF_TARGET_DIG_POWER_PIN} 为数字电源管脚，工作电压范围为 {IDF_TARGET_DIG_POWER_PIN_VOL}。{IDF_TARGET_DIG_POWER_RTC_PIN} 为 RTC 及部分数字电源管脚，工作电压范围为 2.3 V ~ 3.6 V。建议在电路中靠近数字电源管脚处添加 0.1 μF 电容。

.. only:: esp32s2 or esp32s3

  管脚 {IDF_TARGET_VDD_POWER} 可配置输出 1.8 V 或 3.3 V（默认）给外部电路使用。建议靠近该电源管脚处添加 0.1 μF 及 1 μF 去耦电容，请不要添加过大的电容。

  - 当 {IDF_TARGET_VDD_POWER} 处于 1.8 V 模式时，由 {IDF_TARGET_NAME} 内部的 LDO 供电，能提供的典型电流值为 40 mA。
  - 当 {IDF_TARGET_VDD_POWER} 处于 3.3 V 模式时，由 VDD3P3_RTC 通过芯片内部的约 {IDF_TARGET_RSPI_VALUE} Ω 电阻后供电。因此 {IDF_TARGET_VDD_POWER} 相对 VDD3P3_RTC 会有一定电压降。

.. only:: esp32

  管脚 {IDF_TARGET_VDD_POWER} 可配置输出 1.8 V 或 3.3 V（默认）给外部电路使用。

  - 当 {IDF_TARGET_VDD_POWER} 处于 1.8 V 模式时，由 {IDF_TARGET_NAME} 内部的 LDO 供电，能提供的最大电流为 40 mA，输出电压范围为 1.65 V ~ 2.0 V。建议在 {IDF_TARGET_VDD_POWER} 管脚处添加 2 kΩ 对地电阻及 4.7 μF 对地电容。

  - 当 {IDF_TARGET_VDD_POWER} 处于 3.3 V 模式时，由 VDD3P3_RTC 通过芯片内部的约 {IDF_TARGET_RSPI_VALUE} Ω 电阻后供电。因此 {IDF_TARGET_VDD_POWER} 相对 VDD3P3_RTC 会有一定电压降。建议在 {IDF_TARGET_VDD_POWER} 靠近管脚处添加 1 μF 滤波电容。

.. attention::

   - 当使用 {IDF_TARGET_VDD_POWER} 给封装内或封装外的 3.3 V flash/PSRAM 供电时，考虑到上文提到的电压降，为了满足 flash/PSRAM 的工作电压要求，请保证 VDD3P3_RTC 在 3.0 V 以上。

   - 请注意 VDD3P3_RTC 不能单独供电工作，所有电源必须全部上电。

.. only:: esp32s3 or esp32

   {IDF_TARGET_VDD_POWER} 电压有两种控制方式，具体取决于 {IDF_TARGET_EFUSE_POWER_CTRL} 的值，如表 :ref:`tab-vdd-spi-voltage-control` 所示。

   .. list-table:: {IDF_TARGET_VDD_POWER} 电压控制
    :name: tab-vdd-spi-voltage-control
    :header-rows: 1
    :widths: 10 10 10 20 50
    :align: center

    * - {IDF_TARGET_EFUSE_POWER_CTRL}
      - {IDF_TARGET_VDD_STRAPPING_PIN}
      - {IDF_TARGET_EFUSE_TIEH}
      - 电压
      - {IDF_TARGET_VDD_POWER} 电源
    * - 0
      - 0
      - 忽略
      - 3.3 V
      - VDD3P3_RTC 通过 R\ :sub:`SPI` 供电（默认）
    * - 0
      - 1
      - 忽略
      - 1.8 V
      - Flash Voltage 稳压器
    * - 1
      - 忽略
      - 0
      - 1.8 V
      - Flash Voltage 稳压器
    * - 1
      - 忽略
      - 1
      - 3.3 V
      - VDD3P3_RTC 通过 R\ :sub:`SPI` 供电

{IDF_TARGET_VDD_POWER} 也可以连接到外部电源，由外部电源输入供电。

推荐使用 {IDF_TARGET_VDD_POWER} 输出电源给封装外或封装内 flash/PSRAM 供电。






