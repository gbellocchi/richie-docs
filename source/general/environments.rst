************
Environments
************
.. _general_environments:

:smallcap:`Richie` supports various development environments, depending on the implementation target.

==================
Accelerator Design
==================

---------------------------
Vitis/Vivado HLS (Standard)
---------------------------

Tool version:

* :code:`AMD-Xilinx tools`

  * **Version**: 2019.2;
  * **Usage**: Required for HLS synthesis.

------------------------
Vitis HLS Vision Library
------------------------

Tool version:

* :code:`AMD-Xilinx tools`

  * **Version**: 2022.2;
  * **Usage**: Required for HLS synthesis.

* :code:`OpenCV`

  * **Version**: OpenCV-4.4.0 x86 libraries;
  * **Usage**: Required for synthesizing Vision kernels;
  * **Installation**: Refer to the `Vitis Vision Library documentation <https://github.com/Xilinx/Vitis_Libraries/blob/main/vision/README.md>`_.

==========
Deployment
==========

-------------
Xilinx ZCU102
-------------
A complete Linux environment with kernel and the base root filesystem for the ARMv8 host on the Xilinx Zynq UltraScale+ MPSoC ZCU102

--------------
RTL Simulation
--------------
An environment is provided to simulate the accelerator in RTL.
Specify a QuestaSim license through the LM_LICENSE_FILE variable in :code:`env/setup_esim.sh`.
