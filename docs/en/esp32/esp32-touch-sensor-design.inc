{IDF_TARGET_TOUCH_IO_NUM:default="to be defined", esp32="10", esp32s3="14", esp32s2="14", esp32p4="14"}

{IDF_TARGET_NAME} offers up to {IDF_TARGET_TOUCH_IO_NUM} capacitive IOs that detect changes in capacitance on touch sensors due to finger contact or proximity. The chip's internal capacitance detection circuit features low noise and high sensitivity. It allows to use touch pads with smaller area to implement the touch detection function. You can also use the touch panel array to detect a larger area or more test points.

Figure :ref:`fig-touch-design` depicts a typical touch sensor application.

.. figure:: ../_static/shared-touch-design.png
    :name: fig-touch-design
    :align: center
    :width: 70%
    :alt: {IDF_TARGET_NAME} Typical Touch Sensor Application

    {IDF_TARGET_NAME} Typical Touch Sensor Application

To prevent capacitive coupling and other electrical interference to the sensitivity of the touch sensor system, the following factors should be taken into account.