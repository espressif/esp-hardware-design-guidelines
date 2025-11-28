{IDF_TARGET_NAME} 的管脚 47 CAP2 和管脚 48 CAP1 的连接电路见图 :ref:`fig-external-capacitor-schematic`。

CAP1 所连的 C5 (10 nF) 是保证 {IDF_TARGET_NAME} 正常工作的必要器件，不能移除，且精度应在 10% 以内。

CAP1 与 CAP2 之间的 RC 电路在特定条件下可以取消。这部分电路用于在 Deep-sleep 模式下缩短芯片内部电压降（从 1.1 V 降到 0.7 V）的时间，以将功耗降至最低。移除这部分电路会导致电压降的时间变长，功耗增加。如果应用场景中不需要 Deep-sleep 模式或者对于功耗的要求不高，则可以移除这部分电路。

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-external-capacitor.png
   :name: fig-external-capacitor-schematic
   :align: center
   :width: 50%
   :alt: {IDF_TARGET_NAME} 外置电容电路图

   {IDF_TARGET_NAME} 外置电容电路图