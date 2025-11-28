.. _download-guidelines:

Download Guidelines
======================
:link_to_translation:`zh_CN:[中文]`

{IDF_TARGET_SPI_BOOT_PIN:default="to be defined", esp32="GPIO0", esp32s2="GPIO0", esp32s3="GPIO0", esp32c3="GPIO9", esp32c6="GPIO9", esp32h2="GPIO9", esp32c2="GPIO9", esp32c5="GPIO28", esp32c61="GPIO9"}

{IDF_TARGET_DOWNLOAD_FIRMWARE_METHOD: default="UART and USB", esp32="UART", esp32c2="UART", esp32s2="UART"}

You can download firmware to {IDF_TARGET_NAME} via {IDF_TARGET_DOWNLOAD_FIRMWARE_METHOD}.

To download via UART:

1. Before the download, make sure to set the chip or module to Joint Download Boot mode, according to Table :ref:`tab-chip-boot-mode-control`.
2. Power up the chip or module and check the log via the UART0 serial port. If the log shows “waiting for download”, the chip or module has entered Joint Download Boot mode.
3. Download your firmware into flash via UART using the `Flash Download Tool <https://www.espressif.com/en/support/download/other-tools?keys=>`__.
4. After the firmware has been downloaded, pull {IDF_TARGET_SPI_BOOT_PIN} high or leave it floating to make sure that the chip or module enters SPI Boot mode.
5. Power up the chip or module again. The chip will read and execute the new firmware during initialization.

.. only:: not esp32 and not esp32c2 and not esp32s2

    To download via USB:

    1. If the flash is empty, set the chip or module to Joint Download Boot mode, according to Table :ref:`tab-chip-boot-mode-control`.
    2. Power up the chip or module and check the log via USB serial port. If the log shows “waiting for download”, the chip or module has entered Joint Download Boot mode.
    3. Download your firmware into flash via USB using `Flash Download Tool <https://www.espressif.com/en/support/download/other-tools?keys=>`__.
    4. After the firmware has been downloaded, pull {IDF_TARGET_SPI_BOOT_PIN} high or leave it floating to make sure that the chip or module enters SPI Boot mode.
    5. Power up the chip or module again. The chip will read and execute the new firmware during initialization.
    6. If the flash is not empty, start directly from Step 3.

.. note::

    .. list::

        - It is advised to download the firmware only after the "waiting for download" log shows via the serial port.
        - Serial tools cannot be used simultaneously with the Flash Download Tool on one COM port.

        .. only:: not esp32 and not esp32c2

            - The USB auto-download will be disabled if the following conditions occur in the application, where it will be necessary to set the chip or module to Joint Download Boot mode first by configuring the strapping pin.

                - USB PHY is disabled by the application;
                - USB is secondary developed for other USB functions, e.g., USB host, USB standard device;
                - USB IOs are configured to other peripherals, such as UART and LEDC.

            - It is recommended that the user retains control of the strapping pins to avoid the USB download function not being available in case of the above scenario.
