.. _download-guidelines:

下载指导
==============
:link_to_translation:`en:[English]`

{IDF_TARGET_SPI_BOOT_PIN:default="to be defined", esp32="GPIO0", esp32s2="GPIO0", esp32s3="GPIO0", esp32c3="GPIO9", esp32c6="GPIO9", esp32h2="GPIO9", esp32c2="GPIO9", esp32c5="GPIO28", esp32c61="GPIO9"}

{IDF_TARGET_DOWNLOAD_FIRMWARE_METHOD: default="UART 和 USB", esp32="UART", esp32c2="UART", esp32s2="UART"}

{IDF_TARGET_NAME} 系列芯片/模组支持通过 {IDF_TARGET_DOWNLOAD_FIRMWARE_METHOD} 下载固件。

UART 下载的过程如下：

1. 烧录前，需要根据表 :ref:`tab-chip-boot-mode-control` 设置芯片/模组在 Joint Download Boot 模式。
2. 给芯片/模组上电，通过 UART0 串口查看是否进入 Joint Download Boot 模式。如果串口显示“waiting for download”，则表示已进入 Joint Download Boot 模式。
3. 通过 `Flash 下载工具 <https://www.espressif.com/zh-hans/support/download/other-tools?keys=>`__，选择 UART 方式将程序固件烧录进 flash 中。
4. 烧录结束后， {IDF_TARGET_SPI_BOOT_PIN} 可以悬空或者上拉切换至高电平，进入 SPI Boot 启动模式下工作。
5. 重新上电，芯片/模组初始化时会从 flash 中读取程序运行。

.. only:: not esp32 and not esp32c2 and not esp32s2

    USB 下载的过程如下：

    1. 如果 flash 中没有能正常运行的程序固件，烧录前，需要根据表 :ref:`tab-chip-boot-mode-control` 设置芯片/模组在 Joint Download Boot 模式。
    2. 给芯片/模组上电，通过 USB 接口查看是否进入 Joint Download Boot 模式。如果显示“waiting for download”，则表示已进入 Joint Download Boot 模式。
    3. 通过 `Flash 下载工具 <https://www.espressif.com/zh-hans/support/download/other-tools?keys=>`__，选择 USB 方式将程序固件烧录进 flash 中。
    4. 烧录结束后， {IDF_TARGET_SPI_BOOT_PIN} 可以悬空或者上拉切换至高电平，进入 SPI Boot 启动模式下工作。
    5. 重新上电，芯片/模组初始化时会从 flash 中读取程序运行。
    6. 如果 flash 中有能正常运行的程序固件，可以直接从步骤 3 开始 USB 自动下载。

.. note::

    .. list::

        - 建议看到 "waiting for download" 的信息后再进行下载。
        - 串口打印工具和烧录工具不能同时占用一个串口端口。

        .. only:: not esp32 and not esp32c2

            - 应用程序中如果出现以下情况，USB 自动下载功能将被禁用，必须通过配置 strapping 管脚进入 Joint Download Boot 启动模式，才能使用 USB 下载功能。

                - USB PHY 被应用程序关闭。
                - USB 被二次开发用于其他 USB 功能，例如 USB 主机、USB 标准设备。
                - USB 对应的 IO 管脚被用于其他外设功能，例如 UART、LEDC 等。

            - 建议用户保留对 strapping 管脚的控制，避免在出现以上情况时，USB 下载功能无法使用。