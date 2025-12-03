The VDD_LDO of {IDF_TARGET_NAME} provides power for the low dropout regulators (LDOs). The operating voltage ranges from 3.0 V to 3.6 V. VDD_DCDCC provides power for DCDC. The operating voltage ranges from 3.0 V to 3.6 V. Due to the high current on these pins, place a 10 μF capacitor on the power traces of VDD_LDO and VDD_DCDCC, and add a 0.1 μF capacitor at each pin.

The LDO outputs VDDO_FLASH to power the external flash. The default output is 3.3 V, but it can be configured to 1.8 V by programming EFUSE_0PXA_TIEH_SEL_0.

.. note::

    When using a 1.8 V SPI flash, it is recommended to disconnect the power connection between VDDO_FLASH and the SPI flash until the VDDO_FLASH output voltage has been correctly configured to 1.8 V, to prevent damage to the 1.8 V flash caused by excessive supply voltage.

    If this solution is intended for mass production, please contact sales for further support.

.. flat-table:: VDDO_FLASH Voltage
    :name: tab-vdd-flash-voltage-control
    :header-rows: 1
    :widths: 1 2 3

    * - Power
      - EFUSE\_0PXA\_TIEH\_SEL\_0
      - Voltage
    * - :rspan:`2` flash LDO
      - 0
      - 3.3 V
    * - 2
      - 1.8 V

The LDO outputs VDDO_PSRAM to power the in-package PSRAM. The typical output voltage is 1.9V, which requires software configuration. The default output is 0.

The LDO outputs VDDO_3/4 to power the peripherals. The maximum output current is 50 mA. The output voltage ranges from 0.5V to 2.7V/3.3V, which also requires software configuration. The default output is 0.

For software configuration, please refer to `Low Dropout Linear Regulator (LDO) <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32p4/api-reference/peripherals/ldo_regulator.html>`__.

It is recommended to place a 1 μF capacitor near the VDDO_FLASH, VDDO_PSRAM, and VDDO_3/4 in the circuit.

The VDD_HP_0/1/2/3 is powered by an external DC-DC converter (DCDC), with the following details:

- The input of the external DCDC is the same as the VDD_DCDCC power supply.
- EN_DCDC is the enable pin of the external DCDC. In download mode or when there is no firmware, the voltage on EN_DCDC is 0. After the firmware starts normally, EN_DCDC is controlled internally. In download mode, the EN_DCDC voltage remains at 0. In sleep mode, this pin can be used to disable the power supply to reduce power consumption.
- FB_DCDC is the feedback pin of the external DCDC.
- EN_DCDC and FB_DCDC pins are fully controlled by the internal circuitry of ESP32-P4 by default. Ensure that they are connected to the EN and FB pins of the external DCDC, respectively, and that the DCDC regulator is placed close to the ESP32-P4. When designing the layout for chip revisions v1.0 and v1.3 (**not recommended for new designs**), you must reserve pad locations for the feedback resistor and feedback capacitor (components not required), For chip revisions v3.0 and later versions, the feedback resistor and the feedback capacitor must be populated.

Please use verified DCDC models: ETA3485, SY8088, RY3420, or TLV62569. The input/output specifications and inductor parameters should follow the respective datasheets. Below is the circuit design for TLV62569.

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/esp32p4-TLV62569-rev3.0-and-later.png
  :align: center
  :width: 150%
  :alt: TLV62569 Schematic (Chip Revisions v3.0 and Later)

  TLV62569 Schematic (Chip Revisions v3.0 and Later)

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/esp32p4-TLV62569-rev1.0-and-v1.3.png
  :align: center
  :width: 150%
  :alt: TLV62569 Schematic (Chip Revisions v1.0 and v1.3)

  TLV62569 Schematic (Chip Revisions v1.0 and v1.3)
