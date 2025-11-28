{IDF_TARGET_POWER_TRACE_WIDTH:default="25", esp32c3="20", esp32c2="20", esp32h2="20", esp32c5="35"}

{IDF_TARGET_ANALOG_POWER_TRACE:default="VDD3P3", esp32c6="VDDA3P3", esp32c2="VDDA3P3", esp32h2="VDD3P3 at pin1 and pin2", esp32s2="VDD3P3 at pin3 and pin4", esp32c5="VDDA6, VDDA7, VDDA1, and VDDA2 at pin1, pin3, pin40, and pin41", esp32s3="VDD3P3 at pin2 and pin3"}

{IDF_TARGET_ANALOG_POWER_TRACE_WIDTH:default="20", esp32c3="15", esp32c2="15", esp32h2="15"}

{IDF_TARGET_ANALOG_FILTER_CIRCUIT:default="CLC", esp32c3="LC", esp32c2="LC"}

{IDF_TARGET_RF_POWER_TRACE:default="pin2 and pin3", esp32c5="pin1, pin3, pin40, and pin41"}

Figure :ref:`fig-power-layout-four-layer` shows the overview of the power traces in a four-layer PCB design.

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-pcb-power-layout.png
    :name: fig-power-layout-four-layer
    :align: center
    :width: 60%
    :alt: {IDF_TARGET_NAME} Power Traces in a Four-layer PCB Design

    {IDF_TARGET_NAME} Power Traces in a Four-layer PCB Design

General Guidelines
^^^^^^^^^^^^^^^^^^^^^^^

- Four-layer PCB design is preferred.
- The power traces should be routed on the inner third layer whenever possible.
- Vias are required for the power traces to go through the layers and get connected to the pins on the top layer. There should be at least two vias if the main power traces need to cross layers. The drill diameter on other power traces should be no smaller than the width of the power traces.
- The ground pad at the bottom of the chip should be connected to the ground plane through at least nine ground vias.
- If you need to add a thermal pad EPAD under the chip on the bottom of the module, it is recommended to employ a square grid on the EPAD, cover the gaps with solder paste, and place ground vias in the gaps, as shown in Figure :ref:`fig-power-layout-four-layer`. This can avoid chip displacement caused by tin leakage and bubbles when soldering the module EPAD to the substrate.

3.3 V Power Layout
^^^^^^^^^^^^^^^^^^^^^^^

The 3.3 V power traces, highlighted in yellow, are routed as shown in Figure :ref:`fig-power-layout-four-layer`.

The 3.3 V power layout should meet the following guidelines:

- The ESD protection diode is placed next to the power port (circled in red in Figure :ref:`fig-power-layout-four-layer`). The power trace should have a 10 µF capacitor on its way before entering into the chip, and a 0.1 µF or 1 µF capacitor could also be used in conjunction. After that, the power traces are divided into several branches using a star-shaped topology, which reduces the coupling between different power pins. Note that all decoupling capacitors should be placed close to the corresponding power pin, and ground vias should be added close to the capacitor's ground pad to ensure a short return path.
- In Figure :ref:`fig-power-layout-four-layer`, the 10 µF capacitor is shared by the analog power supply {IDF_TARGET_ANALOG_POWER_TRACE}, and the power entrance since the analog power is close to the chip power entrance. If the chip power entrance is not near {IDF_TARGET_ANALOG_POWER_TRACE}, it is recommended to add a 10 µF capacitor to both the chip power entrance and {IDF_TARGET_ANALOG_POWER_TRACE}. Also, reserve two 1 µF capacitors if space permits.
- The width of the main power traces should be no less than {IDF_TARGET_POWER_TRACE_WIDTH} mil. The width of {IDF_TARGET_ANALOG_POWER_TRACE} power traces should be no less than {IDF_TARGET_ANALOG_POWER_TRACE_WIDTH} mil. The recommended width of other power traces is 10 mil.

Analog Power Layout
^^^^^^^^^^^^^^^^^^^^^^^^

The analog power layout should meet the following guidelines:

.. list::

    :esp32s3 or esp32c3 or esp32c6 or esp32c2: - As shown in Figure :ref:`fig-analog-power-layout`, it is recommended to connect the capacitor to ground in the {IDF_TARGET_ANALOG_FILTER_CIRCUIT} filter circuit near {IDF_TARGET_ANALOG_POWER_TRACE} to the fourth layer through a via, and maintain a keep-out area on other layers. The purpose is to further reduce harmonic interference.
    - {IDF_TARGET_ANALOG_POWER_TRACE} analog power supply should be surrounded by ground copper. It is required to add GND isolation between {IDF_TARGET_ANALOG_POWER_TRACE}, power trace and the surrounding GPIO and RF traces, and place vias whenever possible.