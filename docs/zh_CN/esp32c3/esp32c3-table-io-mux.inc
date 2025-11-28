.. _IO MUX Pin Functions:

.. csv-table:: IO MUX 管脚功能
    :header-rows: 1

    管脚名称,管脚序号,功能 0,功能 1,功能 2,复位,说明
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

**复位**：

各管脚复位后的默认配置：

- 0 -- 输入关闭，高阻（IE = 0）
- 1 -- 输入使能，高阻（IE = 1）
- 2 -- 输入使能，下拉电阻使能（IE = 1，WPD = 1）
- 3 -- 输入使能，上拉电阻使能（IE = 1，WPU = 1）
- 4 -- 输出使能，上拉电阻使能（OE = 1, WPU = 1）
- 0* -- 输入关闭，上拉电阻使能（IE = 0，WPU = 0，USB_WPU = 1），具体见说明
- 1* -- eFuse 的 EFUSE_DIS_PAD_JTAG 位为

    - 0 时（初始默认值），管脚复位后输入使能，上拉电阻使能（IE = 1， WPU = 1）
    - 1 时，管脚复位后输入使能，高阻（IE = 1）

**说明**：

.. list::

    - R -- 管脚具有模拟功能。
    - USB -- GPIO18、GPIO19 为 USB 管脚。

        - USB 管脚（GPIO18 和 GPIO19）默认开启 USB 功能，此时管脚是否上拉由 USB 上拉电阻决定。USB 上拉电阻由 USB_SERIAL_JTAG_DP/DM_PULLUP 控制，具体阻值可通过 USB_SERIAL_JTAG_PULLUP_VALUE 位控制，详见 `{IDF_TARGET_NAME} 技术参考手册 <{IDF_TARGET_TRM_CN_URL}>`__ > 章节 *USB 串口/JTAG 控制器*。
        - USB 管脚关闭 USB 功能时，用作普通 GPIO，默认禁用管脚内部弱上下拉电阻，可通过 IO_MUX_FUN_WPU/WPD 配置。
    - G -- 管脚在芯片上电过程中有毛刺，具体见表 :ref:`tab-glitches-on-pins`。
