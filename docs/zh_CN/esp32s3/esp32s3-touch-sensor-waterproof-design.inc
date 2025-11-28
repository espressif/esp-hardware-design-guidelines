{IDF_TARGET_NAME} 新增硬件防水和接近传感器功能，图 :ref:`fig-touch-waterproof-design` 为防水和接近传感器参考的布局。

.. figure:: ../_static/shared-touch-waterproof-design__cn.png
    :name: fig-touch-waterproof-design
    :align: center
    :width: 70%
    :alt: {IDF_TARGET_NAME} 防水和接近传感器参考布局

    {IDF_TARGET_NAME} 防水和接近传感器参考布局

为更好实现上述功能，请注意以下事项：

- 屏蔽电极的宽度建议 2 cm。
- 顶层填充网格，走线宽度为 7 mil，网格宽度为 45 mil（25% 填充），填充的网格与驱动屏蔽信号连接。
- 底层填充网格，走线宽度为 7 mil，网格宽度为 70 mil（17% 填充），填充的网格与驱动屏蔽信号连接。
- 建议保护传感器应为弯曲边缘的矩形，包围其他所有传感器。
- 保护传感器宽度建议为 2 mm。
- 保护传感器与屏蔽传感器宽度间隙建议为 1 mm。
- 接近传感器的感应距离与接近传感器的面积成正比，但增大感应面积也会带来更大噪声，需实际测试。
- 接近传感器形状建议为闭合环状。宽度建议为 1.5 mm。