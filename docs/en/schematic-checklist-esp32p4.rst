Schematic Checklist
======================
:link_to_translation:`zh_CN:[中文]`

.. _schematic-checklist-overview:

Overview
---------

The integrated circuitry of ESP32-P4 series chips requires only 40 electrical components (resistors, capacitors, and inductors) and a crystal, as well as an SPI flash and a direct current to direct current converter (DCDC). The high integration of ESP32-P4 allows for simple peripheral circuit design. This chapter details the schematic design of ESP32-P4.

The following figures show the reference schematics of ESP32-P4, which can be used as the basis of your schematic design.

.. attention::

    For new designs, please refer to the schematic of chip revisions v3.0 and later versions.

.. figure:: ../_static/esp32p4/esp32p4-core-schematic_rev3.0-and-later.png
   :name: fig-chip-core-schematic-2
   :align: center
   :width: 95%
   :alt: ESP32-P4 Reference Schematic (Chip Revisions v3.0 and Later)

   ESP32-P4 Reference Schematic (Chip Revisions v3.0 and Later)

.. figure:: ../_static/esp32p4/esp32p4-core-schematic_rev1.0-and-v1.3.png
   :name: fig-chip-core-schematic-1
   :align: center
   :width: 95%
   :alt: ESP32-P4 Reference Schematic (Chip Revisions v1.0 and v1.3)

   ESP32-P4 Reference Schematic (Chip Revisions v1.0 and v1.3)

.. important::

    The main differences between chip revisions v1.0/v1.3 (**not recommended for new designs**) and v3.0 and later versions include the definition of pin 54, the 1 MΩ resistor on the DP pin, the two 499 kΩ resistors and one 22 pF capacitor in the DCDC circuit. For detailed descriptions of these differences, please refer to the following sections.

    In chip revisions v3.0 and later versions, pin 54 of ESP32-P4 is defined as VDD_HP_1; in chip revisions v1.0 and v1.3, this pin is defined as NC.

    Differences between ESP32-P4 chip revisions and how to distinguish them are described in `ESP32-P4 Series SoC Errata <https://docs.espressif.com/projects/esp-chip-errata/en/latest/esp32p4/index.html>`_.


Any basic ESP32-P4 circuit design includes the following major building blocks:

.. list::

    - `Power supply`_
    - `Chip power-up and reset timing`_
    - `Flash and PSRAM`_
    - `Clock source`_
    - `UART`_
    - `Strapping pins`_
    - `GPIO`_
    - `ADC`_
    - `SDIO`_
    - `USB`_
    - `Touch sensor`_
    - `Ethernet MAC`_
    - `MIPI`_

The rest of this chapter details the specifics of circuit design for each of these sections.

.. _p4-power-supply:

Power Supply
----------------

The general recommendations for power supply design are:

- For a single power supply, a voltage of 3.3 V is recommended.
- Without external peripherals, ESP32-P4 requires a minimum supply current of 380 mA. For the supply current when peripherals are connected, please refer to `HP/LP IO Power Supply`_, `MIPI PHY Power Supply`_ and `USB PHY Power Supply`_. Calculate the required supply current based on your application and choose an appropriate power supply chip.
- It is suggested to add a 10 μF capacitor at each power entrance.
- The power scheme is as shown in Figure :ref:`fig-chip-power-scheme`.

.. figure:: ../_static/esp32p4/esp32p4-chip-power-scheme.png
   :name: fig-chip-power-scheme
   :align: center
   :width: 95%
   :alt: ESP32-P4 Power Scheme

   ESP32-P4 Power Scheme

More information about power supply pins can be found in `ESP32-P4 Series Datasheet <{IDF_TARGET_DATASHEET_EN_URL}#cd-pwr-supply>`__ > Section *Power Supply*.

.. _hp-lp-power-supply:

HP/LP IO Power Supply
^^^^^^^^^^^^^^^^^^^^^

.. include:: esp32p4/esp32p4-gpio-power-supply.inc

.. _mipi-phy-power-supply:

MIPI PHY Power Supply
^^^^^^^^^^^^^^^^^^^^^

The VDD_MIPI_DPHY of ESP32-P4 is the power supply pin for MIPI PHY. The operating voltage range is 2.25 V ~ 2.75 V. The maximum current consumption is 50 mA. It is recommended to use the internal voltage regulator for power supply, and place 10 nF + 0.1 μF + 1 μF capacitors near VDD_MIPI_DPHY in the circuit.

