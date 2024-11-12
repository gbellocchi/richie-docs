************
Environments
************
.. _general_environments:

:smallcap:`Richie` supports various development environments, depending on the implementation target.

========================
Local Configuration File
========================

Create a :code:`local.cfg` file at the root of the :smallcap:`Richie` repository and include the following fields:

* :code:`TARGET_PLATFORM`: *Name of the target platform*, which corresponds to the :code:`name` field of a :ref:`platform specification file <richie_toolchain_sld_optimization>`;
* :code:`BR2_RICHIE_BITSTREAM`: *Absolute path to the FPGA bitstream*, included in the FPGA build of the target platform;
* :code:`BR2_RICHIE_XSA`: *Absolute path to the XSA file*, included in the FPGA build of the target platform.

This file must be updated everytime a field changes, e.g., when the FPGA should be configured with a different bitstream from the one specified by :code:`BR2_RICHIE_BITSTREAM`.

====================
List of Environments
====================

-----------------------------------------------------
Accelerator Design :octicon:`rocket;1em;sd-text-info`
-----------------------------------------------------
.. _general_environments_accelerator_design:

.. dropdown:: Vivado HLS (Standard) 

  *Description*: HLS synthesis tested with the following setup. |br|
  *Tool*: Vivado HLS 2019.2 (Vitis HLS is also supported, but not tested for all accelerators).

.. dropdown:: Vitis HLS Vision Library

  *Description*: HLS synthesis for Vitis HLS Vision accelerators. |br|
  *Tool*: Vitis HLS 2022.2. |br|
  *Deps*: `Vitis Vision Library <https://github.com/Xilinx/Vitis_Libraries/blob/main/vision/README.md>`_, `OpenCV 4.4.0 <https://github.com/Xilinx/Vitis_Libraries/blob/main/vision/README.md#opencv-installation-guidance>`_. |br|
  *Sourcing the environment*:
  From the root of the :smallcap:`Richie` repository, open the script :code:`env/setups/vitis_hls_vision.sh` and define:

  - :code:`vitis_install_path`: Environment variable, including the path to the Vitis build directory, e.g., "export vitis_install_path=some/path/Vitis/2022.2".
  - :code:`opencv_install_path`: Environment variable, including the path to your OpenCV directory, e.g., "export opencv_install_path=some/path/opencv".

  Then, execute :code:`source env/richie_user_setup.sh` at the root of the :smallcap:`Richie` repository and select the development environment :code:`vitis_hls_vision`.

------------------------------------------------
FPGA Development :octicon:`cpu;1em;sd-text-info`
------------------------------------------------

.. dropdown:: Xilinx ZCU102

  *Description*: A complete Linux environment with kernel and the base root filesystem for 
  the ARMv8 host on the Xilinx Zynq UltraScale+ MPSoC ZCU102. |br|
  *Tool*: Vivado 2019.2.

--------------------------------------------
Simulation :octicon:`tools;1em;sd-text-info`
--------------------------------------------

.. dropdown:: RTL Simulation

  *Description*: RTL simulation environment. |br|
  *Tool*: QuestaSim 10.6 (or 10.5).