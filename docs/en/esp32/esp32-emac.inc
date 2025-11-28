{IDF_TARGET_NAME} provides a media access control (MAC) interface that complies with the IEEE-802.3-2008 standard for Ethernet communication. The `ESP32-Ethernet-Kit board <https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/esp32-ethernet-kit/index.html>`_ only supports the Reduced Media-Independent Interface (RMII). The allocation of the {IDF_TARGET_NAME} pins to the RMII interface is shown in the table below.

.. csv-table:: Ethernet MAC
    :header-rows: 1

    Pin Name,Function 6,RMII (int_osc),RMII (ext_osc)
    GPIO0,EMAC_TX_CLK,CLK_OUT(O),EXT_OSC_CLK(I)
    GPIO21,EMAC_TX_EN,TX_EN(O),TX_EN(O)
    GPIO19,EMAC_TXD0,TXD[0](O),TXD[0](O)
    GPIO22,EMAC_TXD1,TXD[1](O),TXD[1](O)
    GPIO27,EMAC_RX_DV,CRS_DV(I),CRS_DV(I)
    GPIO25,EMAC_RXD0,RXD[0](I),RXD[0](I)
    GPIO26,EMAC_RXD1,RXD[1](I),RXD[1](I)
    GPIO16,EMAC_CLK_OUT,CLK_OUT(O),–
    GPIO17,EMAC_CLK_OUT_180,CLK_OUT_180(O),–
    Any GPIO,–,MDC(O),MDC(O)
    Any GPIO,–,MDIO(IO),MDIO(IO)

For an Ethernet solution, it is recommended to use GPIO0 as the clock input. Be aware that GPIO0 also acts as a strapping pin and it can be affected by the clock during chip power-up and may enter download mode as a result. Therefore, make sure you have turned off the clock output on the PHY side before powering up the chip. The ESP32-Ethernet-Kit board uses GPIO to control PHY's reset pin and turn off the clock output. However, not all PHYs support this design, so it is crucial to verify functionality during testing. If this design cannot be implemented, consider alternative methods to ensure that GPIO0 remains unaffected during power-up. For a reference design please see `ESP32-Ethernet-Kit User Guide <https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/esp32-ethernet-kit/index.html>`_.

If you need to use Wi-Fi and Ethernet simultaneously, do not use the internal APLL clock to generate the RMII clock, as this can lead to clock instability. Instead, use the RMII clock from the PHY side or an external clock source. For further details, please refer to `ESP32-Ethernet-Kit User Guide <https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/esp32-ethernet-kit/index.html>`_ > `RMII Clock Selection <https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/esp32-ethernet-kit/user_guide.html#rmii-clock-selection>`_.