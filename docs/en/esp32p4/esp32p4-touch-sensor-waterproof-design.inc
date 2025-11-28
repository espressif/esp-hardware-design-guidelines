{IDF_TARGET_NAME} touch sensor has a waterproof design and features proximity sensor function. Figure :ref:`fig-touch-waterproof-design` shows an example layout of a waterproof and proximity sensing design.

.. figure:: ../_static/shared-touch-waterproof-design.png
    :name: fig-touch-waterproof-design
    :align: center
    :width: 70%
    :alt: {IDF_TARGET_NAME} Waterproof and Proximity Sensing Design

    {IDF_TARGET_NAME} Waterproof and Proximity Sensing Design

Note the following guidelines to better implement the waterproof and proximity sensing design:

- The recommended width of the shield electrode width is 2 cm.
- Employ a grid on the top layer with a trace width of 7 mil and a grid width of 45 mil (25% fill). The filled grid is connected to the driver shield signal.
- Employ a grid on the bottom layer with a trace width of 7 mil and a grid width of 70 mil (17% fill). The filled grid is connected to the driver shield signal.
- The protective sensor should be in a rectangle shape with curved edges and surround all other sensors.
- The recommended width of the protective sensor is 2 mm.
- The recommended gap between the protective sensor and shield sensor is 1 mm.
- The sensing distance of the proximity sensor is directly proportional to the area of the proximity sensor. However, increasing the sensing area will introduce more noise. Actual testing is needed for optimized performance.
- It is recommended that the shape of the proximity sensor is a closed loop. The recommended width is 1.5 mm.