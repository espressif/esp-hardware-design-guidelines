- Pin VDDPST_1 of {IDF_TARGET_NAME} is a power supply input pin associated with the digital LP power domain, with an operating voltage range of 3.0 V ~ 3.6 V. It is recommended to add a 0.1 μF capacitor close to this power supply pin in the circuit.
- Pins VDDPST_3 and VDDPST_4 are power supply input pins associated with the digital HP power domain, with an operating voltage range of 3.0 V ~ 3.6 V. It is recommended to add a 0.1 μF capacitor close to each of these power supply pins in the circuit.
- Pin VCCA/VDDPST_2 is a power supply input pin associated with USB_PHY and the digital HP power domain, with an operating voltage range of 3.0 V ~ 3.6 V. It is recommended to add a 0.1 μF capacitor close to this power supply pin in the circuit.
- Pin VDD_SPI is a power supply input/output pin associated with the flash power domain. It is recommended to use the VDD_SPI output power to supply the off-package flash. It is recommended to add 0.1 μF and 1 μF decoupling capacitors close to this power supply pin and the flash.

Currently, pin VDD_SPI can only output 3.3 V. Please add an external pull-up resistor on GPIO36.

- Pins VDD_PSRAM_1P8_1 and VDD_PSRAM_1P8_2 are power supply input pins associated with the PSRAM power domain. It is recommended to add 0.1 μF and 1 μF capacitors close to each of these power supply pins in the circuit.
- Pin VDD_LDO_1P8 is a power output pin that can be used to supply in-package PSRAM, off-package flash, and internal SD GPIO.

It is recommended to use the VDD_LDO_1P8 output power to supply the in-package PSRAM, that is, connect VDD_PSRAM_1P8_1 and VDD_PSRAM_1P8_2 to VDD_LDO_1P8.

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-psram-power.png
    :name: fig-psram-power-circuit
    :align: center
    :width: 65%
    :alt: {IDF_TARGET_NAME} Series Chip PSRAM Power Schematic

    {IDF_TARGET_NAME} Series Chip PSRAM Power Schematic
