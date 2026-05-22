{IDF_TARGET_NAME} 为以太网通信提供了一个符合 IEEE-802.3 标准的媒体访问控制器 (MAC) 接口，支持通过 MII 接口、RMII 接口或 RGMII 接口与外部快速以太网 PHY 进行通信（一次仅可使用一种接口）。

接口定义和 GPIO 的对应如下：

.. list-table:: EMAC GPIO 定义
    :name: tab-emac-gpio
    :header-rows: 1
    :widths: 20 20 20 20
    :align: center

    * - GPIO 管脚
      - MII 接口管脚
      - RMII 接口管脚
      - RGMII 接口管脚
    * - GPIO8
      - MII_TXD0
      - RMII_TXD0
      - RGMII_TXD0
    * - GPIO9
      - MII_TXD1
      - RMII_TXD1
      - RGMII_TXD1
    * - GPIO10
      - MII_TXD2
      - N/A
      - RGMII_TXD2
    * - GPIO11
      - MII_TXD3
      - N/A
      - RGMII_TXD3
    * - GPIO12
      - MII_TXEN
      - RMII_TXEN
      - RGMII_TX_CTL
    * - GPIO13
      - MII_TX_CLK
      - RMII_CLK
      - RGMII_TX_CLK
    * - GPIO14
      - MII_RX_CLK
      - N/A
      - RGMII_RX_CLK
    * - GPIO15
      - MII_RXDV
      - RMII_CRS_DV
      - RGMII_RX_CTL
    * - GPIO16
      - MII_RXD3
      - N/A
      - RGMII_RXD3
    * - GPIO17
      - MII_RXD2
      - N/A
      - RGMII_RXD2
    * - GPIO18
      - MII_RXD1
      - RMII_RXD1
      - RGMII_RXD1
    * - GPIO19
      - MII_RXD0
      - RMII_RXD0
      - RGMII_RXD0
    * - 任意 GPIO
      - MII_RX_ER
      - N/A
      - N/A
    * - 任意 GPIO
      - MII_CRS
      - N/A
      - N/A
    * - 任意 GPIO
      - MII_COL
      - N/A
      - N/A
    * - 任意 GPIO
      - MDIO
      - MDIO
      - MDIO
    * - 任意 GPIO
      - MDC
      - MDC
      - MDC

- 建议在 MII/RMII/RGMII 的 CLK 线上添加串联电阻用于调节。
- RMII 接口中的时钟信号（GPIO13）仅为输入。如果需要时钟输出方案，请使用 REF_GMAC_CLK_PAD 信号（GPIO35）连接至 GPIO13 和 PHY 端。
