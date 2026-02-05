.. list-table:: Revision History
   :header-rows: 1
   :widths: 2 1 7

   * - Date
     - Version
     - Release Notes
   * - 2026-02-05
     - v1.5
     - :doc:`related-documentation-and-resources`: Added the reference design for development boards
   * - 2026-02-04
     - v1.4
     - - :doc:`../schematic-checklist-esp32p4`
           - Overview: Added notes on the main differences between chip revisions v1.0/v1.3 (not recommended for new designs) and v3.0 and later versions, and updated the corresponding reference design schematics
           - Section :ref:`p4-power-supply`: Modified the minimum supply current
           - Section :ref:`usb-phy-power-supply`: Added notes when using DP and DM, and added a reference schematic for VDD_USBPHY
           - Section :ref:`p4-analog-power-supply`: Modified the operating voltage range of pin VDD_BAT
           - Section :ref:`internal-voltage-regulators`: Updated notes on VDDO_FLASH output voltage configuration, added notes for circuit layout for different chip revisions, and added the corresponding TLV62569 schematic
           - Section :ref:`esp32p4-sdio`: Updated SDIO GPIO pin assignment description and fixed a typo in Figure :ref:`esp32p4-sd3-card-power-circuit`
           - Section :ref:`esp32p4-usb`: Added instructions for adding a pull-down resistor on the DP pin (applicable to chip revisions v1.0 and v1.3)
           - Section :ref:`schematic-checklist-ethernet-mac`: Corrected EMAC signal RMII_RXDV to RMII_CRSDV
       - :doc:`../pcb-layout-design-esp32p4`
           - Section :ref:`general-guidelines`: Added recommendation that power traces for pins VDD_BAT and VDD_ANA should be at least 10 mil
       - :doc:`related-documentation-and-resources`: Added Consolidated Pin Overview Excel
   * - 2025-11-28
     - v1.3
     - - :doc:`../schematic-checklist-esp32p4`
           - Section :ref:`internal-voltage-regulators`: Updated a note about FB_DCDC and EN_DCDC
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
