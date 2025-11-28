原理图设计
============
:link_to_translation:`en:[English]`

.. _schematic-checklist-overview:

概述
----

{IDF_TARGET_ELEC_COMP_NUM: default="20", esp32h2="17", esp32c2="15", esp32c5="30", esp32c61="30"}

{IDF_TARGET_ELEC_COMP:default="，以及 1 个 SPI flash", esp32c6="，以及 1 个 SPI flash（QFN32 型号不需要）", esp32h2="", esp32c2="", esp32c61="，以及 1 个 SPI flash（封装内或封装外）"}

{IDF_TARGET_NAME} 系列芯片的核心电路只需要 {IDF_TARGET_ELEC_COMP_NUM} 个左右的电阻电容电感和 1 个无源晶振{IDF_TARGET_ELEC_COMP}。为了能够更好地保证 {IDF_TARGET_NAME} 系列芯片的工作性能，本章将详细介绍 {IDF_TARGET_NAME} 系列芯片的原理图设计。

下图所示为 {IDF_TARGET_NAME} 的核心电路参考设计，您可以将它作为您的原理图设计的基础。

.. only:: not esp32c6

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-core.png
        :name: fig-chip-core-schematic
        :align: center
        :width: 95%
        :alt: {IDF_TARGET_NAME} 系列芯片参考设计原理图

        {IDF_TARGET_NAME} 系列芯片参考设计原理图

.. only:: esp32c6

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-core-qfn40.png
        :name: fig-chip-core-schematic
        :align: center
        :width: 95%
        :alt: {IDF_TARGET_NAME} 系列芯片参考设计原理图 (QFN40)

        {IDF_TARGET_NAME} 系列芯片参考设计原理图 (QFN40)

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-core-qfn32.png
        :name: fig-chip-core-schematic-qfn32
        :align: center
        :width: 95%
        :alt: {IDF_TARGET_NAME} 系列芯片参考设计原理图 (QFN32)

        {IDF_TARGET_NAME} 系列芯片参考设计原理图 (QFN32)

.. only:: esp32 or esp32s3 or esp32c6 or esp32c2

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-chip-core-schem-note.inc

{IDF_TARGET_NAME} 系列芯片的核心电路图的设计有以下重要组成部分：

.. list::

    - `电源`_
    - `上电时序与复位`_
    :esp32h2 or esp32c3 or esp32c6 or esp32c2: - `Flash`_
    :esp32 or esp32s2 or esp32s3 or esp32c5 or esp32c61: - `Flash 及 PSRAM`_
    - `时钟源`_
    - `射频`_
    - `UART`_
    - `Strapping 管脚`_
    - `GPIO`_
    - `ADC`_
    :esp32: - `外置阻容`_
    :esp32c61: - `SPI`_
    :esp32 or esp32s3 or esp32c6 or esp32c5 or esp32c61: - `SDIO`_
    :esp32h2 or esp32s2 or esp32s3 or esp32c6 or esp32c3 or esp32c5 or esp32c61: - `USB`_
    :esp32 or esp32s2 or esp32s3: - `触摸传感器`_

下文将分别对这些部分进行描述。

.. _schematic-checklist-power-supply:

电源
--------

{IDF_TARGET_OUTPUT_CUR:default="500 mA", esp32h2="350 mA", esp32c5="600 mA"}

电源电路设计的通用要点有：

- 使用单电源供电时，建议供给 {IDF_TARGET_NAME} 的电源电压为 3.3 V，最大输出电流至少 {IDF_TARGET_OUTPUT_CUR}。
- 建议在总电源入口处添加 ESD 保护器件和至少 10 μF 的大电容。

.. only:: not esp32c5 and not esp32s3 and not esp32 and not esp32c61 and not esp32c6

    电源管理如 `{IDF_TARGET_NAME} 系列芯片技术规格书 <{IDF_TARGET_DATASHEET_CN_URL}#cd-pwr-scheme>`__ > 图 *{IDF_TARGET_NAME} 电源管理* 所示。

.. only:: esp32c5 or esp32s3 or esp32 or esp32c6

    电源管理如图 :ref:`fig-chip-power-scheme` 所示。

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-chip-power.png
       :name: fig-chip-power-scheme
       :align: center
       :width: 100%
       :alt: {IDF_TARGET_NAME} 系列芯片电源管理图

       {IDF_TARGET_NAME} 系列芯片电源管理图

有关电源管脚的更多信息，请查看 `{IDF_TARGET_NAME} 系列芯片技术规格书 <{IDF_TARGET_DATASHEET_CN_URL}#cd-pwr-supply>`__ > 章节 *电源*。

.. _digital-power-supply:

数字电源
^^^^^^^^^^^^^^^^^^^^^^^^

{IDF_TARGET_DIG_POWER_PIN:default="管脚 17 VDD3P3_CPU", esp32="管脚 37 VDD3P3_CPU", esp32s2="管脚 27 VDD3P3_RTC_IO 和管脚 45 VDD3P3_CPU", esp32s3="管脚 46 VDD3P3_CPU", esp32c6="管脚 5 VDDPST1 和管脚 28 VDDPST2", esp32h2="管脚 9 VDDPST1 和管脚 20 VDDPST2", esp32c5="VDDPST1（管脚 8）、VDDPST2（管脚 24）和 VDDPST3（管脚 39）", esp32c61="管脚 5 VDDPST1 和管脚 30 VDDPST2"}

{IDF_TARGET_DIG_POWER_RTC_PIN:default="待定", esp32s3="管脚 20 VDD3P3_RTC", esp32="管脚 20 VDD3P3_RTC"}

{IDF_TARGET_DIG_POWER_PIN_VOL:default="3.0 V ~ 3.6 V", esp32="1.8 V ~ 3.6 V", esp32s2="3.0 V ~ 3.6 V 和 2.8 V ~ 3.6 V"}

{IDF_TARGET_VDD_POWER:default="VDD_SPI", esp32="VDD_SDIO"}

{IDF_TARGET_VDD_POWER_SOURCE:default="待定", esp32c3="VDD3P3_CPU", esp32c6="VDDPST2"}

{IDF_TARGET_VDD_POWER_CAP:default="待定", esp32c3="一个 1 μF 电容", esp32c6="0.1 μF 和 1 μF 电容"}

{IDF_TARGET_RSPI_VALUE:default="待定", esp32="6", esp32s2="5", esp32s3="14"}

.. only:: not esp32c5 and not esp32s3 and not esp32

    {IDF_TARGET_NAME} 的{IDF_TARGET_DIG_POWER_PIN} 为数字电源管脚，工作电压范围为 {IDF_TARGET_DIG_POWER_PIN_VOL}。建议在电路中靠近数字电源管脚处添加 0.1 μF 电容。

