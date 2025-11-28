{IDF_TARGET_NAME} series has only one SDIO slave controller that conforms to the industry-standard SDIO Specification Version 2.0.

SDIO should be connected to specific GPIOs, namely SDIO_CMD, SDIO_CLK,  SDIO_DATA0, SDIO_DATA1, SDIO_DATA2, and SDIO_DATA3. Please add a pull-up resistor to these GPIOs, and preferably reserve a series resistor on each trace.
