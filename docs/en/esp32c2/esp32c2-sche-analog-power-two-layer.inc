{IDF_TARGET_ANA_POWER_PIN_COLLAPSE:default="VDD3P3", esp32c6="VDDA3P3", esp32h2="VDD3P3 at pin1 and pin2", esp32c2="VDDA3P3"}

If a two-layer board design is used, it is recommended to change the CLC filter circuit for {IDF_TARGET_ANA_POWER_PIN_COLLAPSE} to a CCL structure, as placing the inductance closer to the chip will yield better performance. Please refer to Figure :ref:`fig-chip-analog-power-two-layer` for details.

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-analog-power-two-layer.png
   :name: fig-chip-analog-power-two-layer
   :align: center
   :width: 70%
   :alt: {IDF_TARGET_NAME} Schematic for Analog Power Supply Pins (Two-layer Board)

   {IDF_TARGET_NAME} Schematic for Analog Power Supply Pins (Two-layer Board)
