{IDF_TARGET_NAME} 系列芯片集成一个 USB 串口/JTAG 控制器，默认使用 GPIO24 和 GPIO25 作为 USB 的 D- 和 D+。

{IDF_TARGET_NAME} 系列芯片带有一个集成了收发器的全速 USB On-The-Go (OTG) 外设，符合 USB 2.0 规范，默认使用 GPIO26 和 GPIO27 作为 USB 的 D- 和 D+。

使用 USB 串口/JTAG 控制器和全速 USB On-The-Go (OTG) 外设时，请注意：

  - USB 的 D- 和 D+ 管脚功能可以互换。
  - 使用单个功能时，可以选择 GPIO24/GPIO25 和 GPIO26/GPIO27 其中任意一组。
  - 同时使用两个功能时，GPIO24/GPIO25 和 GPIO26/GPIO27 各自作为一个功能的两个管脚使用。

{IDF_TARGET_NAME} 系列芯片带有一个集成了收发器的高速 USB On-The-Go (OTG) 外设，符合 USB 2.0 规范，DM 和 DP 分别作为 USB 的 D- 和 D+。

全速 USB 的 D- 和 D+ 线上建议预留串联电阻（初始值可为 22/33 Ω）和对地电容（初始可不上件），并注意靠近芯片端放置。

.. figure:: ../_static/esp32p4/USB-RC-circuit_20250228.png
    :name: fig-usb-rc
    :align: center
    :width: 50%
    :alt: ESP32-P4 系列芯片 USB RC 电路图

    ESP32-P4 系列芯片 USB RC 电路图

建议在 USB 连接器端预留 ESD 保护二极管。当使用高速 USB OTG 外设时，请注意 ESD 保护二极管的寄生电容不能超过 1 pF，否则会导致信号质量较差，传输不稳定。

{IDF_TARGET_NAME} 系列芯片也支持通过 USB 进行下载，请参考 :ref:`download-guidelines`。
