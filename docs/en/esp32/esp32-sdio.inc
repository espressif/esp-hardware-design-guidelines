{IDF_TARGET_NAME} supports an SD/SDIO/MMC host controller and an SD/SPI slave controller, compliant with the SDIO 2.0 specification. For the SDIO host/slave controller, {IDF_TARGET_NAME} provides two sets of slot GPIOs for use. Since the GPIOs in slot0 are by default connected to flash, please connect the GPIOs and signal lines according to slot1 as shown in Table :ref:`tab-sdio`.

.. list-table:: SDIO Pin Configuration
    :name: tab-sdio
    :header-rows: 1
    :widths: 10 10 10 10 10 10 10 30
    :align: center

    * -
      - CMD
      - CLK
      - DAT0
      - DAT1
      - DAT2
      - DAT3
      - Note
    * - Slot0
      - GPIO11
      - GPIO6
      - GPIO7
      - GPIO8
      - GPIO9
      - GPIO10
      - Used to connect flash by default. Not recommended for other use.
    * - Slot1
      - GPIO15
      - GPIO14
      - GPIO2
      - GPIO4
      - GPIO12
      - GPIO13
      - Multiplexed with JTAG, touch, EMAC, and strapping functions.

When connecting GPIOs in slot1 to signal lines, please note:

    - When {IDF_TARGET_NAME} works as an SDIO host, it is recommended to add pull-up resistors on the used pins. Unused pins can be utilized for other purposes.
    - When {IDF_TARGET_NAME} works as an SDIO slave, add pull-up resistors on all pins, regardless of whether these pins are used for SDIO or not. Unused pins cannot be used for other purposes.
    - Since there are strapping pins among the SDIO GPIOs, enabling pull-up resistors for SDIO may cause some conflicts. For specific solutions, please refer to `SD Pull-up Requirements <https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/sd_pullup_requirements.html>`_.

For more information on SDIO configuration, please refer to `API References <https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/index.html>`_.