.. only:: esp32c5

    {IDF_TARGET_NAME} 的 {IDF_TARGET_DIG_POWER_PIN} 为数字电源管脚，工作电压范围为 {IDF_TARGET_DIG_POWER_PIN_VOL}。建议在电路中靠近 VDDPST1 电源管脚处添加 1 μF 电容，靠近 VDDPST2 和 VDDPST3 电源管脚处添加 0.1 μF 电容。

.. only:: esp32s2 or esp32s3 or esp32

    .. include:: shared/esp32-s-series-digital-power-supply.inc

.. only:: esp32c3 or esp32c6 or esp32c5 or esp32c61

    .. include:: shared/esp32-c-series-digital-power-supply.inc


模拟电源
^^^^^^^^^^^

{IDF_TARGET_ANA_POWER_PIN:default="待定", esp32="VDDA（管脚 1、43、46）、VDD3P3（管脚 3、4）", esp32s3="VDD3P3（管脚 2、3 ）和 VDDA（管脚 55、56）", esp32c3="VDDA 和 VDD3P3 管脚", esp32s2="VDDA、VDD3P3 和 VDD3P3_RTC 管脚", esp32c6="VDDA 和 VDDA3P3 管脚", esp32h2="VDD3P3、VBAT 和 VDDA_PMU 管脚", esp32c2="VDDA 和 VDDA3P3 管脚", esp32c5="VDDA1 至 VDDA8 管脚", esp32c61="VDDA1 至 VDDA4 管脚"}

{IDF_TARGET_ANA_POWER_PIN_VOL:default="3.0 V ~ 3.6 V", esp32="2.3 V ~ 3.6 V", esp32s2="2.8 V ~ 3.6 V"}

{IDF_TARGET_ANA_POWER_PIN_COLLAPSE:default="VDD3P3", esp32c6="VDDA3P3", esp32h2="管脚 1 和 管脚 2 的 VDD3P3", esp32c2="VDDA3P3", esp32c5="VDDA1、VDDA2、VDDA6 和 VDDA7", esp32c61="VDDA3 和 VDDA4"}

{IDF_TARGET_ANA_POWER_PIN_CAP:default="1 μF", esp32h2="1 μF 和 0.1 μF", esp32c2="0.1 μF", esp32s2="0.1 μF", esp32c3="0.1 μF"}

{IDF_TARGET_CAP_POWER_RAILS_PIN:default="待定", esp32c5="VDDA1/2、VDDA6/7", esp32c61="VDDA3 和 VDDA4"}

{IDF_TARGET_LC_POWER_RAILS_PIN:default="待定", esp32c5="VDDA1 和 VDDA2", esp32c61="VDDA3 和 VDDA4"}

{IDF_TARGET_ADDITIONAL_NOTE_FOR_LC_POWER_RAILS_PIN:default="", esp32c5="在靠近 VDDA6 和 VDDA7 处添加两个电容，"}

{IDF_TARGET_NAME} 的 {IDF_TARGET_ANA_POWER_PIN} 为模拟电源管脚，工作电压范围为 {IDF_TARGET_ANA_POWER_PIN_VOL}。

对于 {IDF_TARGET_ANA_POWER_PIN_COLLAPSE}，当 {IDF_TARGET_NAME} 工作在 TX 时，瞬间电流会加大，往往引起电源的轨道塌陷。所以在电路设计时建议在 {IDF_TARGET_ANA_POWER_PIN_COLLAPSE} 的电源走线上增加一个 10 μF 电容，该电容可与 {IDF_TARGET_ANA_POWER_PIN_CAP} 电容或其他电容搭配使用。

建议在总电源入口添加另一个 10 μF 电容。如果总电源入口靠近 {IDF_TARGET_ANA_POWER_PIN_COLLAPSE}，可以合并仅使用一个 10 μF 电容。

.. only:: esp32c5 or esp32c61

    另外，在靠近 {IDF_TARGET_LC_POWER_RAILS_PIN} 处还需添加 LC 滤波电路，用于抑制高频谐波，同时请注意该电感的额定电流最好在 500 mA 及以上。

.. only:: not esp32h2 and not esp32c5 and not esp32c61

    另外，在靠近 {IDF_TARGET_ANA_POWER_PIN_COLLAPSE} 处还需添加 LC 滤波电路，用于抑制高频谐波，同时请注意该电感的额定电流最好在 500 mA 及以上。

.. only:: esp32h2

    如果 VBAT 由外部电源单独供电，R2 无需上件，工作电压范围为 3.0 V ~ 3.6 V。

.. only:: esp32c2

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-analog-power-two-layer.inc

其余电容电路请参考 :ref:`fig-chip-core-schematic`。

.. only:: esp32c3 or esp32c2

    RTC 电源
    ^^^^^^^^^^^^^

    {IDF_TARGET_NAME} 的 VDD3P3_RTC 管脚为 RTC 电源管脚，建议在电路中靠近该电源管脚处添加 0.1 μF 去耦电容。

    请注意该电源不可以作为备用电源单独供电。

    RTC 电源电路图如图 :ref:`fig-chip-RTC-power` 所示。

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-rtc-power.png
       :name: fig-chip-RTC-power
       :align: center
       :width: 50%
       :alt: {IDF_TARGET_NAME} 系列芯片 RTC 电源电路图

       {IDF_TARGET_NAME} 系列芯片 RTC 电源电路图

上电时序与复位
----------------

{IDF_TARGET_CHIPUP_PIN:default="CHIP_PU", esp32h2="CHIP_EN", esp32c3="CHIP_EN", esp32c2="CHIP_EN"}

{IDF_TARGET_RESET_POWER_PIN:default="VDD", esp32c5="VDDPST1", esp32s3="VDD3P3_RTC", esp32c61="VDDPST1"}

{IDF_TARGET_RESET_POWER:default="(–0.3 ~ 0.25 × VDD)", esp32c5="(–0.3 ~ 0.25 × VDDPST1)", esp32s3="(–0.3 ~ 0.25 × VDD3P3_RTC)", esp32="(NA ~ 0.6)", esp32c61="(–0.3 ~ 0.25 × VDDPST1)", esp32c6="(–0.3 ~ 0.25 × VDDPST1)"}

{IDF_TARGET_NAME} 的 {IDF_TARGET_CHIPUP_PIN} 管脚为高电平时使能芯片，为低电平时复位芯片。

当 {IDF_TARGET_NAME} 使用 3.3 V 系统电源供电时，电源轨需要一些时间才能稳定，之后才能拉高 {IDF_TARGET_CHIPUP_PIN}，激活芯片。因此，{IDF_TARGET_CHIPUP_PIN} 管脚上电要晚于系统电源 3.3 V 上电。

