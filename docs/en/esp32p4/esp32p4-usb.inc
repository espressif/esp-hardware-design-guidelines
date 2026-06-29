{IDF_TARGET_NAME} integrates a USB serial/JTAG controller that uses GPIO24 and GPIO25 as USB D- and USB D+ by default.

{IDF_TARGET_NAME} also features a USB 2.0 Full-Speed OTG peripheral with an integrated transceiver. By default, the USB 2.0 Full-Speed OTG uses GPIO26 and GPIO27 as USB D- and USB D+.

When using the USB serial/JTAG controller and USB 2.0 Full-Speed OTG, please note the following:

- The roles of the USB D- and USB D+ pins can be swapped.
- If only one function is in use, you can select either GPIO24/GPIO25 or GPIO26/GPIO27.
- If both functions are used simultaneously, GPIO24/GPIO25 and GPIO26/GPIO27 will serve as two separate pins for each function.

{IDF_TARGET_NAME} also features a USB 2.0 High-Speed OTG peripheral with an integrated transceiver, where DM and DP respectively serve as the USB D- and USB D+.

When using chip revisions v1.0 and v1.3 (**not recommended for new designs**), add a 1 MΩ pull-down resistor on the DP pin to reduce the large transient current on VDD_USBPHY when CHIP_PU is pulled low.

.. figure:: ../_static/esp32p4/esp32p4-usbphy-circuit-design-rev1.0-and-v1.3.png
  :align: center
  :width: 70%
  :alt: DP Pull-down Resistor (Chip Revisions v1.0 and v1.3)

  DP Pull-down Resistor (Chip Revisions v1.0 and v1.3)

In chip revisions v3.0 and later versions, this issue has been fixed, allowing the retention of a 1 MΩ pull-down resistor for design compatibility.

It is recommended to add a 22/33 Ω series resistor and optional ground capacitors on the D- and D+ lines of the USB 2.0 Full-Speed OTG. These components should be placed close to the chip end.

.. figure:: ../_static/esp32p4/USB-RC-circuit_20250228.png
    :name: fig-usb-rc
    :align: center
    :width: 50%
    :alt: ESP32-P4 USB RC Circuit

    ESP32-P4 USB RC Circuit

At the USB connector end, it is advisable to include ESD protection diodes. When using the USB 2.0 High-Speed OTG peripheral, the parasitic capacitance of the diode should not exceed 1 pF to avoid poor signal quality and unstable transmission.

{IDF_TARGET_NAME} also supports downloading via USB. For details, please refer to :ref:`download-guidelines`.
