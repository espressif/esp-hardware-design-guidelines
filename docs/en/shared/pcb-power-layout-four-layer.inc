Four-Layer PCB Design
^^^^^^^^^^^^^^^^^^^^^

{IDF_TARGET_POWER_TRACE_WIDTH:default="25", esp32h2="20", esp32c5="30"}

{IDF_TARGET_POWER_TRACE_OTHER_WIDTH:default="10", esp32="12 ~ 15"}

{IDF_TARGET_ANALOG_POWER_TRACE:default="VDD3P3", esp32c6="VDDA3P3", esp32c2="VDDA3P3", esp32h2="VDD3P3 at pin1 and pin2", esp32s2="VDD3P3 at pin3 and pin4", esp32c5="VDDA6, VDDA7, VDDA1, and VDDA2 at pin1, pin3, pin40, and pin41", esp32s3="VDD3P3 at pin2 and pin3", esp32c61="VDDA3 and VDDA4 at pin2 and pin3"}

{IDF_TARGET_ANALOG_POWER_TRACE_WIDTH:default="20", esp32h2="15"}

{IDF_TARGET_RF_POWER_TRACE:default="pin2 and pin3", esp32c5="pin1, pin3, pin40, and pin41", esp32="pin 3 and pin 4"}

{IDF_TARGET_POWER_STUB:default=":ref:`fig-power-layout-four-layer`", esp32=":ref:`fig-shared-power-stub`", esp32s2=":ref:`fig-shared-power-stub`", esp32c61=":ref:`fig-pcb-pin-2-3-power-layout`", esp32c6=":ref:`fig-pcb-pin-2-3-power-layout`"}

Figure :ref:`fig-power-layout-four-layer` shows the power traces in a four-layer PCB design.

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-power-layout.png
    :name: fig-power-layout-four-layer
    :align: center
    :width: 60%
    :alt: {IDF_TARGET_NAME} Power Traces in a Four-Layer PCB Design

    {IDF_TARGET_NAME} Power Traces in a Four-Layer PCB Design

.. list::

    - A four-layer PCB design is recommended. Whenever possible, route the power traces on the inner layers (not the ground layer) and connect them to the chip pins through vias. There should be at least two vias if the main power traces need to cross layers. The drill diameter on other power traces should be no smaller than the width of the power traces.
    - The 3.3 V power traces, highlighted in yellow, are routed as shown in Figure :ref:`fig-power-layout-four-layer`. The width of the main power traces should be no less than {IDF_TARGET_POWER_TRACE_WIDTH} mil. The width of {IDF_TARGET_ANALOG_POWER_TRACE} power traces should be no less than {IDF_TARGET_ANALOG_POWER_TRACE_WIDTH} mil. The recommended width of other power traces is {IDF_TARGET_POWER_TRACE_OTHER_WIDTH} mil. Ensure the power traces are surrounded by ground copper.
    :not esp32c5 and not esp32c61: - The red circles in :ref:`fig-power-layout-four-layer` show ESD protection diodes. Place them close to the power input. Add a 10 µF capacitor before the power trace enters the chip. You can also add a 0.1 µF or 1 µF capacitor in parallel. After that, the power trace can branch out in a star-shaped layout to reduce coupling between different power pins.
    :esp32c5: - The ESD protection diode is placed next to the power port (circled in red in Figure :ref:`fig-power-layout-four-layer`). The power trace should have a 10 µF capacitor on its way before entering into the chip. After that, the power traces are divided into several branches using a star-shaped topology, which reduces the coupling between different power pins. Please separate the 2.4 GHz and 5 GHz power traces.
    :esp32c61: - The ESD protection diode is placed next to the power port (circled in red in Figure :ref:`fig-power-layout-four-layer`). The power trace should have a 10 µF capacitor on its way before entering into the chip. After that, the power traces are divided into several branches using a star-shaped topology, which reduces the coupling between different power pins.
    :not esp32c5: -  The power supply for {IDF_TARGET_RF_POWER_TRACE} is RF related, so please place a 10 µF capacitor for each pin. You can also add a 0.1 µF or 1 µF capacitor in parallel.
    :esp32c5: - The power supply for {IDF_TARGET_RF_POWER_TRACE} is RF related, so please place a 10 µF capacitor for each pin, and add one extra capacitor for pin1 and pin3 each.
    :not esp32c5: - Add a CLC/LC filter circuit near {IDF_TARGET_RF_POWER_TRACE} to suppress high-frequency harmonics.The power trace can be routed at a 45-degree angle to maintain distance from adjacent RF traces. Except for the 10 µF capacitor, it is recommended to use 0201 components. This allows the filter circuit for {IDF_TARGET_RF_POWER_TRACE} to be placed closer to the pins, with a GND isolation layer separating them from surrounding RF and GPIO traces, while also maximizing the placement of ground vias. Using 0201 components enables placing a via to the bottom layer at the first capacitor near the chip, while maintaining a keep-out area on other layers, further reducing harmonic interference. See Figure {IDF_TARGET_POWER_STUB}.
    :esp32c5: - Add a CLC/LC filter circuit near pins 40 and 41 to suppress high-frequency harmonics. The power trace can be routed at a 45-degree angle to maintain distance from adjacent RF traces. Except for the 10 µF capacitor, it is recommended to use 0201 components. This allows the filter circuit for pins 2 and 3 to be placed closer to the pins, with a GND isolation layer separating them from surrounding RF and GPIO traces, while also maximizing the placement of ground vias. Using 0201 components enables placing a via to the bottom layer at the first capacitor near the chip, while maintaining a keep-out area on other layers, further reducing harmonic interference. See the figure below.

