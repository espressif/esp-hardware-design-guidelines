四层板设计
^^^^^^^^^^

{IDF_TARGET_POWER_TRACE_WIDTH:default="25", esp32h2="20", esp32c5="30"}

{IDF_TARGET_POWER_TRACE_OTHER_WIDTH:default="10", esp32="12 ~ 15"}

{IDF_TARGET_ANALOG_POWER_TRACE:default="VDD3P3", esp32c6="VDDA3P3", esp32c2="VDDA3P3", esp32h2="pin1 和 pin2 处的 VDD3P3", esp32s2="pin3 和 pin4 处的 VDD3P3", esp32c5="管脚 1、3、40 和 41 处的 VDDA6、VDDA7、VDDA1 和 VDDA2", esp32s3="pin2 和 pin3 处的 VDD3P3", esp32c61="管脚 2 和 3 处的 VDDA3 和 VDDA4"}

{IDF_TARGET_ANALOG_POWER_TRACE_WIDTH:default="20", esp32h2="15"}

{IDF_TARGET_RF_POWER_TRACE:default="管脚 2、3", esp32c5="管脚 1、3、40 和 41 ", esp32="管脚 3、4"}

{IDF_TARGET_POWER_STUB:default=":ref:`fig-power-layout-four-layer`", esp32=":ref:`fig-shared-power-stub`", esp32s2=":ref:`fig-shared-power-stub`", esp32c61=":ref:`fig-pcb-pin-2-3-power-layout`", esp32c6=":ref:`fig-pcb-pin-2-3-power-layout`"}

图 :ref:`fig-power-layout-four-layer` 所示为四层板设计的电源走线。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-power-layout.png
    :name: fig-power-layout-four-layer
    :align: center
    :width: 60%
    :alt: {IDF_TARGET_NAME} 系列芯片四层板电源设计

    {IDF_TARGET_NAME} 系列芯片四层板电源设计

.. list::

    - 推荐优先采用四层板设计。电源走线请尽量走在内层（非地层），通过过孔连接至芯片管脚处。主干电源换层处请至少保证两个过孔。其余电源走线上的钻孔的直径应不小于电源走线的宽度。
    - 图 :ref:`fig-power-layout-four-layer` 中黄色高亮信号线即为 3.3 V 电源走线。主干电源走线的线宽建议至少 {IDF_TARGET_POWER_TRACE_WIDTH} mil。模拟电源 {IDF_TARGET_ANALOG_POWER_TRACE} 分支走线建议至少 {IDF_TARGET_ANALOG_POWER_TRACE_WIDTH} mil。其他分支电源走线建议 {IDF_TARGET_POWER_TRACE_OTHER_WIDTH} mil。电源走线周围注意包地良好。
    :not esp32c5 and not esp32c61: - 图 :ref:`fig-power-layout-four-layer` 中红色圆圈标示的是 ESD 保护管，需靠近电源端口放置。电源走线进入芯片前需添加一个 10 μF 电容，该电容可再与一个 0.1/1 µF 电容搭配使用。而后电源走线可在此分支，进行星形走线，减少不同电源管脚之间的耦合。
    :esp32c5: - 图 :ref:`fig-power-layout-four-layer` 中红色圆圈标示的是 ESD 保护管，需靠近电源端口放置。电源走线进入芯片前需添加一个 10 μF 电容。而后电源走线可在此分支，进行星形走线，减少不同电源管脚之间的耦合。尤其注意 2.4 GHz 和 5 GHz 电源走线需要分开。
    :esp32c61: - 图 :ref:`fig-power-layout-four-layer` 中红色圆圈标示的是 ESD 保护管，需靠近电源端口放置。电源走线进入芯片前需添加一个 10 μF 电容。而后电源走线可在此分支，进行星形走线，减少不同电源管脚之间的耦合。
    :not esp32c5: - {IDF_TARGET_RF_POWER_TRACE} 处电源因为是射频相关电源，请在管脚上添加一个 10 µF 电容。该电容可再与一个 0.1/1 µF 电容搭配使用。
    :esp32c5: - {IDF_TARGET_RF_POWER_TRACE} 处电源因为是射频相关电源，请在管脚上各添加一个 10 µF 电容，并在管脚 1、3 处再各放置一个电容。
    :not esp32c5: - 请靠近{IDF_TARGET_RF_POWER_TRACE} 添加 CLC/LC 滤波电路用于抑制高频谐波。该电源可以考虑 45 度出线的方式，拉开和旁边射频走线之间的距离。除了 10 uF 电容，其余器件推荐使用 0201 封装，这样可以把{IDF_TARGET_RF_POWER_TRACE} 的滤波电路放的更靠近管脚，能够和周围的射频、GPIO 之间添加 GND 隔离，并尽量能放置地孔。使用了 0201 封装，可以在靠近芯片的第一个电容上加一段枝节到底层，其余层做 keep-out 隔离处理，可以进一步抑制谐波干扰，详见图 {IDF_TARGET_POWER_STUB}。
    :esp32c5: - 请靠近管脚 40、41 添加 CLC/LC 滤波电路用于抑制高频谐波。该电源可以考虑 45 度出线的方式，拉开和旁边射频走线之间的距离。除了 10 uF 电容，其余器件推荐使用 0201 封装，这样可以把管脚 2、3 的滤波电路放的更靠近管脚，能够和周围的射频、GPIO 之间添加 GND 隔离，并尽量能放置地孔。使用了 0201 封装，可以在靠近芯片的第一个电容上加一段枝节到底层，其余层做 keep-out 隔离处理，可以进一步抑制谐波干扰，详见下图。