复位芯片时，复位电压 V\ :sub:`IL_nRST` 范围应为 {IDF_TARGET_RESET_POWER} V。为防止外界干扰引起重启，{IDF_TARGET_CHIPUP_PIN} 管脚引线需尽量短一些。

图 :ref:`fig-chip-timing` 为 {IDF_TARGET_NAME} 系列芯片的上电、复位时序图。

.. only:: esp32

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-chip-timing.png
       :name: fig-chip-timing
       :align: center
       :width: 100%
       :alt: {IDF_TARGET_NAME} 系列芯片上电和复位时序图

       {IDF_TARGET_NAME} 系列芯片上电和复位时序图

.. only:: not esp32

    .. figure:: ../_static/shared-chip-timing__cn.png
       :name: fig-chip-timing
       :align: center
       :scale: 70%
       :alt: {IDF_TARGET_NAME} 系列芯片上电和复位时序图

       {IDF_TARGET_NAME} 系列芯片上电和复位时序图

上电和复位时序参数说明见表 :ref:`tab-chip-timing`。

.. list-table:: 上电和复位时序参数说明
    :name: tab-chip-timing
    :header-rows: 1
    :widths: 20 60 20
    :align: center

    * - 参数
      - 说明
      - 最小值 (µs)
    * - t\ :sub:`STBL`
      - {IDF_TARGET_CHIPUP_PIN} 管脚上电晚于电源管脚上电的延时时间
      - 50
    * - t\ :sub:`RST`
      - {IDF_TARGET_CHIPUP_PIN} 电平低于 V\ :sub:`IL_nRST` 从而复位芯片的时间
      - 50

.. attention::

    - {IDF_TARGET_CHIPUP_PIN} 管脚不可浮空。
    - 为确保芯片上电和复位时序正常，一般采用的方式是在 {IDF_TARGET_CHIPUP_PIN} 管脚处增加 RC 延迟电路。RC 通常建议为 R = 10 kΩ，C = 1 μF，但具体数值仍需根据实际的电源特性配合芯片的上电、复位时序进行调整。
    - 如果应用中存在以下场景：

        - 电源缓慢上升或下降，例如电池充电；
        - 需要频繁上下电的操作；
        - 供电电源不稳定，例如光伏发电。

      此时，仅仅通过 RC 电路不一定能满足时序要求，有概率会导致芯片无法进入正常的工作模式。此时，需要增加一些额外的电路设计，比如：

        - 增加复位芯片或者看门狗芯片，通常阈值为 3.0 V 左右；
        - 通过按键或主控实现复位等。

.. only:: esp32 or esp32s3 or esp32s2 or esp32c5 or esp32c61

    .. _schematic-checklist-flash-psram:

    Flash 及 PSRAM
    ------------------

    {IDF_TARGET_EXTERNAL_FLASH_PSRAM_SCHEMATIC:default="to be defined", esp32c5=":ref:`fig-external-flash-psram-schematic`", esp32c61=":ref:`fig-chip-core-schematic`"}

    {IDF_TARGET_NAME} 系列芯片需配合封装内或封装外 flash 一起使用，用于存储应用的固件和数据。封装内 PSRAM 和封装外 PSRAM 非必需。

    .. only:: esp32 or esp32s3 or esp32c5 or esp32c61

        封装内 Flash 及 PSRAM
        ^^^^^^^^^^^^^^^^^^^^^^^

        下面的表格列出了 {IDF_TARGET_NAME} 与封装内 flash/PSRAM 的管脚对应关系。请注意这些芯片管脚最多连接一个 flash 和一个 PSRAM，即当封装内仅有 flash 时，被 flash 占用的管脚只能再连接一个 PSRAM，不能用于其他功能；封装内仅有 PSRAM 时，被 PSRAM 占用的管脚只能再连接一个 flash；封装内同时有 flash 和 PSRAM 时，被占用的管脚不能再连接 flash 或 PSRAM。

        .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-chip-flash-pin-mapping.inc


    .. only:: esp32 or esp32s3 or esp32s2

        封装外 Flash 及 PSRAM
        ^^^^^^^^^^^^^^^^^^^^^^^

        为了减少软件适配的风险，推荐使用乐鑫官方适配过的 flash 和 PSRAM 型号，具体选型请咨询商务或者技术团队。如果使用 {IDF_TARGET_VDD_POWER} 输出电压供电，设计时请注意需根据设置的 {IDF_TARGET_VDD_POWER} 模式 (1.8 V/3.3 V) 选择合适的封装外 flash/PSRAM。另外，建议 SPI 通信线上预留 0 Ω 串联电阻，以便在需要时进行灵活调整，实现降低驱动电流、减小对射频的干扰、调节时序、提升抗干扰能力等功能。

    .. only:: esp32c5 or esp32c61

        封装外 flash 及 PSRAM
        ^^^^^^^^^^^^^^^^^^^^^^^

        为了减少软件适配的风险，推荐使用乐鑫官方适配过的 flash 和 PSRAM 型号，具体选型请咨询商务或者技术团队。建议如图 {IDF_TARGET_EXTERNAL_FLASH_PSRAM_SCHEMATIC} 所示在 SPI 线上预留 0 Ω 串联电阻，以便在需要时进行灵活调整，实现降低驱动电流、减小对射频的干扰、调节时序、提升抗干扰能力等功能。

        .. only:: esp32c5

            .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-external-flash-psram.png
                :name: fig-external-flash-psram-schematic
                :align: center
                :width: 90%
                :alt: {IDF_TARGET_NAME} 系列芯片封装外 flash/PSRAM 电路图

                {IDF_TARGET_NAME} 系列芯片封装外 flash/PSRAM 电路图

    .. only:: esp32s2

        目前，ESP32-S2-WROVER 模组默认采用 4 MB 的 SPI flash 及 2 MB 的 PSRAM。

        图 :ref:`fig-external-flash-psram-schematic` 为 {IDF_TARGET_NAME} 系列芯片的 flash 及 SRAM 电路图。

        .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-flash-psram.png
            :name: fig-external-flash-psram-schematic
            :align: center
            :width: 95%
            :alt: {IDF_TARGET_NAME} Flash 及 SRAM 电路

            {IDF_TARGET_NAME} Flash 及 SRAM 电路

.. only:: esp32h2 or esp32c2

    Flash
    -------

    {IDF_TARGET_INT_FLASH_SIZE:default="待定", esp32h2="2 MB 或 4 MB", esp32c2="1 MB、2 MB 或 4 MB"}

    {IDF_TARGET_NAME} 系列芯片内部合封 {IDF_TARGET_INT_FLASH_SIZE} flash，内部的 flash 管脚没有引出到芯片上。

