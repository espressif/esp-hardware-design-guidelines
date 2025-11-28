当一些 RTC 外设（SAR ADC1 或 SAR ADC2 或 AMP）的电源打开时， GPIO36 (SENSOR_VP) 和 GPIO39 (SENSOR_VN) 的数字输入会被拉低约 80 ns，因此，当⽤户决定把⽤于控制以上传感器的电源域打开时，应当忽略来⾃ GPIO36 和 GPIO39 的输⼊，或者优先考虑将 SENSOR_VP 及 SENSOR_VN 作为 ADC 使用。

目前 ADC2 不支持与 Wi-Fi 同时使用，优先推荐使用 ADC1。
