Related Documentation and Resources
=======================================
:link_to_translation:`zh_CN:[中文]`

.. _hardware-development-modules:

{IDF_TARGET_NAME} Modules
------------------------------

For a list of {IDF_TARGET_NAME} modules please check the `Modules <https://www.espressif.com/en/products/modules>`_ section on Espressif's official website.

.. only:: not esp32p4

    For module reference designs please refer to:

.. only:: latex

    - `Download links <https://docs.espressif.com/projects/esp-hardware-design-guidelines/en/latest/{IDF_TARGET_PATH_NAME}/hardware-development.html>`_

.. only:: esp32

    .. only:: html

        - :download:`ESP32-MINI-1 reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-mini-1_reference_design.zip>`
        - :download:`ESP32-WROOM-32E reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-wroom-32e_reference_design.zip>`
        - :download:`ESP32-WROVER-E reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-wrover-e_reference_design.zip>`

.. only:: esp32s3

    .. only:: html

        - :download:`ESP32-S3-MINI-1 reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-s3-mini-1_reference_design.zip>`
        - :download:`ESP32-S3-WROOM-1 reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-s3-wroom-1_reference_design.zip>`

.. only:: esp32c3

    .. only:: html

        - :download:`ESP32-C3-MINI-1 reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-c3-mini-1_reference_design.zip>`
        - :download:`ESP32-C3-WROOM-02 reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-c3-wroom-02_reference_design.zip>`

.. only:: esp32c6

    .. only:: html

        - :download:`ESP32-C6-MINI-1 reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-c6-mini-1_reference_design.zip>`
        - :download:`ESP32-C6-WROOM-1 reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-c6-wroom-1_reference_design.zip>`

.. only:: esp32h2

    .. only:: html

        - :download:`ESP32-H2-MINI-1 reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-h2-mini-1_reference_design.zip>`
        - :download:`ESP32-H2-WROOM-02C reference design <../_static/{IDF_TARGET_PATH_NAME}/esp32-h2-wroom-02c_reference_design.zip>`

.. only:: esp32c2

    .. only:: html

        - :download:`ESP8684-MINI-1 reference design <../_static/{IDF_TARGET_PATH_NAME}/esp8684-mini-1_reference_design.zip>`
        - :download:`ESP8684-WROOM-02C reference design <../_static/{IDF_TARGET_PATH_NAME}/esp8684-wroom-02c_reference_design.zip>`

.. only:: esp32c5

    .. only:: html

        - :download:`ESP32-C5-MINI-1-N4 Reference Design <../_static/{IDF_TARGET_PATH_NAME}/esp32-c5-mini-1-n4_reference_design.zip>`
        - :download:`ESP32-C5-WROOM-1-N8R8 Reference Design <../_static/{IDF_TARGET_PATH_NAME}/esp32-c5-wroom-1-n8r8_reference_design.zip>`

    The antenna design is for reference only. For actual projects, perform antenna simulations based on the PCB layout.

.. only:: not esp32p4

    .. note::

        Use the following tools to open the files in module reference designs:

            - .DSN files: OrCAD Capture V16.6
            - .pcb files: Pads Layout VX.2. If you cannot open the .pcb files, please try importing the .asc files into your software to view the PCB layout.

{IDF_TARGET_NAME} Development Boards
--------------------------------------------

For a list of the latest designs of {IDF_TARGET_NAME} boards please check the `Development Boards <https://www.espressif.com/en/products/hardware/development-boards>`_ section on Espressif's official website.

.. only:: esp32p4

    For development board reference designs please refer to:

    .. only:: html

        - :download:`ESP32-P4-Function-EV-Board V1.5.2 Reference Design (ZIP) <../_static/{IDF_TARGET_PATH_NAME}/ESP32-P4-Function-EV-Board_V1.5.2_EN.zip>`
        - :download:`ESP32-P4-EYE V2.3 Reference Design (ZIP) <../_static/{IDF_TARGET_PATH_NAME}/ESP32-P4-EYE-MB_V2.3_EN.zip>`

    .. note::

        Use the following tools to open the files in development board reference designs:

            - .DSN files: OrCAD Capture V16.6
            - .brd files: Allegro 16.6

Other Related Documentation and Resources
---------------------------------------------

.. list::

    - `Chip Datasheet (PDF) <{IDF_TARGET_DATASHEET_EN_URL}>`__
    - `Technical Reference Manual (PDF) <{IDF_TARGET_TRM_EN_URL}>`__
    :esp32: - `Chip Errata <https://espressif.com/sites/default/files/documentation/eco_and_workarounds_for_bugs_in_esp32_en.pdf>`_
    :esp32s2: - `Chip Errata <https://www.espressif.com/sites/default/files/documentation/esp32-s2_errata_en.pdf>`_
    :esp32s3: - `Chip Errata <https://www.espressif.com/sites/default/files/documentation/esp32-s3_errata_en.pdf>`_
    :esp32c3: - `Chip Errata <https://www.espressif.com/sites/default/files/documentation/esp32-c3_errata_en.pdf>`_
    :esp32c2: - `Chip Errata <https://www.espressif.com/sites/default/files/documentation/esp8684_errata_en.pdf>`_
    :esp32c5: - `Chip Errata <https://docs.espressif.com/projects/esp-chip-errata/en/latest/esp32c5/index.html>`_
    :esp32p4: - `Chip Errata <https://docs.espressif.com/projects/esp-chip-errata/en/latest/esp32p4/index.html>`_
    :esp32p4: - `Consolidated Pin Overview Excel <https://documentation.espressif.com/ESP32-P4%20Appendix%20Consolidated%20Pin%20Overview.xlsx>`_
    - `{IDF_TARGET_NAME} Chip Variants <https://espressif.com/en/products/socs?id={IDF_TARGET_NAME}>`__
    - `Espressif KiCad Library <https://github.com/espressif/kicad-libraries>`__
    - `ESP Product Selector <https://products.espressif.com/#/product-selector?names=>`__
    - `Regulatory Certificates <https://www.espressif.com/en/certificates>`__
    - `User Forum (Hardware) <https://esp32.com/viewforum.php?f=12>`__
    - `Technical Support <https://www.espressif.com/en/contact-us/technical-inquiries>`__
    - `ESP-FAQ <https://docs.espressif.com/projects/esp-faq/en/latest/index.html>`__