.. only:: esp32c6

    .. _schematic-checklist-flash:

    Flash
    ------

    {IDF_TARGET_NAME} 系列芯片需配合封装内或封装外 flash 一起使用，用于存储应用的固件和数据。

    封装内 flash
    ^^^^^^^^^^^^^^^^

    {IDF_TARGET_INT_FLASH_SIZE:default="", esp32c6="4 MB 或 8 MB"}

    {IDF_TARGET_NAME} 系列芯片内部合封 {IDF_TARGET_INT_FLASH_SIZE} flash，内部的 flash 管脚没有引出到芯片上。

    封装外 flash
    ^^^^^^^^^^^^^^^^

    为了减少软件适配的风险，推荐使用乐鑫官方适配过的 flash 型号，具体选型请咨询商务或者技术团队。建议如图 :ref:`fig-external-flash-schematic` 所示在 SPI 线上预留 0 Ω 串联电阻，以便在需要时进行灵活调整，实现降低驱动电流、减小对射频的干扰、调节时序、提升抗干扰能力等功能。

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-external-flash.png
       :name: fig-external-flash-schematic
       :align: center
       :width: 90%
       :alt: {IDF_TARGET_NAME} 系列芯片封装外 Flash 电路图

       {IDF_TARGET_NAME} 系列芯片封装外 Flash 电路图

.. only:: esp32c3

    .. _schematic-checklist-flash:

    Flash
    -------

    {IDF_TARGET_NAME} 支持的外部 flash 最大可到 16 MB，使用 {IDF_TARGET_VDD_POWER}输出电源供电。建议如图 :ref:`fig-external-flash-schematic` 所示在 SPI 线上预留 0 Ω 串联电阻，以便在需要时进行灵活调整，实现降低驱动电流、减小对射频的干扰、调节时序、提升抗干扰能力等功能。

    对于 {IDF_TARGET_NAME} 封装内有 SPI flash 的芯片型号，flash 管脚不能再被外部使用为其他用处。

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-external-flash.png
       :name: fig-external-flash-schematic
       :align: center
       :width: 90%
       :alt: {IDF_TARGET_NAME} 系列芯片封装外 Flash 电路图

       {IDF_TARGET_NAME} 系列芯片封装外 Flash 电路图

时钟源
----------

{IDF_TARGET_RTC_CLOCK:default="RTC ", esp32h2="低功耗"}

.. only:: not esp32c2

    {IDF_TARGET_NAME} 外部可以有两个时钟源：

    - `外置主晶振时钟源（必选）`_
    - `{IDF_TARGET_RTC_CLOCK}时钟源（可选）`_

.. _schematic-checklist-external-crystal-source:

外置主晶振时钟源（必选）
^^^^^^^^^^^^^^^^^^^^^^^^^

{IDF_TARGET_CRYSTAL_FREQ:default="40", esp32h2="32", esp32c2="26 MHz and 40", esp32c5="48"}

{IDF_TARGET_EXT_CAPACITOR:default="C4", esp32="C2", esp32c3="C2", esp32c2="C2", esp32c5="C2", esp32c61="C2"}

{IDF_TARGET_WIFI_BLE:default="Wi-Fi 或蓝牙", esp32h2="蓝牙"}

{IDF_TARGET_WIFI_BAND:default="2.4", esp32c5="2.4 或者 5"}

.. only:: esp32c2

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-chip-core-schem-note.inc

.. only:: not esp32c2

    目前 {IDF_TARGET_NAME} 系列芯片固件仅支持 {IDF_TARGET_CRYSTAL_FREQ} MHz 晶振。

{IDF_TARGET_NAME} 的无源晶振部分电路如图 :ref:`fig-external-crystal-schematic`。注意，选用的无源晶振自身精度需在 ±10 ppm。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-external-crystal.png
   :name: fig-external-crystal-schematic
   :align: center
   :width: 65%
   :alt: {IDF_TARGET_NAME} 系列芯片无源晶振电路图

   {IDF_TARGET_NAME} 系列芯片无源晶振电路图

.. only:: esp32

    XTAL_P 时钟走线上请放置一个串联电阻，初始建议使用 0 Ω，用来减弱晶振高频谐波对射频性能的影响，最终值需要通过测试后确认。

.. only:: not esp32

    XTAL_P 时钟走线上请放置一个串联元器件，初始建议使用 24 nH 电感，用来减弱晶振高频谐波对射频性能的影响，最终值需要通过测试后确认。

外部匹配电容 C1 和 {IDF_TARGET_EXT_CAPACITOR} 的初始值可参考以下公式来决定：

.. math::

   C_L =  \frac{C1 \times {IDF_TARGET_EXT_CAPACITOR}} {C1+{IDF_TARGET_EXT_CAPACITOR}} + C_{stray}

其中 C\ :sub:`L` （负载电容）的值可查看所选择晶振的规格书，C\ :sub:`stray` 的值为 PCB 的寄生电容。C1 和 {IDF_TARGET_EXT_CAPACITOR} 的最终值需要通过对系统测试后进行调节确定。调试方法如下：

1. 通过 `认证测试工具 <https://www.espressif.com/zh-hans/support/download/other-tools?keys=>`_，选择 TX tone 模式。
2. 使用综测仪或者频谱仪查看 {IDF_TARGET_WIFI_BAND} GHz 信号，解调得到实际频偏。
3. 通过调整外置负载电容，把频偏调整到 ±10 ppm（建议）以内。

  - 当中心频率偏正时，说明等效负载电容偏小，需要增加外置负载电容。
  - 当中心频率偏负时，说明等效负载电容偏大，需要减小外置负载电容。
  - 通常两个外置负载电容相等，在特殊情况下，也可以有略微差异。

.. only:: esp32s2

    如需使用有源晶振，则将有源晶振的时钟输出通过一个隔直电容（50 pF 左右）连接至芯片端的 XTAL_P 端，XTAL_N 悬空即可。注意需要保证该有源晶振的输出时钟稳定且精度在 ±10 ppm 以内。另外，建议用户做好外接无源晶振的兼容设计，以防有源晶振电路出现问题时仍可以替换为无源晶振工作。{IDF_TARGET_NAME} 的有源晶振部分电路如图 :ref:`fig-crystal-osc-schematic`。

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-crystal-osc.png
        :name: fig-crystal-osc-schematic
        :align: center
        :width: 65%
        :alt: {IDF_TARGET_NAME} 系列芯片有源晶振电路图

        {IDF_TARGET_NAME} 系列芯片有源晶振电路图

