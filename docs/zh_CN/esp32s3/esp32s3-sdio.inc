{IDF_TARGET_NAME} 系列芯片只有一个 SD/MMC 主机控制器，不能用做从机。

SDIO 接口可以通过软件配置到任意空闲的 GPIO 上，请在 SDIO GPIO 管脚处添加上拉电阻，建议每根线上预留一个串联的电阻。