If the MIPI function is not required, VDD_MIPI_DPHY can be left floating.

.. attention::

    The voltage level of MIPI signals is defined by the MIPI specification. For details, please refer to the relevant MIPI protocol documentation. Note that this is a different concept from the MIPI DPHY voltage level. The 1.8 V/3.3 V levels mentioned in Camera/Display Datasheet refer to signals other than the MIPI signals (Data Lane & CLK), such as MCLK and I2C. The voltage level of MIPI signals is handled internally by the ESP32-P4's built-in MIPI DPHY and requires no additional configuration.

.. _usb-phy-power-supply:

USB PHY Power Supply
^^^^^^^^^^^^^^^^^^^^

The VDD_USBPHY of ESP32-P4 is the power supply pin for USB PHY. The operating voltage range is 2.97 V ~ 3.63 V. The maximum current consumption is 20 mA. It is recommended to place 10 nF + 0.1 μF + 1 μF capacitors near VDD_USBPHY in the circuit.

If DP and DM are not required, the VDD_USBPHY power supply can be left floating.

If DP and DM are required, for chip revisions v1.0 and v1.3 (**not recommended for new designs**), note that the VDD_USBPHY power supply exhibits leakage current in low power modes. Therefore, it is recommended to add a MOSFET circuit to completely shut off this power supply in low power modes. During the validation phase, a 0 Ω series resistor can be added on VDD_USBPHY.

.. figure:: ../_static/esp32p4/esp32p4-usbphy-circuit-design-rev1.0-and-v1.3.png
  :align: center
  :width: 70%
  :alt: VDD_USBPHY Reference Schematic (Chip Revisions v1.0 and v1.3)

  VDD_USBPHY Reference Schematic (Chip Revisions v1.0 and v1.3)

In chip revisions v3.0 and later versions, this issue has been fixed, and the 0 Ω series resistor can be retained for design compatibility.

Flash and PSRAM IO Power Supply
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The VDD_FLASHIO of ESP32-P4 is the power supply pin for FLASH IO. The operating voltage is 1.65 V ~ 1.95 V/3.0 V ~ 3.6 V. This power is supplied by VDDO_FLASH from the voltage regulator. It is recommended to place 0.1 μF + 1 μF capacitors near VDD_FLASHIO in the circuit.

VDD_PSRAM_0 and VDD_PSRAM_1 are power supply pins for PSRAM IO. The operating voltage is 1.65 V ~ 1.95 V. This power is supplied by VDDO_PSRAM from the voltage regulators. It is recommended to place 0.1 μF + 1 μF capacitors near VDD_PSRAM_0 and VDD_PSRAM_1 in the circuit.

.. _p4-analog-power-supply:

Analog Power Supply
^^^^^^^^^^^^^^^^^^^^

The VDD_ANA of ESP32-P4 is an analog power supply pin. The operating voltage range is 3.0 V ~ 3.6 V. It is recommended to place a 0.1 μF capacitor near VDD_ANA in the circuit. The VDD_BAT is also an analog power supply pin. The operating voltage range is 2.5 V ~ 3.6 V. It is recommended to place 0.1 μF + 10 μF capacitors near VDD_BAT.

Pin VDD_BAT must not be left floating. An external battery can be connected. For details, refer to the `ESP32-P4 Battery Backup Solution <https://docs.espressif.com/projects/esp-iot-solution/en/latest/low_power_solution/esp32p4_vbat.html>`__.

Digital Power Supply
^^^^^^^^^^^^^^^^^^^^^^^^

VDD_HP_0, VDD_HP_1, VDD_HP_2, and VDD_HP_3 of the ESP32-P4 are digital power supply pins, working in a voltage range of 0.99 V ~ 1.3 V. This power is supplied by ESP_VDD_HP from the external DCDC. It is recommended to place a 10 μF capacitor at the main power source and 0.1 μF capacitors near each power pin.

.. _internal-voltage-regulators:

Internal Voltage Regulators and External DCDC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. include:: esp32p4/esp32p4-ldo-dcdc.inc

Chip Power-up and Reset Timing
----------------------------------------

ESP32-P4's CHIP_PU pin can enable the chip when it is high and reset the chip when it is low.

