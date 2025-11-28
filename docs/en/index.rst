ESP Hardware Design Guidelines
================================
:link_to_translation:`zh_CN:[中文]`

.. only:: html

    This document provides guidelines for the `{IDF_TARGET_NAME} SoC <https://www.espressif.com/en/products/socs?id={IDF_TARGET_NAME}>`_. To switch to another chip, use the drop-down menu at the top left of the page.

.. only:: latex

    This document provides guidelines for the `{IDF_TARGET_NAME} SoC <https://www.espressif.com/en/products/socs?id={IDF_TARGET_NAME}>`_.

.. only:: esp32c2

    .. important::

        The {IDF_TARGET_NAME} SoC series group currently includes only one series, the ESP8684. Therefore, any reference to {IDF_TARGET_NAME} in this document applies to the ESP8684.

.. only:: not esp32p4

    ======================    ======================    ======================    ======================
    |Schematic Checklist|_    |PCB Layout Design|_      |Download Guidelines|_    |Resources|_
    ----------------------    ----------------------    ----------------------    ----------------------
    `Schematic Checklist`_    `PCB Layout Design`_      `Download Guidelines`_    `Resources`_
    ======================    ======================    ======================    ======================

    .. |Schematic Checklist| image:: ../_static/schematic-checklist.png
    .. _Schematic Checklist: schematic-checklist.html

    .. |PCB Layout Design| image:: ../_static/pcb-layout-design.png
    .. _PCB Layout Design: pcb-layout-design.html

    .. |Download Guidelines| image:: ../_static/download-guidelines.png
    .. _Download Guidelines: download-guidelines.html

    .. |Resources| image:: ../_static/hardware-development.png
    .. _Resources: hardware-development.html

.. only:: esp32p4

    ======================    ====================    =======================
    |Schematic Checklist|_    |PCB Layout Design|_    |Hardware Development|_
    ----------------------    --------------------    -----------------------
    `Schematic Checklist`_    `PCB Layout Design`_    `Hardware Development`_
    ======================    ====================    =======================

    .. |Schematic Checklist| image:: ../_static/schematic-checklist.png
    .. _Schematic Checklist: schematic-checklist-esp32p4.html

    .. |PCB Layout Design| image:: ../_static/pcb-layout-design.png
    .. _PCB Layout Design: pcb-layout-design-esp32p4.html

    .. |Hardware Development| image:: ../_static/hardware-development.png
    .. _Hardware Development: hardware-development-esp32p4.html

Latest Version of This Document
----------------------------------

.. only:: html

    The document you are reading is the latest version. The full history of releases can be found in Section :ref:`revision-history`.

.. only:: latex

    Check the link to make sure that you use the latest version of this document: https://docs.espressif.com/projects/esp-hardware-design-guidelines/en/latest/{IDF_TARGET_PATH_NAME}/index.html


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
