Figure :ref:`fig-external-capacitor-schematic` shows the schematic of components connected to pin47 CAP2 and pin48 CAP1.

C5 (10 nF) that connects to CAP1 should be of 10% tolerance and is required for proper operation of ESP32.

RC circuit between CAP1 and CAP2 pins may be omitted under certain conditions. This circuit is used when entering Deep-sleep mode. During this process, to minimize power consumption, the voltage to power ESP32 internals is dropped from 1.1 V to around 0.7 V. The RC circuit is used to minimize the period of the voltage drop. If removed, this process will take longer and the power consumption in Deep-sleep will be higher. If particular application of ESP32 is not using Deep-sleep mode, or power consumption is less critical, then this circuit is not required.

.. figure:: ../_static/{IDF_TARGET_PATH_NAME}/{IDF_TARGET_PATH_NAME}-sche-external-capacitor.png
   :name: fig-external-capacitor-schematic
   :align: center
   :width: 50%
   :alt: {IDF_TARGET_NAME} Schematic for External Capacitor

   {IDF_TARGET_NAME} Schematic for External Capacitor