When ESP32-P4 uses a 3.3 V system power supply, the power rails need some time to stabilize before CHIP_PU is pulled up and the chip is enabled. Therefore, CHIP_PU needs to be asserted high after the 3.3 V rails have been brought up.

To reset the chip, keep the reset voltage V\ :sub:`IL_nRST` in the range of (–0.3 ~ 0.25 × VDD_BAT) V. To avoid reboots caused by external interferences, make the CHIP_PU trace as short as possible.

Figure :ref:`fig-chip-timing` shows the power-up and reset timing of ESP32-P4.

.. figure:: ../_static/shared-chip-timing.png
    :name: fig-chip-timing
    :align: center
    :width: 90%
    :alt: ESP32-P4 Power-up and Reset Timing

    ESP32-P4 Power-up and Reset Timing

Table :ref:`tab-chip-timing` provides the specific timing requirements.

.. list-table:: Description of Timing Parameters for Power-up and Reset
    :name: tab-chip-timing
    :header-rows: 1
    :widths: 20 60 20
    :align: center

    * - Parameter
      - Description
      - Minimum (µs)
    * - t\ :sub:`STBL`
      - Time reserved for the power rails to stabilize before the CHIP_PU pin is pulled high to activate the chip
      - 50
    * - t\ :sub:`RST`
      - Time reserved for CHIP_PU to stay below V\ :sub:`IL_nRST` to reset the chip
      - 1000

.. attention::

    - CHIP_PU must not be left floating.
    - To ensure the correct power-up and reset timing, it is advised to add an RC delay circuit at the CHIP_PU pin. The recommended setting for the RC delay circuit is usually R = 10 kΩ and C = 0.1 μF. However, specific parameters should be adjusted based on the characteristics of the actual power supply and the power-up and reset timing of the chip.
    - If the user application has one of the following scenarios:

        - Slow power rise or fall, such as during battery charging.
        - Frequent power on/off operations.
        - Unstable power supply, such as in photovoltaic power generation.

      Then, the RC circuit itself may not meet the timing requirements, resulting in the chip being unable to boot correctly. In this case, additional designs need to be added, such as:

        - Adding an external reset chip or a watchdog chip, typically with a threshold of around 3.0 V.
        - Implementing reset functionality through a button or the main controller.

Flash and PSRAM
---------------------

ESP32-P4 requires off-package flash for storing application firmware and data. ESP32-P4 supports up to 64 MB flash, which can be connected via SPI, Dual SPI, and Quad SPI.

ESP32-P4 includes OPI/HPI 1.8 V PSRAM, which is not pinned out externally.

The following table lists the pin mapping between ESP32-P4 and off-package flash for Quad SPI mode. Please note that the pins can connect to one flash at the maximum.

.. include:: esp32p4/esp32p4-chip-flash-pin-mapping.inc

By default, VDDO_FLASH is used as the power supply for flash, and VDDO_PSRAM is used as the power supply for PSRAM.

When VDDO_FLASH is in the output mode of 3.3 V, consider the impact of R\ :sub:`VFB` on VDD_LDO. For example, when connecting a 3.3 V flash, the following condition must be met:

.. math::

    VDD\_LDO > VDD\_flash\_min + I\_flash\_max \times R_{VFB}

In the formula above, VDD_flash_min is the minimum operating voltage of the flash, I_flash_max is the maximum operating current of the flash, and R\ :sub:`VFB` is the on-resistance in 3.3 V mode.

.. attention::

    - It is recommended to add zero-ohm resistor footprints in series on the SPI communication lines. These footprints provide flexibility for future adjustments, such as tuning drive strength, mitigating RF interference, correcting signal timing, and reducing noise, if needed.
    - Place a pull-up resistor at the FLASH_CS pin.
    - It is recommended to place a 0.1 μF capacitor at the flash power supply pin.

Clock Source
----------------

ESP32-P4 supports two external clock sources:

- `External crystal clock source (Compulsory)`_
- `RTC clock source (Optional)`_

External Crystal Clock Source (Compulsory)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The ESP32-P4 firmware only supports 40 MHz crystal.

The circuit for the crystal is shown in Figure :ref:`fig-external-crystal-schematic`. Note that the accuracy of the selected crystal should be within ±10 ppm.

