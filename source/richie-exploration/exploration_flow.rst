================
Exploration flow
================

.. figure:: ../img/richie_exploration.*
  :figwidth: 75%
  :width: 75%
  :align: center

  Exploration flow.

During an :bolditalic:`exploration campaign`, many platform variants are profiled to determine the most convenient one for a given application.
The :bolditalic:`exploration flow` thus consists of a sequence of hardware-software co-design stages, which are mostly automated (:smallcap:`[auto]`):

#. Define a set of :bolditalic:`design-time knobs`, meaning the desired platform parameters specified in the :ref:`accelerator <richie_toolchain_sld_integration>` and :ref:`platform specification files <richie_toolchain_sld_optimization>`;
#. :smallcap:`[auto]` Launch the :ref:`generation flow <richie_toolchain_generation>` to obtain a specialized instance of the :smallcap:`Richie platform`;
#. :smallcap:`[auto]` Build the FPGA bitstream;
#. Develop the SW application employing the :ref:`heterogeneous stack and the OpenMP-based interface <richie_platform_heterogeneous_stack>`;
#. :smallcap:`[auto]` Profile the generated platform instance and retrieve results (performance, area).

This procedure is repeated for all the platform descriptions (i.e., sets of knobs) that the user intends to consider.