When USB-OTG Download Boot mode is enabled, the chip initializes the IO pad connected to the external PHY in ROM when starts up. The status of each IO pad after initialization is as follows.

.. _IO Pad Status After Chip Initialization in the USB-OTG Download Boot Mode:

.. list-table:: IO Pad Status After Chip Initialization in the USB-OTG Download Boot Mode
   :header-rows: 1
   :widths: 30 40 30
   :align: center

   * - IO Pad
     - Input/Output Mode
     - Level Status
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

If the USB-OTG Download Boot mode is not needed, it is suggested to disable the USB-OTG Download Boot mode by setting the eFuse bit EFUSE_DIS_USB_OTG_DOWNLOAD_MODE to avoid IO pad state change.