- {IDF_TARGET_NAME} 的管脚 VDDPST_1 是电源输入管脚，与数字 LP 电源域相关，工作电压范围为 3.0 V ~ 3.6 V。建议在电路中靠近该电源管脚处添加 0.1 μF 电容。
- 管脚 VDDPST_3 和 VDDPST_4 是电源输入管脚，与数字 HP 电源域相关，工作电压范围为 3.0 V ~ 3.6 V。建议在电路中靠近这两个电源管脚处分别添加 0.1 μF 电容。
- 管脚 VCCA/VDDPST_2 是电源输入管脚，与 USB_PHY 和数字 HP 电源域相关，工作电压范围为 3.0 V ~ 3.6 V。建议在电路中靠近该电源管脚处添加 0.1 μF 电容。
- 管脚 VDD_SPI 是电源输入/输出管脚，与 flash 电源域相关，推荐使用 VDD_SPI 输出电源给封装外 flash 供电。建议靠近该电源管脚和 flash 处添加 0.1 μF 及 1 μF 去耦电容。

当前管脚 VDD_SPI 只能输出 3.3 V，同时请在 GPIO36 外部添加上拉电阻。

- 管脚 VDD_PSRAM_1P8_1 和 VDD_PSRAM_1P8_2 是电源输入管脚，与 PSRAM 电源域相关。建议在电路中靠近这两个电源管脚处分别添加 0.1 μF 及 1 μF 电容。
- 管脚 VDD_LDO_1P8 是电源输出管脚，可作为输出电源给封装内 PSRAM、封装外 flash 和内部 SD GPIO 使用。


推荐使用 VDD_LDO_1P8 输出电源给封装内 PSRAM 供电，即将 VDD_PSRAM_1P8_1 和 VDD_PSRAM_1P8_2 连接至 VDD_LDO_1P8。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-psram-power.png
    :name: fig-psram-power-circuit
    :align: center
    :width: 65%
    :alt: {IDF_TARGET_NAME} 系列芯片 PSRAM 电源电路图

    {IDF_TARGET_NAME} 系列芯片 PSRAM 电源电路图
