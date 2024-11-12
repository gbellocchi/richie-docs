*********
Tutorials
*********

=============
Prerequisites
=============
Before starting with the tutorials, remember to properly read the following documentation sections:

* :ref:`Getting started <general_getting_started>`, to learn how to retrieve the legacy components (hardware, software, tools, etc.). Please note that the **HERO installation** is only required for the compilation of the software applications;
* :ref:`Environments <general_environments>`, to learn about the development environments.

============================================================================
:smallcap:`Tutorial`—Assembling an Accelerator-Rich Computer Vision Platform
============================================================================
The following :bolditalic:`step-by-step tutorial` is meant to guide users throughout the design and specialization of a *computer vision pipeline*,
from the `AMD Vitis Accelerated Libraries <https://github.com/Xilinx/Vitis_Libraries>`_, using the :smallcap:`Richie framework`.

This example can either be run in:

- FPGA setup: :code:`Vivado 2019.2 edition` + Zynq UltraScale+ MPSoC ZCU102;
- RTL simulator: :code:`QuestaSim 10.6`.

---------------------------
Description of the Use-Case
---------------------------

.. figure:: ../img/tutorial_workload.*
  :figwidth: 75%
  :width: 75%
  :align: center

  Computer vision workload and execution model.

The use-case consists of a `colour detection pipeline <https://xilinx.github.io/Vitis_Libraries/vision/2022.1/overview.html#id8>`_ of 6 stages, 
with the following accelerated functionalities: 
`BGR to HSV conversion <https://xilinx.github.io/Vitis_Libraries/vision/2022.1/api-reference.html#bgr-to-hsv-conversion>`_, 
`thresholding <https://xilinx.github.io/Vitis_Libraries/vision/2022.1/api-reference.html#thresholding>`_, 
`erode <https://xilinx.github.io/Vitis_Libraries/vision/2022.1/api-reference.html#erode>`_ and 
`dilate <https://xilinx.github.io/Vitis_Libraries/vision/2022.1/api-reference.html#dilate>`_.
Each stage operates at OI=1 Ops/Bytes on a dataset, which includes 8 images (3-channel in, 1-channel out) at a 256x256 resolution and a memory footprint of 4MB.

More information is available in the `Vitis Vision Library documentation <https://xilinx.github.io/Vitis_Libraries/vision/2022.1/index.html>`_.

-------------------
System-Level Design
-------------------
The following steps explain how to employ the toolchain to automatically assemble various instances of the 
accelerator-rich computer vision platform.

^^^^^^^^^^^^^^^^^^
Accelerator Design
^^^^^^^^^^^^^^^^^^
During this phase, we will design and synthesize the pipeline components of the computer vision workload using :code:`Vitis HLS`.

Move to the location of the accelerators sources: 

.. code-block:: console

  cd $RICHIE_HOME_DIR/hw/accelerators/src

The pipeline components are respectively :code:`rgb2hsv_cv`, :code:`threshold_cv`, :code:`erode_cv` and :code:`dilate_cv`.
Then pick one pipeline stage at a time, run the following commands and then repeat for the others as well:

.. code-block:: console

  cd rgb2hsv_cv
  make run get_rtl

^^^^^^^^^^^^^^^^^^
System Integration
^^^^^^^^^^^^^^^^^^
During this design stage, the toolchain optimizes the :ref:`HWPE hardware-software interface <richie_platform_accelerators>`
to enable the communication between the previously designed HLS pipeline components and the :smallcap:`Richie platform`.

Move to the toolchain location and follow :ref:`this guide <richie_toolchain_how_to_install>` to adequately 
initialize the toolchain environment.

.. code-block:: console

  cd $RICHIE_HOME_DIR/sld-tools/richie-sld-toolchain

The HWPE interface is automatically generated and 
to adequately specialize the HWPE interface, the toolchain requires a high-level description 
of the accelerated functionality, i.e., an :ref:`accelerator specification file <richie_toolchain_sld_integration>`.
These are collected in the *accelerator library* under :code:`src/accelerators`. 
We have already prepared an accelerator specification for each of the previously
synthesized HLS pipeline components (:code:`rgb2hsv_cv`, :code:`threshold_cv`, :code:`erode_cv` and :code:`dilate_cv`).

Finally, the *system integration phase* is automatically run as part of the :smallcap:`Richie` SLD flow, thus we can now move to the next phase.

^^^^^^^^^^^^^^^^^^^
System Optimization
^^^^^^^^^^^^^^^^^^^
At this stage, the SLD toolchain optimizes the :smallcap:`Richie platform` to serve the integrated accelerators with 
specialized .
This phase is driven by a :ref:`platform specification file <richie_toolchain_sld_optimization>`, where are described 
the design requirements of the HeSoC components, including the clusters and the memory subsystem, as well as how 
accelerators are distributed across the platform.
These are collected in the *platform library*, under :code:`src/platforms`.
The optimization phase is also driven by the parameters of the :ref:`accelerator specification files <richie_toolchain_sld_integration>`, 
defined in the previous stage.

We have prepard more variants of the platform specification files, which consist of the many instances of the accelerator-rich computer vision platform, 
which are to be consequently evaluated during the next :bolditalic:`exploration campaign`.

In this specific tutorial, we have formatted each variant name as <:blue:`accname`\_\ :green:`nst`\_\ :orange:`ncl`\_\ :red:`nl1p`\_\ :purple:`nl2p`\>, where:

- :blue:`accname`: accelerator name (e.g., :code:`color_detect`);
- :green:`nst`: number of pipeline stages (the workload consists of 6 stages, hence :code:`6stg`);
- :orange:`ncl`: number of clusters (e.g., :code:`6cl`);
- :red:`nl1p`: number of L1 memory ports (equal for each cluster, e.g., :code:`16l1p`);
- :purple:`nl2p`: number of L2 memory ports (e.g., :code:`16l2p`).

^^^^^^^^^^^^^^^^^^^^
Running the SLD Flow
^^^^^^^^^^^^^^^^^^^^
Activate now the Python virtual environment:

.. code-block:: console

  source richie-py-env/bin/activate

Then launch the SLD flow with the following command:

.. code-block:: console

  cd $RICHIE_HOME_DIR/sld-tools/richie-sld-toolchain
  make clean all TARGET_PLATFORM=color_detect_6stg_6cl_16l1p_6l2p

The generated instance is now available under :code:`output`, including the following locations:

- :code:`accelerators`: the computer vision pipeline and the HWPE hardware-software interface;
- :code:`cluster`: SystemVerilog package and accelerator subsystem for the :smallcap:`Richie cluster`;
- :code:`hesoc`: SystemVerilog package and architecture of the :smallcap:`Richie HeSoC`;
- :code:`ip`: HeSoC wrapper for FPGA build;
- :code:`libs`: API and low-level RTE components;
- :code:`test`: RTL simulation components.

Besides, more information concerning the generation flow is also available :ref:`here <richie_toolchain_generation>`.

^^^^^^^^^^
FPGA Build
^^^^^^^^^^
A FPGA bitstream for the AMD Zynq UltraScale+ MPSoC ZCU102 is then easily built, leveraging the AMD Vivado Suite.

.. code-block:: console

  cd $RICHIE_HOME_DIR/hw
  make fpga

Our FPGA designs have been validated with the :code:`Vivado 2019.2 edition`.

--------------------
Software Application
--------------------
We can now proceed with the design of the software application, where the computer vision pipeline is executed.
Please note that, at this stage, the **installation of HERO** is mandatory, as it includes the required toolchains 
and SDK to build the heterogeneous application.

.. code-block:: console

  cd $RICHIE_HOME_DIR/sw/benchmarks/richie-acc-bench/pulp/vitis-vision/colordetect/sw

The application can be built with the following command:

.. code-block:: console

  make build TARGET=<PATH_TO_SOURCES>

*Sources* are collected under :code:`src/<TARGET_APP>/`.

..
  - :code:`main`
  - :code:`color_detect`
  - :code:`configs`

..
  Add details concerning the configs.h and its generation

The pipeline dependencies are expressed in the application using the :smallcap:`Richie` API and
managed by :ref:`the proxy core and the EU <richie_platform_cluster_fabric>`.
Their cooperation enables a fully software-defined communication paradigm, where clusters can dispatch low-cost commands 
to convey complex synchronization information, thus guaranteeing flexible control of processing and control tasks,
e.g., multi-cluster synchronization and DMA transfers.
About this, implementation examples of the API and low-level RTE components are available under :code:`common/functions/`.

..
  - :code:`cluster_synch`: support for clusters to dispatch commands and synchronize with the proxy core control scheme;
  - :code:`profiling`: enable the performance counters in the proxy core and print logs;
  - :code:`icache_stats`: enable Icache counters for profiling.

.. figure:: ../img/tutorial_synch_paradigm_pipeline.*
  :figwidth: 75%
  :width: 75%
  :align: center

  Mapping the execution model of the workload to the :smallcap:`Richie platform`.

The *computer vision benchmark* is kept under :code:`common/benchmarks/` and is structured as follows: 

.. tab-set::

   .. tab-item:: **Startup**

      #. :math:`Cluster_{\alpha}` starts executing, while the others (up to :math:`cluster_{\omega}`) sleep until they receive an SoC event with a wake-up command.

   .. tab-item:: **Executing the 1st pipeline stage**

    #. :math:`Proxy_{\alpha}` initializes and programs the first pipeline stage :math:`acc_{\alpha , 0}`;
    #. :math:`Proxy_{\alpha}` issues an L2-to-L1 transfer of the accelerator data, waits for its completion and finally triggers computation;
    #. Execution of :math:`acc_{\alpha , 0}`;
    #. Processing termination and then :math:`EU_{\alpha}` notifies :math:`proxy_{\alpha}`;
    #. :math:`Proxy_{\alpha}` issues an L1-to-L2 transfer to transfer results back to the L2 memory;
    #. Repeated as soon as the operations of :math:`acc_{\alpha , 0}` are terminated.

   .. tab-item:: **Executing the Nth pipeline stage**

    #. If the cluster integrates other stages, repeat the same procedure, up to :math:`acc_{\alpha , i}`;
    #. As soon as :math:`cluster_{\alpha}` has no other stages to execute, it forks execution to :math:`cluster_{\beta}`, which will follow the same execution model.

   .. tab-item:: **Termination**

    #. This process continues until all the stages have been executed. 

----------------
Exploration Flow
----------------
TBD

..
  The exploration focus is on find the best compromise between performance and area (FPGA resource occupation)