.. only:: esp32

    The voltage ripple is not large, but the TX performance of RF is rather poor.
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    **Analysis:** The voltage ripple has a strong impact on the RF TX performance. It should be noted that the ripple must be tested when {IDF_TARGET_NAME} is in the normal working mode. The ripple increases when the power gets high in a different mode.

    Generally, the peak-to-peak value of the ripple should be <80 mV when {IDF_TARGET_NAME} sends MCS7\@11n packets, and <120 mV when {IDF_TARGET_NAME} sends 11 MHz\@11b packets.

    **Solution:** Add a 10 μF filter capacitor to the branch of the power trace (the branch powering the chip's analog power pin). The 10 μF capacitor should be as close to the analog power pin as possible for small and stable voltage ripples.

When {IDF_TARGET_NAME} sends data packages, the voltage ripple is small, but RF TX performance is poor.
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Analysis:** The RF TX performance can be affected not only by voltage ripples, but also by the crystal itself. Poor quality and big frequency offsets of the crystal decrease the RF TX performance. The crystal clock may be corrupted by other interfering signals, such as high-speed output or input signals. In addition, high-frequency signal traces, such as the SDIO traces and UART traces under the crystal, could also result in the malfunction of the crystal. Besides, sensitive components or radiating components, such as inductors and antennas, may also decrease the RF performance.

**Solution:** This problem is caused by improper layout for the crystal and can be solved by re-layout. Please refer to Section :ref:`Crystal <crystal-layout>` for details.

When {IDF_TARGET_NAME} sends data packages, the power value is much higher or lower than the target power value, and the EVM is relatively poor.
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Analysis:** The disparity between the tested value and the target value may be due to signal reflection caused by the impedance mismatch on the transmission line connecting the RF pin and the antenna. Besides, the impedance mismatch will affect the working state of the internal PA, making the PA prematurely access the saturated region in an abnormal way. The EVM becomes poor as the signal distortion happens.

**Solution:** Match the antenna's impedance with the π-type circuit on the RF trace, so that the impedance of the antenna as seen from the RF pin matches closely with that of the chip. This reduces reflections to the minimum.

TX performance is not bad, but the RX sensitivity is low.
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Analysis:** Good TX performance indicates proper RF impedance matching. Poor RX sensitivity may result from external coupling to the antenna. For instance, the crystal signal harmonics could couple to the antenna. If the TX and RX traces of UART cross over with RF trace, they will affect the RX performance, as well. If there are many high-frequency interference sources on the board, signal integrity should be considered.

**Solution:** Keep the antenna away from crystals. Do not route high-frequency signal traces close to the RF trace. Please refer to Section :ref:`RF <rf-layout>` for details.