.. figure:: ../_static/esp32p4/esp32p4-sche-external-crystal.png
   :name: fig-external-crystal-schematic
   :align: center
   :width: 65%
   :alt: ESP32-P4 Schematic for External Crystal

   ESP32-P4 Schematic for External Crystal

The initial values of external capacitors C4 and C5 can be determined according to the formula:

.. math::

   C_L =  \frac{C4 \times C5} {C4+C5} + C_{stray}

In the formula above, the value of C\ :sub:`L` (load capacitance) can be found in the crystal's datasheet, and the value of C\ :sub:`stray` refers to the PCB's stray capacitance. The values of C4 and C5 need to be further adjusted after an overall test.

.. _schematic-rtc-clock-source:

RTC Clock Source (Optional)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

ESP32-P4 supports an external 32.768 kHz crystal to act as the RTC clock. The external RTC clock source enhances timing accuracy and consequently decreases average power consumption, without impacting functionality.

Figure :ref:`fig-32khz-crystal-schematic` shows the schematic for the external 32.768 kHz crystal.

.. figure:: ../_static/esp32p4/esp32p4-sche-32khz-crystal.png
    :name: fig-32khz-crystal-schematic
    :align: center
    :width: 60%
    :alt: ESP32-P4 Schematic for 32.768 kHz Crystal

    ESP32-P4 Schematic for 32.768 kHz Crystal

Please note the requirements for the 32.768 kHz crystal:

    - Equivalent series resistance (ESR) ≤ 70 kΩ.
    - Load capacitance at both ends should be configured according to the crystal's specification.

The parallel resistor R is used for biasing the crystal circuit (5 MΩ < R ≤ 10 MΩ). In general, you do not need to populate the resistor.

If the RTC clock source is not required, then the pins for the 32.768 kHz crystal can be used as GPIOs.

.. _schematic-checklist-uart:

UART
---------

ESP32-P4 includes five UART interfaces, UART0 ~ UART4, all of which support both hardware flow control (CTS and RTS signals) and software flow control (XON and XOFF). In addition, ESP32-P4 includes one LP UART interface, which also supports both hardware flow control (CTS and RTS signals) and software flow control (XON and XOFF).

The UART0_TXD pin is GPIO37, and the UART0_RXD pin is GPIO38. The other UART0 signals can be mapped to any available GPIO through software configurations. The LP UART TXD is LP GPIO14, and the LP UART RXD is LP GPIO15. The other LP UART signals can be mapped to any available GPIO through software configurations.

Typically, UART0 is used for download and log printing. For instructions on how to download via UART0, please refer to Section :ref:`download-guidelines`.

It is recommended to use UART1 ~ UART4 as communication serial ports.

.. _schematic-checklist-spi:

SPI
---

When using the SPI function, to improve EMC performance, add a series resistor (or ferrite bead) and a capacitor to ground on the SPI_CLK trace. If space allows, it is recommended to also add a series resistor and capacitor to ground on other SPI traces. Ensure that the RC/LC components are placed close to the pins of the chip or module.

.. _schematic-checklist-strapping-pins:

Strapping Pins
-----------------

At each startup or reset, a chip requires some initial configuration parameters, such as in which boot mode to load the chip, etc. These parameters are passed over via the strapping pins. After reset, the strapping pins work as normal function pins.

GPIO34, GPIO35, GPIO36, GPIO37, and GPIO38 are strapping pins.

All the information about strapping pins is covered in `ESP32-P4 Series Datasheet <{IDF_TARGET_DATASHEET_EN_URL}>`__ > Section *Boot Configurations*. In this document, we will mainly cover the strapping pins related to boot mode.

After chip reset is released, the combination of GPIO35, GPIO36, GPIO37, and GPIO38 controls the boot mode. See Table :ref:`tab-chip-boot-mode-control`.

.. include:: esp32p4/esp32p4-chip-boot-mode-control.inc

Signals applied to the strapping pins should have specific *setup time* and *hold time*. For more information, see Figure :ref:`fig-shared-strap-pin-timing` and Table :ref:`tab-strap-pin-timing`.

.. figure:: ../_static/shared-strap-pin-timing.png
   :name: fig-shared-strap-pin-timing
   :align: center
   :width: 90%
   :alt: Setup and Hold Times for Strapping Pins

   Setup and Hold Times for Strapping Pins


