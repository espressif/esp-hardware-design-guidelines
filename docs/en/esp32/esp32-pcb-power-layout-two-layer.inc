In a two-layer PCB design, the 3.3 V power traces are routed as shown labelled with VDD33 in Figure :ref:`fig-power-layout-two-layer`.

The power layout in a two-layer PCB design should meet the following guidelines:

- In contrast to the design practices for a four-layer PCB design, the power traces in a two-layer PCB design should be routed on the top layer.
- Reduce the size of the thermal pad in the center of the chip. Route the power traces between the thermal pad and its surrounding signal pins. Employ vias only when the power traces have to reach the bottom layer.
- Maintain a complete ground plane while reducing the surrounding area of the power traces.
- Other good practices for routing power traces in four-layer PCB designs still apply to two-layer PCB designs.

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-power-layout-two-layer.png
    :name: fig-power-layout-two-layer
    :align: center
    :width: 70%
    :alt: {IDF_TARGET_NAME} Power Traces in a Two-layer PCB Design

    {IDF_TARGET_NAME} Power Traces in a Two-layer PCB Design