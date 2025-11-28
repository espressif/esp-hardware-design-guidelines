.. _pcb-layout-design:

PCB Layout Design
=================
:link_to_translation:`zh_CN:[中文]`

This chapter introduces the key points of how to design an ESP32-P4 PCB layout using an ESP32-P4 development board as an example.

General Principles of PCB Layout for the Chip
---------------------------------------------

Considering the communication quality of high-speed signal lines and potential interference with the RF module, please use at least a four-layer PCB design, as follows:

- Layer 1 (TOP): Signal traces and components.
- Layer 2 (GND): No signal traces here to ensure a complete GND plane.
- Layer 3 (POWER): Route power traces here. If possible, route high-speed signal traces here and ensure a complete reference plane.
- Layer 4 (BOTTOM): Route some signal traces here.

.. _general-guidelines:

General Guidelines
^^^^^^^^^^^^^^^^^^^^^^^

- Whenever possible, route the power traces on the inner layers (not the ground layer) and connect them to the chip pins through vias. Ensure the power traces are surrounded by ground copper.
- The trace width for the 3.3 V main power supply should be at least 25 mil.
- For the power traces of VDD_LP, VDD_IO_0, VDD_IO_4, VDD_IO_5 and VDD_IO_6, use a trace width of at least 10 mil. Place a 10 µF capacitor at the power entry point for this series of power supply and a 0.1 µF capacitor for each power pin.
- The trace width for the main power supply traces of VDD_HP_0, VDD_HP_2, and VDD_HP_3 should be at least 20 mil. Place a 10 µF capacitor at the power entry point for this series of power supply and a 0.1 µF capacitor for each power pin.
- For VDD_LDO and VDD_DCDCC, which handle higher current, use a trace width of at least 20 mil and place a 10 µF capacitor close to each power pin.
- It is recommended to use a star routing method to distribute power traces to each power pin.
- Because the VDD_HP power supply is by default fully controlled internally by ESP32-P4, the external DCDC should be placed close to the chip to ensure that the input, output, and feedback loops are as short as possible.

.. _crystal-layout:

Crystal
--------

Figure :ref:`fig-crystal` shows a reference PCB layout of crystal design.

    .. figure:: ../_static/esp32p4/esp32p4-pcb-crystal.png
        :name: fig-crystal
        :align: center
        :width: 70%
        :alt: ESP32-P4 Crystal Layout

        ESP32-P4 Crystal Layout

The layout of the crystal should follow the guidelines below:

- Ensure a complete GND plane for the crystal and chip.
- The crystal should be placed far from the clock pin to avoid interference on the chip. The gap should be at least 4.5 mm. It is good practice to add high-density ground vias stitching around the clock trace for better isolation.
- There should be no vias for the clock input and output traces.
- Components in series to the crystal trace should be placed close to the chip side.
- The external matching capacitors should be placed on the two sides of the crystal, preferably at the end of the clock trace, but not connected directly to the series components. This is to make sure the ground pad of the capacitor is close to that of the crystal.
- Do not route high-frequency digital signal traces under the crystal. It is recommended not to route any signal trace under the crystal. The vias on the power traces on both sides of the crystal clock trace should be placed as far away from the clock trace as possible, and the two sides of the clock trace should be surrounded by ground copper.
- As the crystal is a sensitive component, do not place any magnetic components nearby that may cause interference, for example large inductance component, and ensure that there is a complete large-area ground plane around the crystal.

USB
---

The USB layout should meet the following guidelines:

- Reserve space for resistors and capacitors on the USB traces close to {IDF_TARGET_NAME}.
- Use differential pairs with a differential impedance of 90 Ω with a tolerance of ±10%. Use differential pairs and route them in parallel at equal lengths.
- USB differential traces should minimize via transitions as much as possible to ensure better impedance control and avoid signal reflections. If vias are necessary, add a pair of ground return vias at each transition point.
- Ensure there is a continuous reference layer (a ground layer is recommended) beneath the USB traces.
- Surround the USB traces with ground copper.

SDIO
----

The SDIO layout should follow the guidelines below:

- Minimize parasitic capacitance of SDIO traces as they involve high-speed signals.
- The trace lengths for SDIO_CMD and SDIO_DATA0 ~ SDIO_DATA3 should be within ±50 mil of the SDIO_CLK trace length. Use serpentine routing if necessary.
- For SDIO routing, maintain a 50 Ω single-ended impedance with a tolerance of ±10%.
- Keep the total trace length from SDIO GPIOs to the master SDIO interface as short as possible, ideally within 2000 mil.
- Ensure that SDIO traces do not cross layers. Besides, a reference plane (preferably a ground plane) must be placed beneath the traces, and continuity of the reference plane must be ensured.
- It is recommended to surround the SDIO_CLK trace with ground copper.
- For multi-layer PCB designs, it is recommended to route SDIO traces to an inner layer through vias immediately after being drawn out from the chip. This helps minimize interference with high-speed signal lines. Add a pair of ground return vias at each via transition point.

Touch Sensor
------------

.. include:: esp32p4/esp32p4-touch-sensor-design.inc

Electrode Pattern
^^^^^^^^^^^^^^^^^^^^^

.. include:: esp32p4/esp32p4-touch-sensor-electrode-pattern.inc

PCB Layout
^^^^^^^^^^

.. include:: esp32p4/esp32p4-touch-sensor-pcb-layout.inc

Waterproof and Proximity Sensing Design
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. include:: esp32p4/esp32p4-touch-sensor-waterproof-design.inc

.. note::

    For more details on the hardware design of the touch sensor, please refer to `Touch Sensor Application Note <https://github.com/espressif/esp-iot-solution/blob/release/v1.0/documents/touch_pad_solution/touch_sensor_design_en.md>`_.

MIPI
----

.. figure:: ../_static/esp32p4/esp32p4-pcb-mipi-layout.png
        :name: fig-mipi-layout
        :align: center
        :width: 60%
        :alt: ESP32-P4 MIPI Layout

        ESP32-P4 MIPI Layout

The MIPI layout should follow the guidelines below:

- Minimize parasitic capacitance of MIPI traces as they involve high-speed signals.
- The impedance of MIPI differential lines should be controlled to 100 Ω, with a tolerance of ±10%.
- MIPI traces should be kept equal in length and spacing. The length difference between two MIPI traces in a pair should be minimized and kept within 10 mil; the length difference between different MIPI trace pairs should be minimized and kept within 30 mil. Use serpentine routing if necessary.
- It is recommended to surround MIPI trace pairs with ground copper. If this is not feasible, maintain a minimum spacing of 2W between MIPI trace pairs, where "W" is the width of the MIPI trace. For the MIPI CLK trace, surround it with ground copper.
- MIPI signal traces should be kept away from other high-speed and high-frequency signals (such as parallel data traces and clock traces) by at least 3W and must not run parallel to them. They should also be kept away from switching power sources and other sources of interference.
- Ensure there is a continuous reference layer (preferably a ground layer) below the MIPI signal traces.
- For multi-layer PCB designs, it is recommended to route MIPI traces to an inner layer through vias immediately after being drawn out from the chip. This helps minimize interference with high-speed signal lines. Ensure the MIPI CLK traces are surrounded by ground copper. Add a pair of ground return vias at each via transition point.
