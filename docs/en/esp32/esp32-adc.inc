When RTC peripherals (SAR ADC1/SAR ADC2/AMP) is powered on, the inputs of GPIO36 (SENSOR_VP) and GPIO39 (SENSOR_VN) will be pulled down for approximately 80 ns. If SENSOR_VP and SENSOR_VN are used as GPIOs in the design, while ADC is supported by other pins, then software should disregard the glitch. Optionally,  use SENSOR_VP and SENSOR_VN as ADC pins.

ADC1 is recommended over ADC2 as the latter cannot be used when Wi-Fi function is enabled.

