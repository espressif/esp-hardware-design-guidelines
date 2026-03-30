.. _IO MUX Pin Functions:

.. csv-table:: IO MUX Pin Functions
    :header-rows: 1

    Name,No.,Function 0,Function 1,Function 2,Reset,Notes
    GPIO0,3,GPIO0,GPIO0,FSPIQ,0,—
    GPIO1,4,GPIO1,GPIO1,FSPICS0,0,R
    MTMS,5,MTMS,GPIO2,FSPIWP,1,R
    MTDO,6,MTDO,GPIO3,FSPIHD,1,R
    MTCK,7,MTCK,GPIO4,FSPICLK,1*,R
    MTDI,8,MTDI,GPIO5,FSPID,1,R
    GPIO8,10,GPIO8,GPIO8,—,1,—
    GPIO9,11,GPIO9,GPIO9,—,3,—
    GPIO10,12,GPIO10,GPIO10,—,0,R
    GPIO11,13,GPIO11,GPIO11,—,0,R
    GPIO12,14,GPIO12,GPIO12,—,0,—
    XTAL_32K_P,15,GPIO13,GPIO13,—,0,R
    XTAL_32K_N,16,GPIO14,GPIO14,—,0,R
    GPIO22,21,GPIO22,GPIO22,—,0,—
    U0RXD,22,U0RXD,GPIO23,FSPICS1,3,—
    U0TXD,23,U0TXD,GPIO24,FSPICS2,4,—
    GPIO25,24,GPIO25,GPIO25,FSPICS3,1,—
    GPIO26,25,GPIO26,GPIO26,FSPICS4,1,"R, USB"
    GPIO27,26,GPIO27,GPIO27,FSPICS5,3*,"R, USB"

- 0 -- input disabled, in high impedance state (IE = 0)
- 1 -- input enabled, in high impedance state (IE = 1)
- 2 -- input enabled, pull-down resistor enabled (IE = 1, WPD = 1)
- 3 -- input enabled, pull-up resistor enabled (IE = 1, WPU = 1)
- 4 -- output enabled, pull-up resistor enabled (OE = 1, WPU = 1)
- 1* -- When the value of eFuse bit EFUSE_DIS_PAD_JTAG is

    - 0, input enabled, pull-up resistor enabled (IE = 1, WPU = 1)
    - 1, input enabled, in high impedance state (IE = 1)

- 3* -- input enabled, pull-up resistor enabled (IE = 1, WPU = 0, USB_WPU = 1). See details in **Notes**.

**Notes**：

.. list::

    - R -- These pins have analog functions.
    - USB -- USB pull-up resistor is enabled.

        - By default, the USB function is enabled for USB pins (i.e., GPIO26 and GPIO27), and the pin pull-up is decided by the USB pull-up. The USB pull-up is controlled by USB_SERIAL_JTAG_DP/DM_PULLUP and the pull-up resistor value is controlled by USB_SERIAL_JTAG_PULLUP_VALUE. For details, see `{IDF_TARGET_NAME} Technical Reference Manual <{IDF_TARGET_TRM_EN_URL}#usbserialjtag>`__ > Chapter *USB Serial/JTAG Controller*.
        - When the USB function is disabled, USB pins are used as regular GPIOs and the pin’s internal weak pull-up and pull-down resistors are disabled by default (configurable by IO_MUX_GPIOn_FUN_WPU/WPD). For details, see `{IDF_TARGET_NAME} Technical Reference Manual <{IDF_TARGET_TRM_EN_URL}#iomuxgpio>`__ > Chapter *IO MUX and GPIO Matrix (GPIO, IO MUX)*.
