产品概述
============

:link_to_translation:`en:[English]`

{IDF_TARGET_NAME} 系列芯片支持以下功能：

.. include:: {IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-features.inc

.. only:: not esp32p4

    {IDF_TARGET_NAME} 采用低功耗 40 纳米工艺，具有超高的射频性能、稳定性、通用性和可靠性，以及超低的功耗，满足不同的功耗需求，适用于各种应用场景。{IDF_TARGET_NAME} 的典型应用包括：

.. only:: esp32p4

    {IDF_TARGET_NAME} 采用低功耗 40 纳米工艺，具有超高的稳定性、通用性和可靠性，以及超低的功耗，满足不同的功耗需求，适用于各种应用场景。{IDF_TARGET_NAME} 的典型应用包括：

.. list::

    - 智能家居
    - 工业自动化
    - 医疗保健
    - 消费电子产品
    - 智慧农业
    - POS 机
    - 服务机器人
    :not esp32h2 and not esp32c2: - 音频设备
    - 通用低功耗 IoT 传感器集线器
    - 通用低功耗 IoT 数据记录器
    :esp32 or esp32s3 or esp32s2 or esp32p4: - 摄像头视频流传输
    :esp32s3 or esp32s2 or esp32p4: - USB 设备
    :esp32 or esp32s3 or esp32s2 or esp32p4: - 语音识别
    :esp32 or esp32s3 or esp32s2 or esp32p4: - 图像识别
    :esp32: - SDIO Wi-Fi + 蓝牙网卡
    :esp32s3 or esp32c5: - Wi-Fi + 蓝牙网卡
    :esp32 or esp32s3 or esp32s2 or esp32p4: - 触摸和接近感应

.. only:: not esp32c5 and not esp32p4

    更多关于 {IDF_TARGET_NAME} 系列芯片说明请参考 `{IDF_TARGET_NAME} 系列芯片技术规格书 <{IDF_TARGET_DATASHEET_CN_URL}>`__。

.. only:: not esp32c6

    .. note::
        除非特别说明，文中使用的“{IDF_TARGET_NAME}”指的是 {IDF_TARGET_NAME} 系列芯片，而非单一型号。