.. only:: esp32s2 or esp32

    .. figure:: ../_static/shared-power-stub.png
        :name: fig-shared-power-stub
        :align: center
        :width: 50%
        :alt: {IDF_TARGET_NAME} 系列芯片电源枝节图

        {IDF_TARGET_NAME} 系列芯片电源枝节图

.. only:: esp32c5

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-pin-40-41-power-layout.png
        :name: fig-pcb-pin-40-41-power-layout
        :align: center
        :width: 50%
        :alt: {IDF_TARGET_NAME} 系列芯片管脚 40、41 电源设计

        {IDF_TARGET_NAME} 系列管脚 40、41 电源设计

.. only:: esp32c61 or esp32c6

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-pin-2-3-power-layout.png
        :name: fig-pcb-pin-2-3-power-layout
        :align: center
        :width: 50%
        :alt: {IDF_TARGET_NAME} 系列芯片管脚 2、3 电源设计

        {IDF_TARGET_NAME} 系列管脚 2、3 电源设计

.. list::

    :not esp32c61: - 图 :ref:`fig-power-layout-four-layer` 中，因为 {IDF_TARGET_ANALOG_POWER_TRACE} 模拟电源和芯片电源入口接近，因此只使用了一个 10 μF 电容。如果芯片电源入口不靠近 {IDF_TARGET_ANALOG_POWER_TRACE}，请在芯片电源入口处和 {IDF_TARGET_ANALOG_POWER_TRACE} 处都添加一个 10 μF 电容。
    - 其他每个电源管脚上请放置合适的去耦电容。去耦电容的接地管脚请靠近打地孔，保证较短的返回路径。
    - 芯片下方的地焊盘需要至少打九个地孔连接到地平面。
    - 芯片及其外围电路的器件地焊盘，建议和地铺铜充分接触，不要用走线连接。
    - 如图 :ref:`fig-power-layout-four-layer` 所示，如需在模组背面添加散热焊盘 EPAD，建议采用多宫格设计，间隙处盖防焊油墨，地孔打在间隙处。这样可以有效改善模组 EPAD 焊接至底板时的漏锡问题。
    :esp32c5 or esp32s3: - 建议把 EPAD 通过一定宽度的走线或者铜皮连接至外部的大面积铺地上，详见下图。
    :esp32c2 or esp32c3: - 建议把 EPAD 通过一定宽度的走线或者铜皮连接至外部的大面积铺地上。

.. only:: esp32c5 or esp32s3

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-epad-layout.png
        :name: fig-pcb-epad-layout
        :align: center
        :width: 50%
        :alt: {IDF_TARGET_NAME} 系列芯片底部 EPAD 设计

        {IDF_TARGET_NAME} 系列芯片底部 EPAD 设计
