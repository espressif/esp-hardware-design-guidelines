{IDF_TARGET_NAME} 系列芯片集成一个 SD/MMC 主机控制器，不能用做从机。该 SD/MMC 主机外设共有两个卡槽 (slot)，用于插入 SD 卡、连接 SDIO 设备或连接 eMMC 芯片，每个卡槽均可单独使用。

卡槽 1 (SDMMC_HOST_SLOT_0) 信号通过 IO MUX 固定在下表中的 GPIO 管脚，专用于 UHS-I 模式。

.. list-table:: 卡槽 1 (SDMMC_HOST_SLOT_0) 信号映射
   :header-rows: 1
   :widths: 15 10

   * - SDIO 信号
     - 管脚名称
   * - SD1\_CDATA0\_PAD
     - GPIO39
   * - SD1\_CDATA1\_PAD
     - GPIO40
   * - SD1\_CDATA2\_PAD
     - GPIO41
   * - SD1\_CDATA3\_PAD
     - GPIO42
   * - SD1\_CCLK\_PAD
     - GPIO43
   * - SD1\_CCMD\_PAD
     - GPIO44
   * - SD1\_CDATA4\_PAD
     - GPIO45
   * - SD1\_CDATA5\_PAD
     - GPIO46
   * - SD1\_CDATA6\_PAD
     - GPIO47
   * - SD1\_CDATA7\_PAD
     - GPIO48

卡槽 2 (SDMMC_HOST_SLOT_1) 信号通过 GPIO 交换矩阵可配置使用任意 GPIO 管脚，这适用于非 UHS-I 用途。

请在 SDIO GPIO 管脚处添加上拉电阻，建议每根线上预留一个串联的电阻，并在 SDIO CLK 线上预留对地的电容用于调节。

考虑到 SDIO 3.0 协议中 SDIO GPIO 工作电压自动切换的要求，建议把 SDIO GPIO 的电源域 VDD_IO_5 和外部上拉电源连接至 VDDO_4。SD 卡供电电源请连接至系统 3.3 V 电源。

.. figure:: ../_static/esp32p4/esp32p4-sd3-card-power-circuit.png
   :name: esp32p4-sd3-card-power-circuit
   :align: center
   :width: 95%
   :alt: ESP32-P4 SD 3.0 卡电源电路图

   ESP32-P4 SD 3.0 卡电源电路图

为了降低 SD 卡的功耗和复位 SD 卡，可以在 SD 卡电源处预留 MOS 管电路，通过 GPIO 来控制。
