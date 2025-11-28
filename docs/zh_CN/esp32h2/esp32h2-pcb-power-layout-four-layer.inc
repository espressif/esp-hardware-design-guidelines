{IDF_TARGET_POWER_TRACE_WIDTH:default="25", esp32c3="20", esp32c2="20", esp32h2="20", esp32c5="35"}

{IDF_TARGET_ANALOG_POWER_TRACE:default="VDD3P3", esp32c6="VDDA3P3", esp32c2="VDDA3P3", esp32h2="pin1 和 pin2 处的 VDD3P3", esp32s2="pin3 和 pin4 处的 VDD3P3", esp32c5="管脚 1、3、40 和 41 处的 VDDA6、VDDA7、VDDA1 和 VDDA2", esp32s3="pin2 和 pin3 处的 VDD3P3"}

{IDF_TARGET_ANALOG_POWER_TRACE_WIDTH:default="20", esp32c3="15", esp32c2="15", esp32h2="15"}

{IDF_TARGET_ANALOG_FILTER_CIRCUIT:default="CLC", esp32c3="LC", esp32c2="LC"}

{IDF_TARGET_RF_POWER_TRACE:default="管脚 2、3", esp32c5="管脚 1、3、40 和 41 "}

图 :ref:`fig-power-layout-four-layer` 所示为四层板设计的电源走线。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-power-layout.png
    :name: fig-power-layout-four-layer
    :align: center
    :width: 60%
    :alt: {IDF_TARGET_NAME} 系列芯片四层板电源设计

    {IDF_TARGET_NAME} 系列芯片四层板电源设计

电源走线通用要点
^^^^^^^^^^^^^^^^^^^

- 优先采用四层板设计。
- 电源走线尽量走在内层第三层。
- 通过过孔连接至顶层芯片管脚处。主干电源换层处请至少保证两个过孔。其余电源走线上的钻孔的直径应不小于电源走线的宽度。
- 芯片下方的地焊盘需要至少打九个地孔连接到地平面。
- 如需在模组背面添加散热焊盘 EPAD，建议采用多宫格设计，间隙处盖防焊油墨，地孔打在间隙处，如图 :ref:`fig-power-layout-four-layer` 所示。这样可以避免模组 EPAD 焊接至底板时因为溢锡及气泡导致芯片移位。

3.3 V 电源
^^^^^^^^^^^^^^

图 :ref:`fig-power-layout-four-layer` 中黄色高亮信号线即为 3.3 V 电源走线。

3.3 V 电源走线应遵循以下规范：

- 图 :ref:`fig-power-layout-four-layer` 中红色圆圈标示的是 ESD 保护管，需靠近电源端口放置。 电源走线进入芯片前需添加一个 10 μF 电容，该电容可与 0.1 或 1 μF 电容搭配使用。而后电源走线可在此分支，进行星形走线，减少不同电源管脚之间的耦合。所有的去耦电容请靠近对应电源管脚放置，去耦电容的接地管脚请靠近打地孔，保证较短的返回路径。
- 图 :ref:`fig-power-layout-four-layer` 中，因为 {IDF_TARGET_ANALOG_POWER_TRACE} 模拟电源和芯片电源入口接近，因此只使用了一个 10 μF 电容。如果芯片电源入口不靠近 {IDF_TARGET_ANALOG_POWER_TRACE}，请在芯片电源入口处和 {IDF_TARGET_ANALOG_POWER_TRACE} 处都添加一个 10 μF 电容。如果有足够空间，可以再各预留一个 1 μF 电容。
- 主干电源走线的线宽建议至少 {IDF_TARGET_POWER_TRACE_WIDTH} mil。模拟电源 {IDF_TARGET_ANALOG_POWER_TRACE} 分支走线建议至少 {IDF_TARGET_ANALOG_POWER_TRACE_WIDTH} mil。其他分支电源走线建议 10 mil。

模拟电源
^^^^^^^^^^^^^^

模拟电源设计应遵循以下规范：

.. list::

    :esp32s3 or esp32c3 or esp32c6 or esp32c2: - 如图 :ref:`fig-analog-power-layout` 所示，{IDF_TARGET_ANALOG_POWER_TRACE} 模拟电源处 {IDF_TARGET_ANALOG_FILTER_CIRCUIT} 滤波电容中的对地电容的 GND 焊盘建议添加过孔连接至底层的地，其余层做 keep-out 隔离处理，进一步降低谐波干扰
    - {IDF_TARGET_ANALOG_POWER_TRACE} 模拟电源两边请包地处理，和周围的射频、GPIO 之间添加 GND 隔离，并尽量能放置地孔。