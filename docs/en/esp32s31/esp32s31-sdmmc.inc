{IDF_TARGET_NAME} series chips integrate one SD/SDIO/MMC host controller (cannot be used as a slave). The SD/MMC host peripheral has two slots that can be used to insert SD cards, connect SDIO devices, or connect eMMC chips. Each slot can be used independently.

- Slot 1 (SDMMC_HOST_SLOT_0) signals are routed via IO MUX using GPIO20 ~ GPIO25, and support SD 3.0 with 1.8 V/3.3 V automatic switching inside the chip.
- Slot 2 (SDMMC_HOST_SLOT_1) signals are routed via IO MUX using GPIO35 ~ GPIO40.

.. list-table:: SD/MMC GPIO Definition
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

When using slot0, the GPIO power domain is internally powered, so external pull-up resistors are not required. It is recommended to place a series resistor on each signal line and reserve a capacitor to ground on the CLK line for potential debugging and signal tuning. In addition, if 1-bit mode is used, the unused pins must not be repurposed for other functions.

When using slot1, please add pull-up resistors to the GPIO pins. It is also recommended to place a series resistor on each signal line and reserve a capacitor to ground on the CLK line for potential debugging and signal tuning.