.. note::

  - 尽管 {IDF_TARGET_NAME} 内部带有自校准功能，但是自身频偏过大（例如大于 ±10 ppm）、工作温度范围内稳定度不高等晶振本身的质量问题仍然会影响芯片的正常工作，导致射频指标性能下降。
  - 建议晶振的幅值大于 500 mV。
  - 如果出现功能性的 {IDF_TARGET_WIFI_BLE}无法连接，排除软件原因后，可以采用上文中的方法，通过调节晶振的电容来保证频偏满足要求。

.. only:: not esp32c2

    .. _schematic-rtc-clock-source:

    {IDF_TARGET_RTC_CLOCK}时钟源（可选）
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    {IDF_TARGET_EXT_SIG_INPUT:default="通过一个隔直电容（20 pF 左右）输入至 XTAL 的 P 端，N 端悬空即可", esp32="输入至 32K_XN。在 32K_XP 端添加大于 200 pF 的电容", esp32s2="通过一个隔直电容（20 pF 左右）输入至 XTAL_32K 的 P 端，N 端悬空即可"}

    {IDF_TARGET_NAME} 支持外置 32.768 kHz 的无源晶振作为 {IDF_TARGET_RTC_CLOCK}时钟。使用外部 {IDF_TARGET_RTC_CLOCK}时钟源是为了使时间更准确，从而降低平均功耗，但对于功能没有任何影响。

    外置 32.768 kHz 无源晶振的电路如图 :ref:`fig-32khz-crystal-schematic` 所示。

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-32khz-crystal.png
        :name: fig-32khz-crystal-schematic
        :align: center
        :width: 90%
        :alt: {IDF_TARGET_NAME} 系列芯片外置 32.768 kHz 无源晶振电路图

        {IDF_TARGET_NAME} 系列芯片外置 32.768 kHz 无源晶振电路图

    请注意 32.768 kHz 晶振选择要求：

        - 等效内阻 (ESR) ≤ 70 kΩ。
        - 两端负载电容值根据晶振的规格要求进行配置。

    并联电阻 R 用于偏置晶振电路，电阻值要求 5 MΩ < R ≤ 10 MΩ。

    .. only:: not esp32 and not esp32c61

        该电阻一般无需上件。

    .. only:: esp32c61

        该电阻必须上件。

    .. only:: esp32

        使用芯片版本 v1.0 或 v1.1 时，不建议使用 32.768 kHz 晶振。使用芯片版本 v3.0 及以上时，可以使用 32.768 kHz 晶振，此时并联电阻 R 必须上件。

        使用 AT 固件时，默认开启了 32.768 kHz 晶振功能，为了防止晶振管脚悬空引入干扰误触发 32.768 kHz 晶振功能，建议在 32K_XP 和 32K_XN 管脚处预留对地的电阻，不用上件。

    如果不需要该 {IDF_TARGET_RTC_CLOCK}时钟源，则 32.768 kHz 晶振的管脚也可配置为通用 GPIO 口使用。

.. _schematic-checklist-rf:

射频
------

.. _schematic-checklist-rf-circuit:

射频电路
^^^^^^^^^^^^^^

{IDF_TARGET_RF_MAT_CIRCUIT:default="CLC", esp32c6="CLCCL", esp32h2="CLCCL", esp32c2="CLCCL", esp32c61="CLCCL"}

{IDF_TARGET_NAME} 系列芯片的射频电路主要由三部分组成：PCB 板射频走线、芯片匹配电路、天线及其匹配电路。各部分电路应满足以下设计规范：

- PCB 板射频走线：需进行 50 Ω 阻抗控制。
- 芯片匹配电路：请尽量靠近芯片放置，优先采用 {IDF_TARGET_RF_MAT_CIRCUIT} 结构。

    .. list::

        :esp32h2 or esp32c2: - {IDF_TARGET_RF_MAT_CIRCUIT} 结构构成带通滤波器，主要用来调整阻抗点，抑制谐波及抑制低频噪声（尤其在电工照明类的应用中效果显著）。如果应用中没有 AC 转 DC 电路，可以考虑只用 CLC 结构。

        :esp32c61 or esp32c6: - {IDF_TARGET_RF_MAT_CIRCUIT} 结构构成带通滤波器，主要用来调整阻抗点，抑制高频谐波及抑制低频噪声。

        :esp32s2 or esp32c3: - {IDF_TARGET_RF_MAT_CIRCUIT} 结构主要用于阻抗匹配及谐波抑制，空间允许的情况下可以再加一组 LC。

        :esp32s3 or esp32: - {IDF_TARGET_RF_MAT_CIRCUIT} 结构主要用于阻抗匹配及谐波抑制。

        :esp32c5: - {IDF_TARGET_RF_MAT_CIRCUIT} 结构主要用于阻抗匹配及谐波抑制，ANT_2G 和 ANT_5G 射频接口需要各自添加一组。

        - 芯片匹配电路如图 :ref:`fig-rf-matching-schematic` 所示。

- 天线及其匹配电路：为保证辐射性能，建议天线的输入阻抗为 50 Ω 左右。为保险起见，推荐在靠近天线位置增加一组 CLC 匹配电路，用于调节天线的输入阻抗。如果经过仿真可以确保天线阻抗点为 50 Ω 左右，并且空间较小，则可以不加天线端的匹配电路。

.. only:: esp32c5

    - ANT_2G 和 ANT_5G 射频接口可以各接一个天线（分时复用），此时建议在 2G 和 5G 接口添加 CLCCL 匹配电路；也可以通过双工器（型号 LFD182G45DCHD481）接到一个天线上，该天线需要支持双频。

.. only:: esp32c5 or esp32s3 or esp32 or esp32c61 or esp32c6

    - 建议在天线端预留 ESD 保护器件用于抵抗静电干扰。

.. only:: esp32c61

    .. note::

       如果有进行 FCC/NCC 认证的计划，建议在 GPIO4 和 GPIO5 上预留对地电容，以有效抑制谐波干扰。对于不涉及此类认证的客户，可无需预留。如果使用 ESP32-C61-WROOM-1U 模组的 ANT2，请在 ANT2 管脚处添加 CLC 电路用来抑制低频噪声。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-rf-matching.png
   :name: fig-rf-matching-schematic
   :align: center
   :width: 80%
   :alt: {IDF_TARGET_NAME} 系列芯片射频匹配电路图

   {IDF_TARGET_NAME} 系列芯片射频匹配电路图

.. _schematic-checklist-rf-tunning:

射频调试
^^^^^^^^^^^^^^

{IDF_TARGET_CONJUGATE_POINT_VALUE:default="35+j0", esp32="25+j0", esp32c2="30+j0"}

射频匹配网络的参数值和 PCB 板有关，不要直接使用模组的匹配值，须按照下述射频调试进行确认。

图 :ref:`fig-rf-tuning` 展示了射频调试的大概过程。

