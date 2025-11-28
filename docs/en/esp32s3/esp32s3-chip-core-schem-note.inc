Note that Figure :ref:`fig-chip-core-schematic` shows the connection for 3.3 V, quad, off-package SPI flash/PSRAM.

- In cases where 1.8 V or 3.3 V, octal, in-package or off-package SPI flash/PSRAM is used, GPIO33 ~ GPIO37 are occupied and cannot be used for other functions.
- If an in-package SPI flash/PSRAM is used and VDD_SPI is configured to 1.8 V or 3.3 V via the VDD_SPI_FORCE eFuse, the GPIO45 strapping pin no longer affects the VDD_SPI voltage. In these cases, the presence of R1 is optional. For all other cases, refer to `{IDF_TARGET_NAME} Chip Series Datasheet <{IDF_TARGET_DATASHEET_EN_URL}#cd-pins-strap-vdd-spi>`__ > Section *VDD\_SPI Voltage Control* > Table *VDD_SPI Voltage Control* to determine whether R1 should be populated or not.
- The connection for 1.8 V, octal, off-package flash/PSRAM is as shown in Figure :ref:`fig-esp32-s3-core-sch-external-1v8-spi8`.
- When only in-package flash/PSRAM is used, there is no need to populate the resistor on the SPI traces or to care the SPI traces.

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/esp32s3-sche-ext-1v8-spi8.png
    :name: fig-esp32-s3-core-sch-external-1v8-spi8
    :align: center
    :width: 90%
    :alt: {IDF_TARGET_NAME} Schematic for Off-Package 1.8 V Octal Flash/PSRAM

    {IDF_TARGET_NAME} Schematic for Off-Package 1.8 V Octal Flash/PSRAM