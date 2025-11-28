{IDF_TARGET_NAME} series has only one SDIO slave controller that conforms to the industry-standard SDIO Specification Version 2.0. SDIO should be connected to specific GPIOs, namely SDIO_CMD/GPIO10, SDIO_CLK/GPIO9,  SDIO_DATA0/GPIO8, SDIO_DATA1/GPIO7, SDIO_DATA2/GPIO14, and SDIO_DATA3/GPIO13. Please add a pull-up resistor to these GPIOs, and preferably reserve a series resistor on each trace.

.. note::

    This peripheral is supported by the chip revision v1.0, but not by v0.1.