.. include:: shared/esp-other-chip-rf-tuning.inc

.. note::

    如果不需要射频功能，建议不要在固件中初始化射频堆栈。此时，射频管脚可以悬空。如果启用射频功能，请确保已连接天线，否则可能导致系统不稳定或射频电路损坏。

.. _schematic-checklist-uart:

UART
---------

.. only:: esp32c5 or esp32s3 or esp32 or esp32c61 or esp32c6

    {IDF_TARGET_UART_NUM:default="待定", esp32c5="3", esp32s3="3", esp32="3", esp32c61="3", esp32c6="3"}
    {IDF_TARGET_UART_NAMES:default="待定", esp32c5="UART0、UART1 和 LP UART", esp32s3="UART0、UART1 和 UART2", esp32="UART0、UART1 和 UART2", esp32c61="UART0、UART1 和 UART2", esp32c6="UART0、UART1 和 LP UART"}

    {IDF_TARGET_U0TXD:default="待定", esp32s3="GPIO43", esp32c5="GPIO11", esp32="GPIO1", esp32c61="GPIO11", esp32c6="GPIO16"}
    {IDF_TARGET_U0RXD:default="待定", esp32s3="GPIO44", esp32c5="GPIO12", esp32="GPIO3", esp32c61="GPIO10", esp32c6="GPIO17"}

    {IDF_TARGET_UART_SIGNAL:default=" UART 信号", esp32c5="信号"}

    {IDF_TARGET_NAME} 有 {IDF_TARGET_UART_NUM} 个 UART 接口，即 {IDF_TARGET_UART_NAMES}。U0TXD 和 U0RXD 默认为 {IDF_TARGET_U0TXD} 和 {IDF_TARGET_U0RXD}，其他{IDF_TARGET_UART_SIGNAL}可以通过软件配置到任意空闲的 GPIO 管脚上。

.. only:: esp32c5 or esp32c6

    LP UART 管脚是固定的，详见表 :ref:`tab-lp-uart-pin-config`。

UART0 通常作为下载和 log 打印的串口。关于如何使用 UART0 进行下载，请参考章节 :ref:`download-guidelines`。U0TXD 线上建议串联 499 Ω 电阻用于抑制谐波。

推荐使用其他 UART 作为通信的串口，同样在 TX 线上建议预留串联电阻用于抑制谐波。

.. only:: esp32s2

     GPIO18 作为 U1RXD，在芯片上电时是不确定状态，可能会影响芯片正常进入下载启动模式，需要在外部增加一个上拉电阻来解决。

.. only:: esp32 or esp32c2 or esp32c3 or esp32c6 or esp32s2

    请注意使用 AT 固件时，固件里配置了 UART 的 GPIO，可以参考 `硬件连接 <https://docs.espressif.com/projects/esp-at/zh_CN/latest/{IDF_TARGET_PATH_NAME}/Get_Started/Hardware_connection.html>`_，建议使用默认配置。

.. only:: esp32c5 or esp32c6

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-lp-uart-pin-config.inc

.. _schematic-checklist-spi:

SPI
---

在使用 SPI 功能时，为了提高 EMC 性能，请在 SPI_CLK 线上添加串联电阻（或磁珠）以及对地电容。如果空间允许，建议在其他 SPI 线上也添加串联电阻和对地电容。另外，请确保 RC/LC 器件靠近芯片或模组的管脚放置。

.. _schematic-checklist-strapping-pins:

Strapping 管脚
-----------------

{IDF_TARGET_STRAP_PIN_NO_CAP:default="待定", esp32="GPIO0", esp32s3="GPIO0", esp32c6="GPIO9", esp32h2="GPIO9", esp32c2="GPIO9", esp32s2="GPIO0", esp32c3="GPIO9", esp32c5="GPIO28", esp32c61="GPIO9"}

{IDF_TARGET_BOOT_STRAP_PIN:default="待定", esp32="GPIO0 和 GPIO2", esp32s3="GPIO0 和 GPIO46", esp32h2="GPIO8 和 GPIO9", esp32c3="GPIO2、GPIO8 和 GPIO9", esp32c2="GPIO8 和 GPIO9", esp32s2="GPIO0 和 GPIO46", esp32c5="GPIO26、GPIO27 和 GPIO28", esp32c6="GPIO8 和 GPIO9", esp32c61="GPIO8 和 GPIO9"}

{IDF_TARGET_STRAP_PIN:default="to be defined", esp32="GPIO、GPIO2、GPIO5、MTDI 和 MTDO", esp32s3="GPIO0、GPIO3、GPIO45 和 GPIO46", esp32h2="GPIO8、GPIO9 和 GPIO25", esp32c3="GPIO2、GPIO8 和 GPIO9", esp32c2="GPIO8 和 GPIO9", esp32s2="GPIO0、GPIO45 和 GPIO46", esp32c5="GPIO25、GPIO26、GPIO27、GPIO28、GPIO7、MTMS 和 MTDI", esp32c6="GPIO8、GPIO9、GPIO15、MTMS 和 MTDI", esp32c61="GPIO7、GPIO8、GPIO9、MTMS 和 MTDI"}

芯片每次上电或复位时，都需要一些初始配置参数，如加载芯片的启动模式等。这些参数通过 strapping 管脚控制。复位放开后，strapping 管脚和普通 IO 管脚功能相同。

{IDF_TARGET_STRAP_PIN} 为 strapping 管脚。

所有的 strapping 管脚信息，可参考 `{IDF_TARGET_NAME} 系列芯片技术规格书 <{IDF_TARGET_DATASHEET_CN_URL}>`__ > 章节 *启动配置项*。

.. only:: esp32s3 or esp32

    与 {IDF_TARGET_VDD_POWER} 有关的 strapping 管脚信息请见 :ref:`digital-power-supply` 章节。

下面主要介绍和启动模式有关的 strapping 管脚信息。

芯片复位释放后，{IDF_TARGET_BOOT_STRAP_PIN} 共同决定启动模式，详见表 :ref:`tab-chip-boot-mode-control`。

.. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-chip-boot-mode-control.inc

Strapping 管脚的时序参数包括 *建立时间* 和 *保持时间*。更多信息，详见图 :ref:`fig-shared-strap-pin-timing` 和表 :ref:`tab-strap-pin-timing`。

.. figure:: ../_static/shared-strap-pin-timing.png
   :name: fig-shared-strap-pin-timing
   :align: center
   :width: 90%
   :alt: Strapping 管脚的时序参数图

   Strapping 管脚的时序参数图

