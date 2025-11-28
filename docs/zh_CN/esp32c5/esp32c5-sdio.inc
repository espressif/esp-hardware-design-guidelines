{IDF_TARGET_NAME} 系列芯片只有一个 SDIO 从机控制器，符合工业标准 SDIO 2.0 规格。SDIO GPIO 是固定的，即 SDIO_CMD/GPIO10、SDIO_CLK/GPIO9、SDIO_DATA0/GPIO8、SDIO_DATA1/GPIO7、SDIO_DATA2/GPIO14 和 SDIO_DATA3/GPIO13。请在 SDIO GPIO 管脚处添加上拉电阻，建议每根线上预留一个串联电阻。

.. note::

    芯片版本 v1.0 支持该外设，v0.1 暂不可用。
