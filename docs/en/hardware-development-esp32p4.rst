Hardware Development
==========================
:link_to_translation:`zh_CN:[中文]`

ESP32-P4 Development Boards
------------------------------------

For a list of the latest designs of {IDF_TARGET_NAME} boards please check the `Development Boards <https://www.espressif.com/en/products/hardware/development-boards>`_ section on Espressif's official website.

.. _download-guidelines:

Download Guidelines
-------------------

You can download firmware to ESP32-P4 series chips via UART and USB.

To download via UART:

1. Before the download, make sure to set the chip to Joint Download Boot mode, according to Table :ref:`tab-chip-boot-mode-control`.
2. Power up the chip and check the log via the UART0 serial port. If the log shows “waiting for download”, the chip has entered Joint Download Boot mode.
3. Download your firmware into flash via UART using the `Flash Download Tool <https://www.espressif.com/en/support/download/other-tools?keys=>`__.
4. After the firmware has been downloaded, pull GPIO35 high or leave it floating to make sure that the chip enters SPI Boot mode.
5. Power up the chip again. The chip will read and execute the new firmware during initialization.

To download via USB:

1. If the flash is empty, set the chip to Joint Download Boot mode, according to Table :ref:`tab-chip-boot-mode-control`.
2. Power up the chip and check the log via USB serial port. If the log shows “waiting for download”, the chip has entered Joint Download Boot mode.
3. Download your firmware into flash via USB using `Flash Download Tool <https://www.espressif.com/en/support/download/other-tools?keys=>`__.
4. After the firmware has been downloaded, pull GPIO35 high or leave it floating to make sure that the chip enters SPI Boot mode.
5. Power up the chip again. The chip will read and execute the new firmware during initialization.
6. If the flash is not empty, start directly from Step 3.

.. note::

    .. list::

        - It is advised to download the firmware only after the "waiting for download" log shows via the serial port.
        - Serial tools cannot be used simultaneously with the Flash Download Tool on one COM port.
        - The USB auto-download will be disabled if the following conditions occur in the application, where it will be necessary to set the chip to Joint Download Boot mode first by configuring the strapping pin.

            - USB PHY is disabled by the application.
            - USB is secondary developed for other USB functions, e.g., USB host, USB standard device.
            - USB IOs are configured to other peripherals, such as UART and LEDC.

        - It is recommended that the user retains control of the strapping pins to avoid the USB download function not being available in case of the above scenario.
