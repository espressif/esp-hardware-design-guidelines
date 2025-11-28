Two-Layer PCB Design
^^^^^^^^^^^^^^^^^^^^

Figure :ref:`fig-power-layout-two-layer` shows the power traces in a two-layer PCB design.

    .. figure:: ../_static/shared-pcb-power-layout-two-layer.png
        :name: fig-power-layout-two-layer
        :align: center
        :width: 60%
        :alt: ESP32 Power Traces in a Two-Layer PCB Design

        ESP32 Power Traces in a Two-Layer PCB Design

.. list::

    - For a two-layer design, ensure to provide a continuous reference ground for the chip, RF, and crystal oscillator, as shown in the figure above.
    - In the figure above, the trace VDD33 represents the 3.3 V power trace. Unlike a four-layer design, the power trace should be routed on the top layer as much as possible. Therefore, the thermal pad in the center of the chip should be reduced in size, allowing the power trace to pass between the signal pads and the thermal pad. Vias to the bottom layer should only be used when absolutely necessary.
    - Other layout considerations are the same as for a four-layer design.
    :not esp32: - Note that there are no official two-layer modules. The figure above uses the ESP32 module as an example.
