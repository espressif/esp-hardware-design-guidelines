{IDF_TARGET_NAME} series chips have only one SD/MMC host controller, which cannot operate as a slave. SDIO 2.0 and SDIO 3.0 interfaces require time-division multiplexing.

SDIO 2.0 interface signals can be configured to any available GPIO through the GPIO matrix. However, in SDIO 3.0 interface, certain signal pins are fixed and should be connected as specified in the table below.

Additionally, it is recommended to add one series pull-up resistor for the each SDIO GPIO pin and populate a capacitor to ground on the SDIO CLK line.

SDIO 3.0 protocol specifies that the voltage of SDIO GPIOs should switch automatically. Therefore, it is recommended to connect the SDIO GPIO power domain VDD_IO_5 and the external pull-up power supply to VDDO_4. Additionally, a 10 μF capacitor should be populated to VDD_IO_5. The SD card's power supply should be connected to the 3.3 V power supply of the system.

.. figure:: ../_static/esp32p4/esp32p4-sd3-card-power-circuit.png
   :name: esp32p4-sd3-card-power-circuit
   :align: center
   :width: 95%
   :alt: ESP32-P4 SD 3.0 Card Power Circuit

   ESP32-P4 SD 3.0 Card Power Circuit

To reduce the power consumption of the SD card and reset it, you can populate a MOSFET at the power supply circuit of SD card and control it via GPIO.

.. list-table:: SDIO 3.0 Interface Configuration
   :header-rows: 1
   :widths: 15 10

   * - Signal
     - Pin Name
   * - SD1\_CDATA0\_PAD
     - GPIO39
   * - SD1\_CDATA1\_PAD
     - GPIO40
   * - SD1\_CDATA2\_PAD
     - GPIO41
   * - SD1\_CDATA3\_PAD
     - GPIO42
   * - SD1\_CCLK\_PAD
     - GPIO43
   * - SD1\_CCMD\_PAD
     - GPIO44
   * - SD1\_CDATA4\_PAD
     - GPIO45
   * - SD1\_CDATA5\_PAD
     - GPIO46
   * - SD1\_CDATA6\_PAD
     - GPIO47
   * - SD1\_CDATA7\_PAD
     - GPIO48
