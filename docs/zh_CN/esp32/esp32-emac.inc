{IDF_TARGET_NAME} 为以太网通信提供了一个符合 IEEE-802.3-2008 标准的媒体访问控制器 (MAC) 接口，当前 `ESP32-Ethernet-Kit <https://docs.espressif.com/projects/esp-dev-kits/zh_CN/latest/esp32/esp32-ethernet-kit/index.html>`_ 开发板方案只支持 RMII 接口，接口定义和 GPIO 的对应如下：

.. csv-table:: Ethernet MAC
    :header-rows: 1

    管脚名称,功能 6,RMII (int_osc),RMII (ext_osc)
    GPIO0,EMAC_TX_CLK,CLK_OUT(O),EXT_OSC_CLK(I)
    GPIO21,EMAC_TX_EN,TX_EN(O),TX_EN(O)
    GPIO19,EMAC_TXD0,TXD[0](O),TXD[0](O)
    GPIO22,EMAC_TXD1,TXD[1](O),TXD[1](O)
    GPIO27,EMAC_RX_DV,CRS_DV(I),CRS_DV(I)
    GPIO25,EMAC_RXD0,RXD[0](I),RXD[0](I)
    GPIO26,EMAC_RXD1,RXD[1](I),RXD[1](I)
    GPIO16,EMAC_CLK_OUT,CLK_OUT(O),–
    GPIO17,EMAC_CLK_OUT_180,CLK_OUT_180(O),–
    任意 GPIO,–,MDC(O),MDC(O)
    任意 GPIO,–,MDIO(IO),MDIO(IO)

对于以太网方案，推荐使用 GPIO0 作为时钟输入。请注意，GPIO0 是一个 strapping 管脚，上电时如果受到时钟信号的影响，可能会进入下载模式。因此，需在 PHY 上电时避免输出时钟。我们的开发板设计通过使用 GPIO 控制 PHY 的复位管脚，确保上电时没有时钟输出。但并非所有的 PHY 都具备此功能，因此建议您在实际测试中确认。如果这种方法不起作用，请尝试其他方式确保 GPIO0 在上电时不被时钟干扰。开发板设计请参阅 `ESP32-Ethernet-Kit 用户指南 <https://docs.espressif.com/projects/esp-dev-kits/zh_CN/latest/esp32/esp32-ethernet-kit/index.html>`_。

此外，请注意，如果同时使用以太网和 Wi-Fi，RMII 时钟只能由 PHY 提供或由外部时钟源提供，因为 {IDF_TARGET_NAME} 内部 APLL 提供的 RMII 时钟不够稳定。更多信息请参考 `ESP32-Ethernet-Kit 用户指南 <https://docs.espressif.com/projects/esp-dev-kits/zh_CN/latest/esp32/esp32-ethernet-kit/index.html>`_ > `RMII 时钟源选择 <https://docs.espressif.com/projects/esp-dev-kits/zh_CN/latest/esp32/esp32-ethernet-kit/user_guide.html#rmii>`_。