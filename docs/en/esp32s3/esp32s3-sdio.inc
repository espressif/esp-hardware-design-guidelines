{IDF_TARGET_NAME} only has one SD/MMC Host controller, which cannot be used as a slave device. 

The SDIO interface can be configured to any free GPIO by software. Please add pull-up resistors to the SDIO GPIO pins, and it is recommended to reserve a series resistor on each trace.