.. _IO MUX Pin Functions:

.. csv-table:: IO MUX Pin Functions
    :header-rows: 1

    Pin Name,No.,Function 0,Function 1,Function 2,Reset,Notes
    GPIO0,4,GPIO0,GPIO0,—,0,"R, G"
    GPIO1,5,GPIO1,GPIO1,—,0,"R, G"
    GPIO2,6,GPIO2,GPIO2,FSPIQ,1,R
    GPIO3,8,GPIO3,GPIO3,—,1,"R, G"
    MTMS,9,MTMS,GPIO4,FSPIHD,1,R
    MTDI,10,MTDI,GPIO5,FSPIWP,1,"R, G"
    MTCK,12,MTCK,GPIO6,FSPICLK,1*,—
    MTDO,13,MTDO,GPIO7,FSPID,1,—
    GPIO8,14,GPIO8,GPIO8,—,1,—
    GPIO9,15,GPIO9,GPIO9,—,3,—
    GPIO10,16,GPIO10,GPIO10,FSPICS0,1,—
    GPIO18,18,GPIO18,GPIO18,—,0,—
    U0RXD,19,U0RXD,GPIO19,—,3,—
    U0TXD,20,U0TXD,GPIO20,—,4,—

**Reset**：

The default configuration of each pin after reset:

- 0 -- input disabled, in high impedance state (IE = 0)
- 1 -- input enabled, in high impedance state (IE = 1)
- 2 -- input enabled, pull-down resistor enabled (IE = 1, WPD = 1)
- 3 -- input enabled, pull-up resistor enabled (IE = 1, WPU = 1)
- 4 -- output enabled, pull-up resistor enabled (OE = 1, WPU = 1)
- 1* -- When the value of eFuse bit EFUSE_DIS_PAD_JTAG is

    - 0, input enabled, pull-up resistor enabled (IE = 1, WPU = 1)
    - 1, input enabled, in high impedance state (IE = 1)


**Notes**：

.. list::

    - R -- These pins have analog functions.
    - G -- These pins have glitches during power-up. See details in :ref:`tab-glitches-on-pins`.
