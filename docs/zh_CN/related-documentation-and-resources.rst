相关文档和资源
===================
:link_to_translation:`en:[English]`

.. _hardware-development-modules:

{IDF_TARGET_NAME} 系列模组
------------------------------

请至乐鑫官网的 `模组页面 <https://www.espressif.com/zh-hans/products/modules>`_ 查看 {IDF_TARGET_NAME} 系列模组的最新详细信息。

.. only:: not esp32p4

    {IDF_TARGET_NAME} 系列模组的参考设计请参考：

.. only:: latex

    - `下载链接 <https://docs.espressif.com/projects/esp-hardware-design-guidelines/zh_CN/latest/{IDF_TARGET_PATH_NAME}/hardware-development.html>`_

.. only:: esp32

    .. only:: html

        - :download:`ESP32-MINI-1 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-mini-1_reference_design.zip>`
        - :download:`ESP32-WROOM-32E 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-wroom-32e_reference_design.zip>`
        - :download:`ESP32-WROVER-E 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-wrover-e_reference_design.zip>`

.. only:: esp32s3

    .. only:: html

        - :download:`ESP32-S3-MINI-1 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-s3-mini-1_reference_design.zip>`
        - :download:`ESP32-S3-WROOM-1 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-s3-wroom-1_reference_design.zip>`

.. only:: esp32c3

    .. only:: html

        - :download:`ESP32-C3-MINI-1 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-c3-mini-1_reference_design.zip>`
        - :download:`ESP32-C3-WROOM-02 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-c3-wroom-02_reference_design.zip>`

.. only:: esp32c6

    .. only:: html

        - :download:`ESP32-C6-MINI-1 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-c6-mini-1_reference_design.zip>`
        - :download:`ESP32-C6-WROOM-1 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-c6-wroom-1_reference_design.zip>`

.. only:: esp32h2

    .. only:: html

        - :download:`ESP32-H2-MINI-1 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-h2-mini-1_reference_design.zip>`
        - :download:`ESP32-H2-WROOM-02C 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-h2-wroom-02c_reference_design.zip>`

.. only:: esp32c2

    .. only:: html

        - :download:`ESP8684-MINI-1 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp8684-mini-1_reference_design.zip>`
        - :download:`ESP8684-WROOM-02C 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp8684-wroom-02c_reference_design.zip>`

.. only:: esp32c5

    .. only:: html

        - :download:`ESP32-C5-MINI-1-N4 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-c5-mini-1-n4_reference_design.zip>`
        - :download:`ESP32-C5-WROOM-1-N8R8 参考设计 <../_static/{IDF_TARGET_PATH_NAME}/esp32-c5-wroom-1-n8r8_reference_design.zip>`

    天线设计仅供参考，实际项目需基于 PCB 进行仿真设计。

.. only:: not esp32p4

    .. note::

        请使用以下工具打开模组参考设计里的文件：

            - .DSN 文件：OrCAD Capture V16.6
            - .pcb 文件：Pads Layout VX.2。如果无法打开 .pcb 文件，请尝试用其他软件导入 .asc 文件查看 PCB 版图。

{IDF_TARGET_NAME} 系列开发板
--------------------------------

请至乐鑫官网的 `开发板页面 <https://www.espressif.com/zh-hans/products/hardware/development-boards>`_ 查看 {IDF_TARGET_NAME} 系列开发板的最新详细信息。

.. only:: esp32p4

    {IDF_TARGET_NAME} 系列开发板的参考设计请参考：

    .. only:: html

        - :download:`ESP32-P4-Function-EV-Board V1.5.2 参考设计 (ZIP) <../_static/{IDF_TARGET_PATH_NAME}/ESP32-P4-Function-EV-Board_V1.5.2_CN.zip>`
        - :download:`ESP32-P4-EYE V2.3 参考设计 (ZIP) <../_static/{IDF_TARGET_PATH_NAME}/ESP32-P4-EYE-MB_V2.3_CN.zip>`

    .. note::

        请使用以下工具打开开发板参考设计里的文件：

            - .DSN 文件：OrCAD Capture V16.6
            - .brd 文件：Allegro 16.6

其他文档和资源
-----------------

.. list::

    - `芯片规格书 (PDF) <{IDF_TARGET_DATASHEET_CN_URL}>`__
    - `技术参考手册 (PDF) <{IDF_TARGET_TRM_CN_URL}>`__
    :esp32: - `芯片勘误表 <https://espressif.com/sites/default/files/documentation/eco_and_workarounds_for_bugs_in_esp32_cn.pdf>`_
    :esp32s2: - `芯片勘误表 <https://www.espressif.com/sites/default/files/documentation/esp32-s2_errata_cn.pdf>`_
    :esp32s3: - `芯片勘误表 <https://www.espressif.com/sites/default/files/documentation/esp32-s3_errata_cn.pdf>`_
    :esp32c3: - `芯片勘误表 <https://www.espressif.com/sites/default/files/documentation/esp32-c3_errata_cn.pdf>`_
    :esp32c2: - `芯片勘误表 <https://www.espressif.com/sites/default/files/documentation/esp8684_errata_cn.pdf>`_
    :esp32c5: - `芯片勘误表 <https://docs.espressif.com/projects/esp-chip-errata/zh_CN/latest/esp32c5/index.html>`_
    :esp32p4: - `芯片勘误表 <https://docs.espressif.com/projects/esp-chip-errata/zh_CN/latest/esp32p4/index.html>`_
    :esp32p4: - `管脚总览 Excel <https://documentation.espressif.com/ESP32-P4%20%E9%99%84%E5%BD%95%E7%AE%A1%E8%84%9A%E6%80%BB%E8%A7%88.xlsx>`_
    - `{IDF_TARGET_NAME} 系列芯片 <https://espressif.com/zh-hans/products/socs?id={IDF_TARGET_NAME}>`__
    - `乐鑫 KiCad 仓库 <https://github.com/espressif/kicad-libraries>`__
    - `乐鑫产品选型工具 <https://products.espressif.com/#/product-selector?names=>`__
    - `产品证书 <https://www.espressif.com/zh-hans/certificates>`__
    - `论坛（硬件问题讨论） <https://esp32.com/viewforum.php?f=30>`__
    - `技术支持 <https://www.espressif.com/zh-hans/contact-us/technical-inquiries>`__
    - `常见问题 (ESP-FAQ) <https://docs.espressif.com/projects/esp-faq/zh_CN/latest/index.html>`__