{IDF_TARGET_NAME} provides an IEEE-802.3 compliant Media Access Controller (MAC) interface for Ethernet communication. It supports communication with an external fast Ethernet PHY through the MII, RMII, or RGMII interface (only one interface can be used at a time).

The interface definitions and the corresponding GPIOs are listed below:

.. list-table:: EMAC GPIO Definition
    :name: tab-emac-gpio
    :header-rows: 1
    :widths: 20 20 20 20
    :align: center

    * - GPIO Pin
      - MII Interface Pin
      - RMII Interface Pin
      - RGMII Interface Pin
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
    * - Any GPIO
      - MII_RX_ER
      - N/A
      - N/A
    * - Any GPIO
      - MII_CRS
      - N/A
      - N/A
    * - Any GPIO
      - MII_COL
      - N/A
      - N/A
    * - Any GPIO
      - MDIO
      - MDIO
      - MDIO
    * - Any GPIO
      - MDC
      - MDC
      - MDC

- It is recommended to add a series resistor on the MII/RMII/RGMII CLK line for tuning.
- The clock signal on the RMII interface (GPIO13) is input only. If a clock output scheme is needed, please use the REF_GMAC_CLK_PAD signal (GPIO35) and connect it to GPIO13 and the PHY side.
