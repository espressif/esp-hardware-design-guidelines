.. list-table:: Revision History
   :header-rows: 1
   :widths: 2 1 7

   * - Date
     - Version
     - Release Notes
   * - 2025-09-22
     - v1.2
     - - :doc:`../schematic-checklist-esp32p4`
           - Section :ref:`internal-voltage-regulators`: Added a note about VDDO_FLASH default voltage and precautions for 1.8 V flash
   * - 2025-07-07
     - v1.1
     - - :doc:`../schematic-checklist-esp32p4`
           - Section :ref:`hp-lp-power-supply`: Added a note about VDD_IO_5
           - Section :ref:`mipi-phy-power-supply`: Updated descriptions about VDD_MIPI_DPHY and added a note about MIPI signal level
           - Section :ref:`internal-voltage-regulators`: Updated descriptions about FB_DCDC and EN_DCDC
           - Section :ref:`esp32p4-sdio`: Added a figure :ref:`esp32p4-sd3-card-power-circuit`
       - :doc:`../pcb-layout-design-esp32p4`
           - Section :ref:`general-guidelines`: Deleted descriptions about the power traces of VDD_FLASHIO and updated descriptions about the placement of DCDC
   * - 2025-04-23
     - v1.0
     - First release of {IDF_TARGET_NAME} Hardware Design Guidelines.
