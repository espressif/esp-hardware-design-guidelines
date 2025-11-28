.. _IO MUX Pin Functions:

.. csv-table:: IO 管脚默认配置
    :header-rows: 1

    管脚序号,管脚名称,供电管脚,复位时,复位后
    1,VDDA,,,
    2,LNA_IN,VDD3P3,,
    3,VDD3P3,,,
    4,VDD3P3,,,
    5,SENSOR_VP,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    6,SENSOR_CAPP,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    7,SENSOR_CAPN,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    8,SENSOR_VN,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    9,CHIP_PU,VDD3P3_RTC,,
    10,VDET_1,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    11,VDET_2,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    12,32K_XP,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    13,32K_XN,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    14,GPIO25,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    15,GPIO26,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    16,GPIO27,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=0"
    17,MTMS,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=1, wpu"
    18,MTDI,VDD3P3_RTC,"oe=0, ie=1, wpd","oe=0, ie=1, wpd"
    19,VDD3P3_RTC,VDD3P3_RTC,,
    20,MTCK,VDD3P3_RTC,"oe=0, ie=0","oe=0, ie=1, wpd"
    21,MTDO,VDD3P3_RTC,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    22,GPIO2,VDD3P3_RTC,"oe=0, ie=1, wpd","oe=0, ie=1, wpd"
    23,GPIO0,VDD3P3_RTC,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    24,GPIO4,VDD3P3_RTC,"oe=0, ie=1, wpd","oe=0, ie=1, wpd"
    25,GPIO16,VDD_SDIO,"oe=0, ie=0","oe=0, ie=1"
    26,VDD_SDIO,,,
    27,GPIO17,VDD_SDIO,"oe=0, ie=0","oe=0, ie=1"
    28,SD_DATA_2,VDD_SDIO,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    29,SD_DATA_3,VDD_SDIO,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    30,SD_CMD,VDD_SDIO,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    31,SD_CLK,VDD_SDIO,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    32,SD_DATA_0,VDD_SDIO,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    33,SD_DATA_1,VDD_SDIO,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    34,GPIO5,VDD3P3_CPU,"oe=0, ie=1, wpd","oe=0, ie=1, wpd"
    35,GPIO18,VDD3P3_CPU,"oe=0, ie=0","oe=0, ie=1"
    36,GPIO23,VDD3P3_CPU,"oe=0, ie=0","oe=0, ie=1"
    37,VDD3P3_CPU,,,
    38,GPIO19,VDD3P3_CPU,"oe=0, ie=0","oe=0, ie=1"
    39,GPIO22,VDD3P3_CPU,"oe=0, ie=0","oe=0, ie=1"
    40,U0RXD,VDD3P3_CPU,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    41,U0TXD,VDD3P3_CPU,"oe=0, ie=1, wpu","oe=0, ie=1, wpu"
    42,GPIO21,VDD3P3_CPU,"oe=0, ie=0","oe=0, ie=1"
    43,VDDA,,,
    44,XTAL_N,VDDA,,
    45,XTAL_P,VDDA,,
    46,VDDA,,,
    47,CAP2,VDDA,,
    48,CAP1,VDDA,,

- ie -- 输入使能
- oe -- 输出使能
- wpu -- 内部弱上拉电阻使能
- wpd -- 内部弱下拉电阻使能
