.. _IO MUX Pin Functions:

.. csv-table:: IO MUX 管脚功能
    :header-rows: 1

    管脚名称,管脚序号,功能 0,功能 1,功能 2,复位,说明
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

- 0 -- 输入关闭，高阻 (IE = 0)
- 1 -- 输入使能，高阻 (IE = 1)
- 2 -- 输入使能，下拉电阻使能 (IE = 1, WPD = 1)
- 3 -- 输入使能，上拉电阻使能 (IE = 1, WPU = 1)
- 4 -- 输出使能，上拉电阻使能 (OE = 1, WPU = 1)
- 1* -- eFuse 的 EFUSE_DIS_PAD_JTAG 位为

    - 0 时（初始默认值），管脚复位后输入使能，上拉电阻使能 (IE = 1, WPU = 1)
    - 1 时，管脚复位后输入使能，高阻 (IE = 1)

- 3* -- 输入使能，上拉电阻使能 (IE = 1, WPU = 0, USB_WPU = 1)。具体见 **说明**。

**说明**：

.. list::

    - R -- 管脚具有模拟功能
    - USB -- USB 上拉电阻使能

        - USB 管脚（GPIO26 和 GPIO27）默认开启 USB 功能，此时管脚是否上拉由 USB 是否上拉决定。USB 上拉由 USB_SERIAL_JTAG_DP/DM_PULLUP 控制，USB 上拉电阻的具体阻值可通过 USB_SERIAL_JTAG_PULLUP_VALUE 位控制，详见 `{IDF_TARGET_NAME} 技术参考手册 <{IDF_TARGET_TRM_CN_URL}>`__ > 章节 *USB 串口/JTAG 控制器*。
        - USB 管脚关闭 USB 功能时，用作普通 GPIO，默认禁用管脚内部弱上/下拉电阻，可通过 IO_MUX_GPIOn_FUN_WPU/WPD 配置，详见 `{IDF_TARGET_NAME} 技术参考手册 <{IDF_TARGET_TRM_CN_URL}>`__ > 章节 *IO MUX 和 GPIO 交换矩阵 (GPIO, IO MUX)*。