.. list-table:: 修订历史
   :header-rows: 1
   :widths: 2 1 7

   * - 日期
     - 版本
     - 发布说明
   * - 2026-02-04
     - v1.4
     - - :doc:`../schematic-checklist-esp32p4`
           - 概述章节：补充说明芯片版本 v1.0/v1.3（不推荐用于新设计）与 v3.0 及之后版本之间的主要差异，并更新对应的参考设计原理图
           - 章节 :ref:`p4-power-supply`：修改基本供电电流值
           - 章节 :ref:`usb-phy-power-supply`：增加使用 DP 和 DM 时的注意事项，增加 VDD_USBPHY 电路参考设计图
           - 章节 :ref:`p4-analog-power-supply`：修改管脚 VDD_BAT 的工作电压范围
           - 章节 :ref:`internal-voltage-regulators`：更新关于 VDDO_FLASH 输出电压配置的备注，和不同芯片版本布局电路时的注意事项，增加对应的 TLV62569 电路参考设计图
           - 章节 :ref:`esp32p4-sdio`：更新 SDIO GPIO 管脚分配说明，修正图 :ref:`esp32p4-sd3-card-power-circuit` 里的一处笔误
           - 章节 :ref:`esp32p4-usb`：增加 DP 管脚处添加下拉电阻的说明（适用于芯片版本 v1.0 和 v1.3）
           - 章节 :ref:`schematic-checklist-ethernet-mac`：修正 EMAC 信号 RMII_RXDV 为 RMII_CRSDV
       - :doc:`../pcb-layout-design-esp32p4`
           - 章节 :ref:`general-guidelines`：补充说明 VDD_BAT 和 VDD_ANA 管脚的电源走线建议至少 10 mil
       - :doc:`related-documentation-and-resources`：增加管脚总览 Excel
   * - 2025-11-28
     - v1.3
     - - :doc:`../schematic-checklist-esp32p4`
           - 章节 :ref:`internal-voltage-regulators`：更新 FB_DCDC 和 EN_DCDC 相关的说明
   * - 2025-09-22
     - v1.2
     - - :doc:`../schematic-checklist-esp32p4`
           - 章节 :ref:`internal-voltage-regulators`：新增关于 VDDO_FLASH 默认电压及 1.8 V flash 使用注意事项的说明
   * - 2025-07-07
     - v1.1
     - - :doc:`../schematic-checklist-esp32p4`
           - 章节 :ref:`hp-lp-power-supply`：新增 VDD_IO_5 相关的说明
           - 章节 :ref:`mipi-phy-power-supply`：更新 VDD_MIPI_DPHY 相关的描述，增加 MIPI 信号电平相关的说明
           - 章节 :ref:`internal-voltage-regulators`：更新 FB_DCDC 和 EN_DCDC 相关的描述
           - 章节 :ref:`esp32p4-sdio`：新增图 :ref:`esp32p4-sd3-card-power-circuit`
       - :doc:`../pcb-layout-design-esp32p4`
           - 章节 :ref:`general-guidelines`：删除 VDD_FLASHIO 电源走线相关的描述，更新 DCDC 放置相关的描述
   * - 2025-04-23
     - v1.0
     - 首次发布《{IDF_TARGET_NAME} 硬件设计指南》。
