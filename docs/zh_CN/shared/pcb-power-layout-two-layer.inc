两层板设计
^^^^^^^^^^

图 :ref:`fig-power-layout-two-layer` 所示为两层板设计的电源走线。

    .. figure:: ../_static/shared-pcb-power-layout-two-layer.png
        :name: fig-power-layout-two-layer
        :align: center
        :width: 60%
        :alt: ESP32 芯片两层板电源设计

        ESP32 芯片两层板电源设计

.. list::

    - 如采用两层板设计，请一定保证芯片、射频和晶振有一个完整的参考地，可以参考上图。
    - 上图中属性为 VDD33 的走线即为 3.3 V 电源走线。与四层板设计不同的是，电源走线需尽可能走在顶层。故需要将芯片中间的散热焊盘缩小，电源走在四周信号管脚与散热焊盘之间，只在不得不换层的位置，打孔至底层穿一段走线。
    - 其他注意事项与四层板一致。
    :not esp32: - 请注意官方模组没有两层板模组，上图以 ESP32 模组为例。
