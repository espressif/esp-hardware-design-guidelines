{IDF_TARGET_CONJUGATE_POINT_VALUE:default="35+j0", esp32="25+j0", esp32c2="30+j0", esp32c5="(40 ~ 45)+j0 (2.4 GHz) or (50 ~ 65)+j0 (5 GHz)"}

{IDF_TARGET_S21_FREQ:default="4.8 GHz and 7.2 GHz", esp32c5="2nd and 3rd harmonics"}

.. figure:: ../_static/shared-rf-tuning.png
   :name: fig-rf-tuning
   :align: center
   :width: 90%
   :alt: {IDF_TARGET_NAME} RF Tuning Diagram

   {IDF_TARGET_NAME} RF Tuning Diagram

In the matching circuit, define the port near the chip as Port 1 and the port near the antenna as Port 2. S11 describes the ratio of the signal power reflected back from Port 1 to the input signal power, the transmission performance is best if the matching impedance is conjugate to the chip impedance. S21 is used to describe the transmission loss of signal from Port 1 to Port 2. If S11 is close to the chip conjugate point {IDF_TARGET_CONJUGATE_POINT_VALUE} and S21 is less than -35 dB at {IDF_TARGET_S21_FREQ}, the matching circuit can satisfy transmission requirements.

Connect the two ends of the matching circuit to the network analyzer, and test its signal reflection parameter S11 and transmission parameter S21. Adjust the values of the components in the circuit until S11 and S21 meet the requirements. If your PCB design of the chip strictly follows the PCB design stated in Chapter :ref:`pcb-layout-design`, you can refer to the value ranges in Table :ref:`tab-recommended-value-ranges-components` to debug the matching circuit.

.. only:: not esp32c5

    .. list-table:: Recommended Value Ranges for Components
        :name: tab-recommended-value-ranges-components
        :header-rows: 1
        :widths: 20 40 40
        :align: center

        * - Reference Designator
          - Recommended Value Range
          - Serial No.
        * - C11
          - 1.2 ~ 1.8 pF
          - GRM0335C1H1RXBA01D
        * - L2
          - 2.4 ~ 3.0 nH
          - LQP03TN2NXB02D
        * - C12
          - 1.8 ~ 1.2 pF
          - GRM0335C1H1RXBA01D

    Please use 0201 packages for RF matching components and add a stub to the first capacitor in the matching circuit at the chip end.

.. only:: esp32c5

    .. table:: Recommended Value Ranges for Components
        :name: tab-recommended-value-ranges-components

        +--------------------------+------------------------+------------------------+----------------------------+
        | **Reference Designator** | **Recommended Value**  | **Recommended Value**  | **Serial No.**             |
        |                          | **Range for 2.4 GHz**  | **Range for 5 GHz**    |                            |
        +--------------------------+------------------------+------------------------+----------------------------+
        | C11                      | 1.2 ~ 3.0 pF           | 0.2 ~ 1.5 pF           | GRM0335C1H1RXBA01D         |
        +--------------------------+------------------------+------------------------+----------------------------+
        | L2                       | 2.4 ~ 3.0 nH           | 0 ~ 3 nH               | LQP03TN2NXB02D             |
        +--------------------------+------------------------+------------------------+----------------------------+
        | C12                      | 1.2 ~ 3.0 pF           | 0.2 ~ 1.5 pF           | GRM0335C1H1RXBA01D         |
        +--------------------------+------------------------+------------------------+----------------------------+

    It is recommended to use RF matching components in the 0201 SMD package size. Please add a stub for the first capacitor in the 5 GHz matching circuit on the chip side.