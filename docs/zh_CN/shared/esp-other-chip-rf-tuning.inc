{IDF_TARGET_CONJUGATE_POINT_VALUE:default="35+j0", esp32="25+j0", esp32c2="30+j0", esp32c5="(40 ~ 45)+j0（2.4 GHz）或 (50 ~ 65)+j0（5 GHz）"}

{IDF_TARGET_S21_FREQ:default=" 4.8 GHz 和 7.2 GHz ", esp32c5="二次和三次谐波"}

.. figure:: ../_static/shared-rf-tuning.png
   :name: fig-rf-tuning
   :align: center
   :width: 90%
   :alt: {IDF_TARGET_NAME} 射频调试示意图

   {IDF_TARGET_NAME} 射频调试示意图

将芯片匹配电路靠近芯片的端口定义为端口 1，将其靠近天线的端口定义为端口 2，则 S11 用来描述从端口 1 反射回来的信号功率与输入信号功率之比，如果匹配阻抗与芯片阻抗共轭，则传输性能最佳。S21 用来描述从端口 1 到端口 2 的信号功率传输损耗。如果 S11 接近芯片共轭阻抗点 {IDF_TARGET_CONJUGATE_POINT_VALUE}，且 S21 在{IDF_TARGET_S21_FREQ}频率下小于 -35 dB，则匹配电路可满足传输要求。

将芯片匹配电路的两端分别接到综测仪上，测试其信号反射参数 S11 及传输参数 S21。调试该匹配电路中元件的数值，直至 S11 和 S21 满足上述要求。如果芯片的 PCB 板严格设计遵循章节 :ref:`pcb-layout-design` 里的规范，用户可以参考表 :ref:`tab-recommended-value-ranges-components` 来调试该匹配电路。

.. only:: not esp32c5

    .. list-table:: 匹配电路元器件推荐数值范围
        :name: tab-recommended-value-ranges-components
        :header-rows: 1
        :widths: 20 40 40
        :align: center

        * - 位号
          - 推荐数值范围
          - 物料编号
        * - C11
          - 1.2 ~ 1.8 pF
          - GRM0335C1H1RXBA01D
        * - L2
          - 2.4 ~ 3.0 nH
          - LQP03TN2NXB02D
        * - C12
          - 1.8 ~ 1.2 pF
          - GRM0335C1H1RXBA01D

    射频匹配器件请采用 0201 物料，芯片端匹配电路的第一个电容需要添加枝节。

.. only:: esp32c5

    .. list-table:: 匹配电路元器件推荐数值范围
        :name: tab-recommended-value-ranges-components
        :header-rows: 1
        :widths: 10 30 30 30
        :align: center

        * - 位号
          - 2.4 GHz 推荐数值范围
          - 5 GHz 推荐数值范围
          - 物料编号
        * - C11
          - 1.2 ~ 3.0 pF
          - 0.2 ~ 1.5 pF
          - GRM0335C1H1RXBA01D
        * - L2
          - 2.4 ~ 3.0 nH
          - 0 ~ 3 nH
          - LQP03TN2NXB02D
        * - C12
          - 1.2 ~ 3.0 pF
          - 0.2 ~ 1.5 pF
          - GRM0335C1H1RXBA01D

    推荐射频匹配器件采用 0201 物料，芯片端 5 GHz 匹配电路的第一个电容需要添加枝节。