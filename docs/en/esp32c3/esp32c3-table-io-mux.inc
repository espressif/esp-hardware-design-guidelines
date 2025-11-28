.. _IO MUX Pin Functions:

.. csv-table:: IO MUX Pin Functions
    :header-rows: 1

    Name,No.,Function 0,Function 1,Function 2,Reset,Notes
    XTAL_32K_P,4,GPIO0,GPIO0,—,0,R
    XTAL_32K_N,5,GPIO1,GPIO1,—,0,R
    GPIO2,6,GPIO2,GPIO2,FSPIQ,1,R
    GPIO3,8,GPIO3,GPIO3,—,1,R
    MTMS,9,MTMS,GPIO4,FSPIHD,1,R
    MTDI,10,MTDI,GPIO5,FSPIWP,1,R
    MTCK,12,MTCK,GPIO6,FSPICLK,1*,G
    MTDO,13,MTDO,GPIO7,FSPID,1,G
    GPIO8,14,GPIO8,GPIO8,—,1,—
    GPIO9,15,GPIO9,GPIO9,—,3,—
    GPIO10,16,GPIO10,GPIO10,FSPICS0,1,G
    VDD_SPI,18,GPIO11,GPIO11,—,0,—
    SPIHD,19,SPIHD,GPIO12,—,3,—
    SPIWP,20,SPIWP,GPIO13,—,3,—
    SPICS0,21,SPICS0,GPIO14,—,3,—
    SPICLK,22,SPICLK,GPIO15,—,3,—
    SPID,23,SPID,GPIO16,—,3,—
    SPIQ,24,SPIQ,GPIO17,—,3,—
    GPIO18,25,GPIO18,GPIO18,—,0,"USB, G"
    GPIO19,26,GPIO19,GPIO19,—,0*,USB
    U0RXD,27,U0RXD,GPIO20,—,3,G
    U0TXD,28,U0TXD,GPIO21,—,4,—

**Reset**
    
The default configuration of each pin after reset:

- 0 -- input disabled, in high impedance state (IE = 0)
- 1 -- input enabled, in high impedance state (IE = 1)
- 2 -- input enabled, pull-down resistor enabled (IE = 1, WPD = 1)
- 3 -- input enabled, pull-up resistor enabled (IE = 1, WPU = 1)
- 4 -- output enabled, pull-up resistor enabled (OE = 1, WPU = 1)
- 0* -- input disabled, pull-up resistor enabled (IE = 0, WPU = 0, USB_WPU = 1). See details in Notes
- 1* -- When the value of eFuse bit EFUSE_DIS_PAD_JTAG is
    
    - 0, input enabled, pull-up resistor enabled (IE = 1, WPU = 1)
    - 1, input enabled, in high impedance state (IE = 1)

**Notes**

.. list::

    - R -- These pins have analog functions.
    - USB -- GPIO18 and GPIO19 are USB pins.

        -  By default, the USB function is enabled for USB pins (i.e., GPIO18 and GPIO19), and the pin pull-up is decided by the USB pull-up resistor. The USB pull-up resistor is controlled by USB_SERIAL_JTAG_DP/DM_PULLUP and the pull-up value is controlled by USB_SERIAL_JTAG_PULLUP_VALUE. For details, see `{IDF_TARGET_NAME} Technical Reference Manual <{IDF_TARGET_TRM_EN_URL}>`__ > Chapter *USB Serial/JTAG Controller*.
        -  When the USB function is disabled, USB pins are used as regular GPIOs and the pin's internal weak pull-up and pull-down resistors are disabled by default (configurable by IO_MUX_FUN_WPU/WPD).
    - G -- These pins have glitches during power-up. See details in Table :ref:`tab-glitches-on-pins`.
