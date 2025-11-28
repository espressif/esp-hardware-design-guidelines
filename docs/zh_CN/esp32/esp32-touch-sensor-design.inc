{IDF_TARGET_TOUCH_IO_NUM:default="待定", esp32="10", esp32s3="14", esp32s2="14", esp32p4="14"}

{IDF_TARGET_NAME} 提供多达 {IDF_TARGET_TOUCH_IO_NUM} 个电容式传感 IO，能够探测由手指或其他物品直接接触或接近而产生的电容差异。这种设计具有低噪声和高灵敏度的特点，可以用于支持使用相对较小的触摸板。矩阵按键的设计可以得到更多的触摸点。接近感应的设计可以检测到人体的接近。

图 :ref:`fig-touch-design` 为典型触摸传感应用。

.. figure:: ../_static/shared-touch-design__cn.png
    :name: fig-touch-design
    :align: center
    :width: 70%
    :alt: {IDF_TARGET_NAME} 典型的触摸传感器应用

    {IDF_TARGET_NAME} 典型的触摸传感器应用

为防止电容耦合和其他电干扰影响触摸传感系统的灵敏度，需要考虑以下因素：