.. list-table:: Power-Up Glitches on Pins
   :name: tab-glitches-on-pins
   :header-rows: 1
   :widths: 30 50 20
   :align: center

   * - Pin
     - Glitch [3]_
     - Typical Time (µs)
   * - GPIO1
     - Low-level glitch
     - 60
   * - GPIO2
     - Low-level glitch
     - 60
   * - GPIO3
     - Low-level glitch
     - 60
   * - GPIO4
     - Low-level glitch
     - 60
   * - GPIO5
     - Low-level glitch
     - 60
   * - GPIO6
     - Low-level glitch
     - 60
   * - GPIO7
     - Low-level glitch
     - 60
   * - GPIO8
     - Low-level glitch
     - 60
   * - GPIO9
     - Low-level glitch
     - 60
   * - GPIO10
     - Low-level glitch
     - 60
   * - GPIO11
     - Low-level glitch
     - 60
   * - GPIO12
     - Low-level glitch
     - 60
   * - GPIO13
     - Low-level glitch
     - 60
   * - GPIO14
     - Low-level glitch
     - 60
   * - XTAL_32K_P
     - Low-level glitch
     - 60
   * - XTAL_32K_N
     - Low-level glitch
     - 60
   * - GPIO17
     - Low-level glitch
     - 60
   * - GPIO18
     - Low-level/High-level glitch
     - 60
   * - GPIO19
     - Low-level glitch/High-level glitch [4]_
     - 60
   * - GPIO20
     - Pull-down glitch/High-level glitch [4]_
     - 60

.. [3]

    - Low-level glitch: the pin is at a low level output status during the time period;
    - High-level glitch: the pin is at a high level output status during the time period;
    - Pull-down glitch: the pin is at an internal weak pulled-down status during the time period;
    - Pull-up glitch: the pin is at an internal weak pulled-up status during the time period.

.. [4] GPIO19 and GPIO20 pins both have two high-level glitches during chip power-up, each lasting for about 60 µs. The total duration for the glitches and the delay are 3.2 ms and 2 ms respectively for GPIO19 and GPIO20.
