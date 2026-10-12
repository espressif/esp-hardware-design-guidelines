{IDF_TARGET_NAME} 系列芯片集成一个 SD/SDIO/MMC 主机控制器，不能作为从机。该 SD/MMC 主机外设共有两个卡槽 (slot)，用于插入 SD 卡、连接 SDIO 设备或连接 eMMC 芯片，每个卡槽均可独立使用。

- 卡槽 1 (SDMMC_HOST_SLOT_0) 的信号通过 IO MUX 使用 GPIO20 ~ GPIO25，支持 SD 3.0 版本，1.8 V/3.3 V 在芯片内部自动切换。
- 卡槽 2 (SDMMC_HOST_SLOT_1) 的信号通过 IO MUX 使用 GPIO35 ~ GPIO40。

.. list-table:: SD/MMC GPIO 定义
    :name: tab-sdmmc-gpio
    :header-rows: 1
    :widths: 14 14 14 14 14 14 14
    :align: center

    * -
      - DATA0
      - DATA1
      - DATA2
      - DATA3
      - CLK
      - CMD
    * - SLOT0
      - GPIO20
      - GPIO21
      - GPIO22
      - GPIO23
      - GPIO24
      - GPIO25
    * - SLOT1
      - GPIO35
      - GPIO36
      - GPIO37
      - GPIO38
      - GPIO39
      - GPIO40

使用 slot0 时，因为 GPIO 电源域是内部电源，所以无需添加上拉，建议每根线上添加一个串联电阻，在 CLK 线上预留对地电容用于可能的调试。此外，如果使用 1 bit 模式，其他没有使用的管脚也不能再作为其他用处。

使用 slot1 时，请在 GPIO 管脚处添加上拉电阻，建议每根线上添加一个串联电阻，在 CLK 线上预留对地电容用于可能的调试。
