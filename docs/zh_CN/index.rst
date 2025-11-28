ESP 硬件设计指南
====================
:link_to_translation:`en:[English]`

.. only:: html

    本文档是 `{IDF_TARGET_NAME} <https://www.espressif.com/zh-hans/products/socs?id={IDF_TARGET_NAME}>`_ 系列芯片的硬件设计指南。如需阅读其他芯片的硬件设计指南，请在页面左上方的下拉菜单中选择您的目标芯片。

.. only:: latex

    本文档是 `{IDF_TARGET_NAME} <https://www.espressif.com/zh-hans/products/socs?id={IDF_TARGET_NAME}>`_ 系列芯片的硬件设计指南。

.. only:: esp32c2

    .. important::

        {IDF_TARGET_NAME} 芯片系列合集当前仅包含 ESP8684 一个系列，因此本文中出现的 {IDF_TARGET_NAME} 指的就是 ESP8684 芯片系列。

.. only:: not esp32p4

    ======================    ======================    ======================    ======================
    |原理图设计|_               |PCB 版图布局|_            |下载指导|_                 |相关文档和资源|_
    ----------------------    ----------------------    ----------------------    ----------------------
    `原理图设计`_               `PCB 版图布局`_            `下载指导`_                 `相关文档和资源`_
    ======================    ======================    ======================    ======================

    .. |原理图设计| image:: ../_static/schematic-checklist.png
    .. _原理图设计: schematic-checklist.html

    .. |PCB 版图布局| image:: ../_static/pcb-layout-design.png
    .. _PCB 版图布局: pcb-layout-design.html

    .. |下载指导| image:: ../_static/download-guidelines.png
    .. _下载指导: download-guidelines.html

    .. |相关文档和资源| image:: ../_static/hardware-development.png
    .. _相关文档和资源: related-documentation-and-resources.html

.. only:: esp32p4

    ======================    ====================    =======================
    |原理图设计|_               |PCB 版图布局|_          |开发硬件介绍|_
    ----------------------    --------------------    -----------------------
    `原理图设计`_               `PCB 版图布局`_          `开发硬件介绍`_
    ======================    ====================    =======================

    .. |原理图设计| image:: ../_static/schematic-checklist.png
    .. _原理图设计: schematic-checklist-esp32p4.html

    .. |PCB 版图布局| image:: ../_static/pcb-layout-design.png
    .. _PCB 版图布局: pcb-layout-design-esp32p4.html

    .. |开发硬件介绍| image:: ../_static/hardware-development.png
    .. _开发硬件介绍: hardware-development-esp32p4.html

本文档的最新版本
------------------

.. only:: html

    您正在阅读的是最新版本的文档。完整的发布历史可在第 :ref:`revision-history` 节中查看。

.. only:: latex

    请查看以下链接，以确保使用的是本文档的最新版本：https://docs.espressif.com/projects/esp-hardware-design-guidelines/zh_CN/latest/{IDF_TARGET_PATH_NAME}/index.html


.. toctree::
   :hidden:

   about-this-document
   product-overview
   :not esp32p4: schematic-checklist
   :esp32p4: schematic-checklist-esp32p4
   :not esp32p4: pcb-layout-design
   :esp32p4: pcb-layout-design-esp32p4
   :not esp32p4: download-guidelines
   :esp32p4: hardware-development-esp32p4
   related-documentation-and-resources
   glossary
   revision-history
   disclaimer-and-copyright