.. list-table:: Description of Timing Parameters for Strapping Pins
    :name: tab-strap-pin-timing
    :header-rows: 1
    :widths: 20 60 20
    :align: center

    * - Parameter
      - Description
      - Minimum (ms)
    * - t\ :sub:`SU`
      - Time reserved for the power rails to stabilize before the chip enable pin (CHIP_PU) is pulled high to activate the chip.
      - 0
    * - t\ :sub:`H`
      - Time reserved for the chip to read the strapping pin values after CHIP_PU is already high and before these pins start operating as regular IO pins.
      - 3


.. attention::

    - It is recommended to reserve a pull-up resistor at the GPIO35.
    - Do not add high-value capacitors at GPIO35, otherwise, the chip may not boot successfully.


GPIO
--------

The pins of ESP32-P4 can be configured via IO MUX or GPIO matrix. IO MUX provides the default pin configurations (see `ESP32-P4 Series Datasheet <{IDF_TARGET_DATASHEET_EN_URL}#cd-append-consolid-pin-overview>`__ > Appendix *ESP32-P4 Consolidated Pin Overview*), whereas the GPIO matrix is used to route signals from peripherals to GPIO pins. For more information about IO MUX and GPIO matrix, please refer to `ESP32-P4 Technical Reference Manual <{IDF_TARGET_TRM_EN_URL}>`__ > Chapter *IO MUX and GPIO Matrix*.

Some peripheral signals have already been routed to certain GPIO pins, while some can be routed to any available GPIO pins. For details, please refer to `ESP32-P4 Series Datasheet <{IDF_TARGET_DATASHEET_EN_URL}>`__ > Section *Peripherals*.

When using GPIOs, please:

.. list::

    - Pay attention to the states of strapping pins during power-up.
    - Pay attention to the default configurations of the GPIOs after reset. The default configurations can be found in Table :ref:`IO MUX Pin Functions`. It is recommended to add a pull-up or pull-down resistor to pins in the high-impedance state or enable the pull-up and pull-down during software initialization to avoid extra power consumption.
    - Only GPIOs in the VDD_LP power domain can be controlled in Deep-sleep mode.
    - When powered solely by the battery, only GPIOs in the VDD_BAT power domain can be controlled.

.. include:: esp32p4/esp32p4-table-io-mux.inc

ADC
------

.. include:: esp32p4/esp32p4-adc.inc

.. _esp32p4-sdio:

SDIO
------

.. include:: esp32p4/esp32p4-sdio.inc

.. _esp32p4-usb:

USB
-------

.. include:: esp32p4/esp32p4-usb.inc

Touch Sensor
----------------

When using the touch function, it is recommended to populate a series resistor at {IDF_TARGET_NAME} side to reduce the coupling noise and interference on the line, and to strengthen the ESD protection. The recommended resistance is from 470 Ω to 2 kΩ, preferably 510 Ω. The specific value depends on the actual test results of the product.

The ESP32-P4 touch sensor has a waterproof design to reduce the impact of small water droplets. The ESP32-P4 touch sensor includes a special PAD called the Shield Pad. You can choose any touch pin as the Shield Pad, which will be connected in parallel with the currently measured touch pin, effectively reducing the impact of water droplets.

.. _schematic-checklist-ethernet-mac:

Ethernet MAC
-------------

.. include:: esp32p4/esp32p4-emac.inc

MIPI
----

ESP32-P4 includes an MIPI DSI interface for connecting displays with an MIPI interface, and an MIPI CSI interface for connecting cameras with an MIPI interface. Please populate a 4.02 kΩ pull-down resistor to both the CSI_REXT pin and DSI_REXT pin.

It is recommended to reserve series resistors on the MIPI communication lines (initially 0 Ω). The main purposes are to reduce drive current, adjust timing, and improve interference resistance.

If an RF module is included in the design, please also add series resistors on the CSI interface at the device end to minimize interference with the RF module.

.. attention::

    - If the MIPI interface is not used, the power and external resistor pins can be left floating.
    - For MIPI interface devices, please use GPIO for control signals.

.. figure:: ../_static/esp32p4/esp32p4-mipi.png
    :name: fig-mipi
    :align: center
    :width: 50%
    :alt: ESP32-P4 Schematic for MIPI Signal

    ESP32-P4 Schematic for MIPI Signal
