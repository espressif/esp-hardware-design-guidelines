Note that Figure :ref:`fig-chip-core-schematic` shows the connection method for quad 3.3 V external flash/PSRAM.

- The SCLK for PSRAM can be assigned to any available GPIO (configured by software). It is recommended to use GPIO17, or share the clock line with flash, i.e., SD_CLK.
- When using ESP32-D0WDR2-V3 (with in-package quad 3.3 V PSRAM), the connection method for external flash is as shown in :ref:`fig-chip-core-schematic`. GPIO16 needs a pull-up resistor, with a typical value of 10 kΩ.
- When using a module with built-in ESP32-D0WDR2-V3, since VDD_SDIO is not led out, the pull-up on GPIO16 needs to be connected to an external 3.3 V power supply. This will result in additional power consumption. If low power consumption is required, use a pull-up resistor of 1 MΩ at the maximum.
- When using ESP32-U4WDH (with built-in quad 3.3 V flash), the internal flash connection is as shown in :ref:`fig-esp32-u4wdh-core-schematic`.
- When using in-package flash/PSRAM, there is no need to install resistors on the SPI traces, nor to pay special attention to the SPI traces.
- Whether R9 needs to be installed should be determined according to the `{IDF_TARGET_NAME} Chip Series Datasheet <{IDF_TARGET_DATASHEET_CN_URL}>`__ > Section *Internal LDO (VDD_SDIO) Voltage Control*.

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/esp32-sche-u4wdh-core.png
    :name: fig-esp32-u4wdh-core-schematic
    :align: center
    :width: 90%
    :alt: {IDF_TARGET_NAME} Schematic for Quad 3.3 V In-Package Flash

    {IDF_TARGET_NAME} Schematic for Quad 3.3 V In-Package Flash