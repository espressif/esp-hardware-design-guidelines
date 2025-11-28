{IDF_TARGET_ANA_POWER_PIN_COLLAPSE: default="VDD3P3", esp32c6="VDDA3P3", esp32h2="VDD3P3 at pin1 and pin2", esp32c2="VDDA3P3"}

如果使用两层板设计，建议将 {IDF_TARGET_ANA_POWER_PIN_COLLAPSE} 的 CLC 滤波电路改成 CCL 结构，电感更靠近芯片效果会更好。详情可参考图 :ref:`fig-chip-analog-power-two-layer`。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-analog-power-two-layer.png
   :name: fig-chip-analog-power-two-layer
   :align: center
   :width: 70%
   :alt: {IDF_TARGET_NAME} 系列芯片模拟电源电路图（两层板）

   {IDF_TARGET_NAME} 系列芯片模拟电源电路图（两层板）
