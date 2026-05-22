The {IDF_TARGET_NAME} LCD_CAM controller contains a separate LCD control module and a Camera control module. It can connect to external LCD and camera devices.

The LCD and CAM interfaces of the LCD_CAM controller can be configured to use any GPIO pin via the GPIO matrix. For high-speed requirements, please use the GPIOs defined in the IO MUX, as shown in the table below.

.. list-table:: LCD IO MUX Interface Definition
    :name: tab-lcd-iomux
    :header-rows: 1
    :widths: 20 20 20 20
    :align: center

    * - GPIO Pin
      - Parallel LCD Interface Pin
      - RGB 888 Interface Pin
      - RGB565 Interface Pin
    * - GPIO2
      - LCD_DATA19
      - R3
      - –
    * - GPIO3
      - LCD_DATA20
      - R4
      - –
    * - GPIO4
      - LCD_DATA21
      - R5
      - –
    * - GPIO5
      - LCD_DATA22
      - R6
      - –
    * - GPIO7
      - LCD_DATA23
      - R7
      - –
    * - GPIO8
      - LCD_DATA0
      - B0
      - B3
    * - GPIO9
      - LCD_DATA1
      - B1
      - B4
    * - GPIO10
      - LCD_DATA2
      - B2
      - B5
    * - GPIO11
      - LCD_DATA3
      - B3
      - B6
    * - GPIO12
      - LCD_DATA4
      - B4
      - B7
    * - GPIO13
      - LCD_DATA5
      - B5
      - G2
    * - GPIO14
      - LCD_DATA6
      - B6
      - G3
    * - GPIO15
      - LCD_DATA7
      - B7
      - G4
    * - GPIO16
      - LCD_DATA8
      - G0
      - G5
    * - GPIO17
      - LCD_DATA9
      - G1
      - G6
    * - GPIO18
      - LCD_DATA10
      - G2
      - G7
    * - GPIO19
      - LCD_DATA11
      - G3
      - R3
    * - GPIO33
      - LCD_DATA12
      - G4
      - R4
    * - GPIO34
      - LCD_DATA13
      - G5
      - R5
    * - GPIO35
      - LCD_DATA14
      - G6
      - R6
    * - GPIO36
      - LCD_DATA15
      - G7
      - R7
    * - GPIO37
      - LCD_DATA16
      - R0
      - –
    * - GPIO38
      - LCD_DATA17
      - R1
      - –
    * - GPIO39
      - LCD_DATA18
      - R2
      - –
    * - GPIO40
      - LCD_PCLK
      - LCD_PCLK
      - LCD_PCLK
    * - GPIO43
      - LCD_H_ENABLE
      - LCD_H_ENABLE
      - LCD_H_ENABLE
    * - GPIO44
      - LCD_H_SYNC
      - LCD_H_SYNC
      - LCD_H_SYNC
    * - GPIO45
      - LCD_V_SYNC
      - LCD_V_SYNC
      - LCD_V_SYNC

.. list-table:: Camera IO MUX Interface Definition
    :name: tab-cam-iomux
    :header-rows: 1
    :widths: 50 50
    :align: center

    * - GPIO Pin
      - Camera Interface Pin
    * - GPIO46
      - CAM_DATA0
    * - GPIO47
      - CAM_DATA1
    * - GPIO48
      - CAM_DATA2
    * - GPIO49
      - CAM_DATA3
    * - GPIO50
      - CAM_DATA4
    * - GPIO51
      - CAM_DATA5
    * - GPIO52
      - CAM_DATA6
    * - GPIO53
      - CAM_DATA7
    * - GPIO54
      - CAM_PCLK
    * - GPIO55
      - CAM_XCLK
    * - GPIO56
      - CAM_V_SYNC
    * - GPIO57
      - CAM_H_SYNC