.. list-table:: Strapping 管脚的时序参数说明
    :name: tab-strap-pin-timing
    :header-rows: 1
    :widths: 20 60 20
    :align: center

    * - 参数
      - 说明
      - 最小值 (ms)
    * - t\ :sub:`SU`
      - *建立时间*，即拉高 {IDF_TARGET_CHIPUP_PIN} 激活芯片前，电源轨达到稳定所需的时间
      - 0
    * - t\ :sub:`H`
      - *保持时间*，即 {IDF_TARGET_CHIPUP_PIN} 已拉高、strapping 管脚变为普通 IO 管脚开始工作前，可读取 strapping 管脚值的时间
      - 3

.. only:: not esp32c5

    .. attention::

        - 建议在 {IDF_TARGET_STRAP_PIN_NO_CAP} 管脚处预留上拉电阻。
        - 不要在 {IDF_TARGET_STRAP_PIN_NO_CAP} 管脚处添加较大的电容，可能会导致进入下载模式。

.. only:: esp32c5

    .. attention::

        - 建议在 {IDF_TARGET_STRAP_PIN_NO_CAP} 管脚处预留上拉电阻。
        - 建议在 {IDF_TARGET_STRAP_PIN_NO_CAP} 管脚处预留电容位置用于调节，电容先不要上件、值不要过大，否则可能会导致进入下载模式。

.. _schematic-checklist-gpio:

GPIO
--------

{IDF_TARGET_NAME} 系列芯片通过 IO MUX 表格或者 GPIO 交换矩阵来配置 GPIO。IO MUX 是默认的外设管脚配置（详见 `{IDF_TARGET_NAME} 系列芯片技术规格书 <{IDF_TARGET_DATASHEET_CN_URL}#cd-append-consolid-pin-overview>`__ > 附录 *{IDF_TARGET_NAME} 管脚总览*），GPIO 交换矩阵用于将可以配置的外设信号传输至 GPIO 管脚。更多关于 IO MUX 和 GPIO 交换矩阵的信息，请参考 `{IDF_TARGET_NAME} 技术参考手册 <{IDF_TARGET_TRM_CN_URL}>`__ > 章节 *IO MUX 和 GPIO 交换矩阵*。

部分外设的 GPIO 管脚是固定的，部分是可以任意配置的，具体信息请参考 `{IDF_TARGET_NAME} 系列芯片技术规格书 <{IDF_TARGET_DATASHEET_CN_URL}>`__ > 章节 *外设*。

使用 GPIO 时，请注意：

{IDF_TARGET_DEEP_SLEEP_POWER_DOMAIN:default="待定", esp32c6="VDDPST1", esp32="VDD3P3_RTC", esp32s3="VDD3P3_RTC"}

.. list::

    - Strapping 管脚的上电状态。
    - 请注意 GPIO 复位后的默认配置，详见下表。建议对处于高阻态的管脚配置上拉或下拉，或在软件初始化时开启管脚自带的上下拉，以避免不必要的耗电。
    :esp32 or esp32s3 or esp32s2 or esp32c61: - 避免使用 flash/PSRAM 占用的管脚。
    :esp32: - 请注意 GPIO34 及以上的 GPIO 仅为输入，并且内部没有上下拉，需要的话请在外部添加合适的电阻。
    :esp32s2: - GPIO33 ~ GPIO37 属于同一电源域，即 VDD3P3_CPU，也可由软件配置为 VDD_SPI。
    :esp32c6 or esp32c3 or esp32c5: - 避免使用 flash 占用的管脚。
    :esp32s3 or esp32c2 or esp32c3: - 上电过程中，部分管脚会有毛刺，详见表 :ref:`tab-glitches-on-pins`。
    :esp32s3: - 在启用 USB-OTG Download Boot 模式时，部分管脚会有电平输出，详见表 :ref:`IO Pad Status After Chip Initialization in the USB-OTG Download Boot Mode`。
    :esp32s3: - SPICLK_N、SPICLK_P、GPIO33 ~ GPIO37 属于同样的电源域，因此，如果使用八线 1.8 V 的 flash/PSRAM，SPICLK_P 和 SPICLK_N 也属于 1.8 V 电源域。
    :esp32 or esp32s3 or esp32c6: - Deep-sleep 模式下只能控制电源域为 {IDF_TARGET_DEEP_SLEEP_POWER_DOMAIN} 的 GPIO。
    :esp32c5 : - Deep-sleep 模式下只能控制 LP GPIO，即 GPIO0 至 GPIO6。
    :esp32c61: - Deep-sleep 模式下只能控制 LP GPIO, 即下表中供电管脚为 VDDPST1 的 GPIO。


.. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-table-io-mux.inc

.. only:: esp32s3 or esp32c2 or esp32c3

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-table-glitches.inc

.. _schematic-checklist-adc:

ADC
------

{IDF_TARGET_ADC_CALI_ATTEN0:default="待定", esp32="100 ~ 950 mV", esp32s3="0 ~ 850 mV", esp32c6=" 0 ~ 1000 mV", esp32h2="0 ~ 1000 mV", esp32c2="0 ~ 950 mV", esp32c3="0 ~ 750 mV", esp32c61="0 ~ 1000 mV"}

{IDF_TARGET_ADC_CALI_ATTEN1:default="待定", esp32="100 ~ 1250 mV", esp32s3="0 ~ 1100 mV", esp32c6=" 0 ~ 1300 mV", esp32h2="0 ~ 1300 mV", esp32c3="0 ~ 1050 mV", esp32c61="0 ~ 1300 mV"}

{IDF_TARGET_ADC_CALI_ATTEN2:default="待定", esp32="150 ~ 1750 mV", esp32s3="0 ~ 1600 mV", esp32c6=" 0 ~ 1900 mV", esp32h2="0 ~ 1900 mV", esp32c3="0 ~ 1300 mV", esp32c61="0 ~ 1900 mV"}

{IDF_TARGET_ADC_CALI_ATTEN3:default="待定", esp32="150 ~ 2450 mV", esp32s3="0 ~ 2900 mV", esp32c6=" 0 ~ 3300 mV", esp32h2="0 ~ 3300 mV", esp32c2="0 ~ 2800 mV", esp32c3="0 ~ 2500 mV", esp32c61="0 ~ 3300 mV"}

{IDF_TARGET_ADC_CALI_ERROR0:default="待定", esp32="±23 mV", esp32s3="±5 mV", esp32c6="±12 mV", esp32h2="±7 mV", esp32c2="±5 mV", esp32c3="±10 mV", esp32c61="±10 mV"}

{IDF_TARGET_ADC_CALI_ERROR1:default="待定", esp32="±30 mV", esp32s3="±6 mV", esp32c6="±12 mV", esp32h2="±8 mV", esp32c3="±10 mV", esp32c61="±10 mV"}

