{IDF_TARGET_NAME} 系列芯片只有一个 SDIO 从机控制器，符合工业标准 SDIO 2.0 规格。

SDIO GPIO 是固定的，即 SDIO_CMD、SDIO_CLK、SDIO_DATA0、SDIO_DATA1、SDIO_DATA2 和 SDIO_DATA3。请在 SDIO GPIO 管脚处添加上拉电阻，建议每根线上预留一个串联电阻。
