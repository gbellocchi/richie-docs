*********
Toolchain
*********

.. figure:: ../img/richie_toolchain.*
  :figwidth: 90%
  :width: 90%
  :align: center

  Toolchain architecture.

============
Introduction
============
The :smallcap:`Richie toolchain` is a System-Level Design (SLD) Toolchain that automates and simplifies
the HW/SW assembling and specialization of *Accelerator-Rich Heterogeneous Systems-on-Chip (HeSoCs)*.
The Toolchain comprises a set of Python-based tools, which enables the seamless and rapid composition
of accelerators into full-fledged Accelerator-Rich HeSoCs, from a *high-level description*.
Indeed, the Toolchain supports various *accelerator design flows*, e.g., leveraging High-Level Synthesis (HLS).
Generated HeSoCs are based on the `Parallel Ultra Low Power (PULP) Platform <https://pulp-platform.org/index.html>`_,
an open-source research and development platform targeting highly parallel architectures for ultra-low-power processing
based on the RISC-V Instruction Set Architecture (ISA).
The :smallcap:`Richie toolchain` was formerly named *GenOv*.

.. include:: getting_started.rst
.. include:: sld.rst
.. include:: generation.rst
.. include:: verif.rst
.. include:: tools.rst
.. include:: external.rst