.. only:: esp32s2 or esp32

    .. figure:: ../_static/shared-power-stub.png
        :name: fig-shared-power-stub
        :align: center
        :width: 50%
        :alt: {IDF_TARGET_NAME} Power Stub

        {IDF_TARGET_NAME} Power Stub

.. only:: esp32c5

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-pin-40-41-power-layout.png
        :name: fig-pcb-pin-40-41-power-layout
        :align: center
        :width: 50%
        :alt: {IDF_TARGET_NAME} Power Traces for Pins 40 and 41

        {IDF_TARGET_NAME} Power Traces for Pins 40 and 41

.. only:: esp32c61 or esp32c6

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-pin-2-3-power-layout.png
        :name: fig-pcb-pin-2-3-power-layout
        :align: center
        :width: 50%
        :alt: {IDF_TARGET_NAME} Power Traces for Pins 2 and 3

        {IDF_TARGET_NAME} Power Traces for Pins 2 and 3

.. list::

    :not esp32c61: - In Figure :ref:`fig-power-layout-four-layer`, the 10 µF capacitor is shared by the analog power supply {IDF_TARGET_ANALOG_POWER_TRACE}, and the power entrance since the analog power is close to the chip power entrance. If the chip power entrance is not near {IDF_TARGET_ANALOG_POWER_TRACE}, it is recommended to add a 10 µF capacitor to both the chip power entrance and {IDF_TARGET_ANALOG_POWER_TRACE}.
    - Place appropriate decoupling capacitors at the rest of the power pins. Ground vias should be added close to the capacitor's ground pad to ensure a short return path.
    - The ground pad at the bottom of the chip should be connected to the ground plane through at least nine ground vias.
    - The ground pads of the chip and surrounding circuit components should make full contact with the ground copper pour rather than being connected via traces.
    - If you need to add a thermal pad EPAD under the chip on the bottom of the module, it is recommended to employ a square grid on the EPAD, cover the gaps with solder paste, and place ground vias in the gaps, as shown in Figure :ref:`fig-power-layout-four-layer`. This helps effectively reduce solder leakage issues when soldering the module EPAD to the substrate.
    :esp32c5 or esp32s3: - For optimal grounding, connect the EPAD to a large external ground area using wide traces or copper planes. See the figure below.
    :esp32c2 or esp32c3: - For optimal grounding, connect the EPAD to a large external ground area using wide traces or copper planes.

.. only:: esp32c5 or esp32s3

    .. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-epad-layout.png
        :name: fig-pcb-epad-layout
        :align: center
        :width: 50%
        :alt: {IDF_TARGET_NAME} EPAD Design at Chip Bottom

        {IDF_TARGET_NAME} EPAD Design at Chip Bottom
