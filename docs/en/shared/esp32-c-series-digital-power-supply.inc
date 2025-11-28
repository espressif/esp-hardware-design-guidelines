{IDF_TARGET_VDD_POWER:default="VDD_SPI", esp32="VDD_SDIO"}

{IDF_TARGET_VDD_POWER_PIN:default="", esp32c5=" (pin29)", esp32c61=" (pin23)", esp32c6=" (pin23)"}

{IDF_TARGET_VDD_POWER_SOURCE:default="to be defined", esp32c3="VDD3P3_CPU", esp32c6="VDDPST2", esp32c5="VDDPST2", esp32c61="VDDPST2"}

{IDF_TARGET_VDD_POWER_CAP:default="to be defined", esp32c3="a 1 μF capacitor", esp32c6="0.1 μF and 1 μF capacitors", esp32c5="a 1 μF capacitor", esp32c61="a 1 μF capacitor"}

{IDF_TARGET_RSPI_VALUE:default="to be defined", esp32="6", esp32s2="5", esp32s3="14"}

{IDF_TARGET_PSRAM: default="to be defined", esp32c6="",esp32c5="/PSRAM", esp32c61="/PSRAM"}

Pin {IDF_TARGET_VDD_POWER}{IDF_TARGET_VDD_POWER_PIN} can serve as the power supply for the external device at 3.3 V (typical value), provided by {IDF_TARGET_VDD_POWER_SOURCE} via R\ :sub:`SPI`. Therefore, there will be some voltage drop from {IDF_TARGET_VDD_POWER_SOURCE}. When the {IDF_TARGET_VDD_POWER} outputs 3.3 V, it is recommended that users add {IDF_TARGET_VDD_POWER_CAP} close to {IDF_TARGET_VDD_POWER}.

{IDF_TARGET_VDD_POWER} can be connected to and powered by an external power supply.

When not serving as a power supply pin, {IDF_TARGET_VDD_POWER} can be used as a regular GPIO.

.. only:: esp32c5 or esp32c61 or esp32c6

    It is recommended to use the {IDF_TARGET_VDD_POWER} to power the in-package or off-package flash{IDF_TARGET_PSRAM}.

.. only:: esp32c5 or esp32c61 or esp32c6

{IDF_TARGET_PSRAM: default="to be defined", esp32c6="",esp32c5="/PSRAM", esp32c61="/PSRAM"}

    .. attention::

        When using {IDF_TARGET_VDD_POWER} as the power supply pin for the in-package flash/PSRAM or external 3.3 V flash{IDF_TARGET_PSRAM}, considering the voltage drop mentioned above, {IDF_TARGET_VDD_POWER_SOURCE} should be 3.0 V or above, so as to meet the requirements of flash{IDF_TARGET_PSRAM}'s working voltage.


.. only:: not esp32c5 and not esp32c61 and not esp32c6

    .. attention::

        When using {IDF_TARGET_VDD_POWER} as the power supply pin for the in-package flash or external 3.3 V flash, the supply voltage should be 3.0 V or above, so as to meet the requirements of flash's working voltage. In such cases, {IDF_TARGET_VDD_POWER} cannot be used as a regular GPIO.
