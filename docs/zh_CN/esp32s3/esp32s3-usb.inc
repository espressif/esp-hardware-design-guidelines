在启用 USB-OTG Download Boot 模式时，芯片上电后会在 ROM 中初始化用于连接外部 PHY 的 IO 焊盘，初始化后各 IO 焊盘状态如下：

.. _IO Pad Status After Chip Initialization in the USB-OTG Download Boot Mode:

.. list-table:: USBOTG Download Boot 模式下芯片初始化后 IO 焊盘状态
   :header-rows: 1
   :widths: 30 40 30
   :align: center

   * - IO 焊盘
     - 输入/输出模式
     - 电平状态
   * - VP (MTMS)
     - INPUT
     - –
   * - VM (MTDI)
     - INPUT
     - –
   * - RCV (GPIO21)
     - INPUT
     - –
   * - OEN (MTDO)
     - OUTPUT
     - HIGH
   * - VPO (MTCK)
     - OUTPUT
     - LOW
   * - VMO(GPIO38)
     - OUTPUT
     - LOW

若无需使用 USB-OTG Download Boot 模式, 可烧写 eFuse 位 EFUSE_DIS_USB_OTG_DOWNLOAD_MODE 禁用该模式，以避免 IO 状态的变化。