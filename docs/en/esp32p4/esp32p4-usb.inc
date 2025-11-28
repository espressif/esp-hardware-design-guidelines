{IDF_TARGET_NAME} integrates a USB serial/JTAG controller that uses GPIO24 and GPIO25 as USB D- and USB D+ by default.

{IDF_TARGET_NAME} also features an full-speed USB On-The-Go (OTG) peripheral with an integrated transceiver, compliant with USB 2.0 specifications. By default, the full-speed USB OTG uses GPIO26 and GPIO27 as USB D- and USB D+.

When using the USB serial/JTAG controller and full-speed USB OTG, please note the following:

- The roles of the USB D- and USB D+ pins can be swapped.
- If only one function is in use, you can select either GPIO24/GPIO25 or GPIO26/GPIO27.
- If both functions are used simultaneously, GPIO24/GPIO25 and GPIO26/GPIO27 will serve as two separate pins for each function.

{IDF_TARGET_NAME} also features a high-speed USB OTG peripheral with an integrated transceiver, compliant with USB 2.0 specifications, where DM and DP respectively serve as USB D- and USB D+.

It is recommended to add a 22/33 Ω series resistor and optional ground capacitors on the Full-speed USB D- and USB D+ lines. These components should be placed close to the chip end.

.. figure:: ../_static/esp32p4/USB-RC-circuit_20250228.png
    :name: fig-usb-rc
    :align: center
    :width: 50%
    :alt: ESP32-P4 USB RC Circuit

    ESP32-P4 USB RC Circuit

At the USB connector end, it is advisable to include ESD protection diodes. When using a high-speed USB OTG peripheral, the parasitic capacitance of the diode should not exceed 1 pF to avoid poor signal quality and unstable transmission.

{IDF_TARGET_NAME} also supports downloading via USB. For details, please refer to :ref:`schematic-checklist-strapping-pins`.