{IDF_TARGET_ADC_CALI_ERROR2:default="待定", esp32="±40 mV", esp32s3="±10 mV", esp32c6="±23 mV", esp32h2="±12 mV", esp32c3="±10 mV", esp32c61="±12 mV"}

{IDF_TARGET_ADC_CALI_ERROR3:default="待定", esp32="±60 mV", esp32s3="±50 mV", esp32c6="±40 mV", esp32h2="±23 mV", esp32c2="±10 mV", esp32c3="±35 mV", esp32c61="±15 mV"}

.. only:: esp32s3 or esp32

    ADC 功能对应的 GPIO 管脚如下表所示。

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-table-adc-gpio.inc

使用 ADC 功能时，请靠近管脚添加 0.1 μF 的对地滤波电容，精度会更准确一些。

.. only:: esp32 or esp32s3 or esp32c6 or esp32h2 or esp32c3 or esp32c5 or esp32c61

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-adc.inc

.. only:: esp32 or esp32s3 or esp32c6 or esp32h2 or esp32c2 or esp32c3 or esp32c61

    ADC 经硬件校准和 `软件校准 <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/{IDF_TARGET_PATH_NAME}/api-reference/peripherals/adc_calibration.html>`_ 后的结果如以下列表所示。如需更高的精度，可选用其他方法自行校准。

.. list::

    :not esp32s2 and not esp32c5: - 当 ATTEN=0，有效测量范围为 {IDF_TARGET_ADC_CALI_ATTEN0} 时，总误差为 {IDF_TARGET_ADC_CALI_ERROR0}。
    :not esp32c2 and not esp32s2 and not esp32c5: - 当 ATTEN=1，有效测量范围为 {IDF_TARGET_ADC_CALI_ATTEN1} 时，总误差为 {IDF_TARGET_ADC_CALI_ERROR1}。
    :not esp32c2 and not esp32s2 and not esp32c5: - 当 ATTEN=2，有效测量范围为 {IDF_TARGET_ADC_CALI_ATTEN2} 时，总误差为 {IDF_TARGET_ADC_CALI_ERROR2}。
    :not esp32s2 and not esp32c5: - 当 ATTEN=3，有效测量范围为 {IDF_TARGET_ADC_CALI_ATTEN3} 时，总误差为 {IDF_TARGET_ADC_CALI_ERROR3}。

.. only:: esp32

    外置阻容
    -------------

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-external-capacitor.inc

.. only:: esp32 or esp32s3 or esp32c6 or esp32c5 or esp32c61

    SDIO
    --------

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sdio.inc

.. only:: esp32s2 or esp32s3 or esp32c3 or esp32c6 or esp32h2 or esp32c5 or esp32c61

    .. _schematic-checklist-usb:

    USB
    -------

    {IDF_TARGET_USB_SPEC:default="2.0", esp32s2="1.1"}

    {IDF_TARGET_USB_GPIO:default="待定", esp32s2="GPIO19 和 GPIO20", esp32s3="GPIO19 和 GPIO20", esp32c3="GPIO18 和 GPIO19", esp32c6="GPIO12 和 GPIO13", esp32h2="GPIO26 和 GPIO27", esp32c5="GPIO13 和 GPIO14", esp32c61="GPIO12 和 GPIO13"}

    .. only:: esp32s2 or esp32s3

        {IDF_TARGET_NAME} 系列芯片带有一个集成了收发器的全速 USB On-The-Go (OTG) 外设，符合 USB {IDF_TARGET_USB_SPEC} 规范。

    .. only:: not esp32s2

        {IDF_TARGET_NAME} 系列芯片集成了一个 USB 串口/JTAG 控制器，作为兼容 USB 2.0 全速模式的设备。

    {IDF_TARGET_USB_GPIO} 可以分别作为 USB 的 D- 和 D+，线上建议预留串联电阻（初始值可为 22/33 Ω）和对地电容（初始可不上件），并注意靠近芯片端放置。

    .. only:: esp32c5 or esp32s3 or esp32c61 or esp32c6

        USB RC 电路如图 :ref:`fig-usb-rc-schematic` 所示。

        .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-usb-rc.png
            :name: fig-usb-rc-schematic
            :align: center
            :width: 55%
            :alt: {IDF_TARGET_NAME} 系列芯片 USB RC 电路图

            {IDF_TARGET_NAME} 系列芯片 USB RC 电路图

    请注意 USB_D+ 管脚上电时会输出高低电平信号，其中高电平的状态比较强，需要较强的下拉才可以拉低。因此，如果需要一个稳定的初始状态，建议添加外部上拉来提供稳定的高电平初始值。

    .. only:: not esp32s2

        {IDF_TARGET_NAME} 系列芯片也支持通过 USB 进行下载和 log 打印，下载指导请参考章节 :ref:`download-guidelines`。

    .. only:: esp32s2

        {IDF_TARGET_NAME} 系列芯片也支持将 GND、RXD、TXD 接出外接 USB 转 UART 进行下载和 log 打印，下载指导请参考章节 :ref:`download-guidelines`。

    .. only:: esp32s3

        .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-usb.inc

.. only:: esp32 or esp32s2 or esp32s3

    .. _schematic-checklist-touch:

    触摸传感器
    -------------

    {IDF_TARGET_TOUCH_PIN_NUM:default="待定", esp32s3="14", esp32="10", esp32s2="14"}

    {IDF_TARGET_NAME} 提供了多达 {IDF_TARGET_TOUCH_PIN_NUM} 个电容式传感 GPIO，能够探测由手指或其他物品直接接触或接近而产生的电容差异。这种设计具有低噪声和高灵敏度的特点，可以用于支持使用相对较小的触摸板。设计中也可以使用触摸板阵列以探测更大区域或更多点。

    .. only:: esp32s3 or esp32s2

        {IDF_TARGET_NAME} 的触摸传感器同时还支持防水和数字滤波等功能来进一步提高传感器的性能。

    .. attention::

        {IDF_TARGET_NAME} 触摸传感器目前尚无法通过射频抗扰度测试系统 (CS) 认证，应用场景有所限制。

    触摸传感器功能对应的 GPIO 管脚如下表所示。

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-table-touch-gpio.inc

    .. only:: esp32s2 or esp32s3

        注意只有 GPIO14 (TOUCH14) 可以驱动屏蔽电极。

    使用 TOUCH 功能时，建议靠近芯片侧预留串联电阻，用于减小线上的耦合噪声和干扰，也可加强 ESD 保护。该阻值建议 470 Ω 到 2 kΩ，推荐 510 Ω。具体值还需根据产品实际测试效果而定。

.. only:: esp32

    .. _schematic-checklist-ethernet-mac:

    以太网 MAC
    ---------------

    .. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-emac.inc
