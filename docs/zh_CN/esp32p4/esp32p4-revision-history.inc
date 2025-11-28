.. list-table:: 修订历史
   :header-rows: 1
   :widths: 2 1 7

   * - 日期
     - 版本
     - 发布说明
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
