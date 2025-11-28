.. _IO MUX Pin Functions:

.. csv-table:: IO MUX 管脚功能
    :header-rows: 1

    管脚名称,管脚序号,功能 0,功能 1,功能 2,复位,说明
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

**复位**：

各管脚复位后的默认配置：

- 0 -- 输入关闭，高阻 (IE = 0)
- 1 -- 输入使能，高阻 (IE = 1)
- 2 -- 输入使能，下拉电阻使能 (IE = 1, WPD = 1)
- 3 -- 输入使能，上拉电阻使能 (IE = 1, WPU = 1)
- 4 -- 输出使能，上拉电阻使能 (OE = 1, WPU = 1)
- 1* -- eFuse 的 EFUSE_DIS_PAD_JTAG 位为

    - 0 时（初始默认值），管脚复位后输入使能，上拉电阻使能 (IE = 1, WPU = 1)
    - 1 时，管脚复位后输入使能，高阻 (IE = 1)


**说明**：

.. list::

    - R -- 管脚具有模拟功能
    - G -- 管脚在芯片上电过程中有毛刺，详见表 :ref:`tab-glitches-on-pins`。
