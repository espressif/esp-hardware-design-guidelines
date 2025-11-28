图 :ref:`fig-power-layout-two-layer` 中属性为 VDD33 的走线即为两层板中 3.3 V 电源的走线。

两层板中 3.3 V 电源走线应遵循以下规范：

- 与四层板设计不同的是，电源走线需尽可能走在顶层。
- 将芯片中间的散热焊盘缩小，电源走在四周信号管脚与散热焊盘之间，只在不得不换层的位置，打孔至底层穿一段走线。
- 尽可能地维持底层为一个完整的地平面，同时减小电源的环绕区域。
- 其他注意事项与四层板一致。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-power-layout-two-layer.png
    :name: fig-power-layout-two-layer
    :align: center
    :width: 70%
    :alt: {IDF_TARGET_NAME} 系列芯片两层板电源设计

    {IDF_TARGET_NAME} 系列芯片两层板电源设计