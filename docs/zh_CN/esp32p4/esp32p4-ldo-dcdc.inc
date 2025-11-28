{IDF_TARGET_NAME} 的管脚 VDD_LDO 为内部电压稳压器提供电源，工作电压范围为 3.0 V ~ 3.6 V。管脚 VDD_DCDCC 为 DCDC 控制部分提供电源，工作电压范围为 3.0 V ~ 3.6 V。因为管脚电流较大，请在 VDD_LDO 和 VDD_DCDCC 的电源走线上放置一个 10 μF 电容，再在各个管脚处添加 0.1 μF。

内部电压稳压器输出 VDDO_FLASH 给外部 flash 供电，默认输出 3.3 V 电压，可以通过烧写 EFUSE_0PXA_TIEH_SEL_0 使 VDDO_FLASH 输出 1.8 V。

.. note::

    在 eFuse 配置之前，VDDO_FLASH 默认输出 3.3 V 电压，此时接到 1.8 V flash 会有风险。因此，使用 1.8 V flash 时，建议在 VDDO_FLASH 和 VDD_FLASHIO 之间加一个跳帽，直到 VDDO_FLASH 电压确认为 1.8 V 之后再供电给 flash。

.. flat-table:: VDDO_FLASH 电压控制
    :name: tab-vdd-flash-voltage-control
    :header-rows: 1
    :widths: 1 2 3

    * - VDDO_FLASH 电源
      - EFUSE\_0PXA\_TIEH\_SEL\_0
      - 电压
    * - :rspan:`2` flash 稳压器
      - 0
      - 3.3 V
    * - 2
      - 1.8 V

内部电压稳压器输出 VDDO_PSRAM 给内部 PSRAM 供电，输出典型值为 1.9 V 电压，需要软件配置，默认输出 0。

内部电压稳压器输出 VDDO_3/4 给外设供电，最大输出电流50 mA，输出电压范围为 0.5 V ~ 2.7 V/3.3 V，需要软件配置，默认输出 0。

软件配置请参考 `低压差线性稳压器 (LDO) <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32p4/api-reference/peripherals/ldo_regulator.html>`__。

建议在电路中靠近 VDDO_FLASH、VDDO_PSRAM、VDDO_3/4 电源管脚处添加 1 μF。

VDD_HP_0/2/3 系列电源由外部 DCDC 供电，其中：

- 外部 DCDC 的输入和 VDD_DCDCC 电源一致。
- 管脚 EN_DCDC 为外部 DCDC 的使能管脚。在下载模式和没有固件的情况下，EN_DCDC 电压为 0。正常启动固件后，EN_DCDC 由内部控制。在下载模式下，EN_DCDC 电压为 0。在睡眠模式下，可以通过管脚 EN_DCDC 关闭该系列的电源从而降低功耗。
- 管脚 FB_DCDC 为外部 DCDC 的反馈管脚。
- EN_DCDC 和 FB_DCDC 默认由 ESP32-P4 内部完全控制，因此两个管脚请悬空。可以预留反馈电阻和反馈电容，但是请不要上件，注意 DCDC 需要靠近 ESP32-P4 放置。

请使用验证过的 DCDC 型号：ETA3485/SY8088/RY3420/TLV62569。输入、输出和电感参数请按照具体的规格书设计，下图为 TLV62569 的电路设计。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/ESP32-P4-TLV62569_20250403.png
  :align: center
  :width: 150%
  :alt: TLV62569 电路参考设计

  TLV62569 电路参考设计
