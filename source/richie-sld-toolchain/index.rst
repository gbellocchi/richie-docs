*************
SLD toolchain
*************
.. _richie_toolchain_index:

.. figure:: ../img/richie_sld_toolchain.*
  :figwidth: 90%
  :width: 90%
  :align: center

  SLD toolchain architecture.

============
Introduction
============
The :smallcap:`Richie SLD toolchain` is a :bolditalic:`System-Level Design (SLD) toolchain` that automates and simplifies
the hardware-software *assembling* and *specialization* of accelerator-rich HeSoCs.
The *toolchain* comprises a set of Python-based tools, which enables the seamless and rapid composition
of accelerators into full-fledged accelerator-rich HeSoCs, from a *high-level description*.
Indeed, the *toolchain* supports various :bolditalic:`accelerator design flows`, e.g., based on High-Level Synthesis (HLS).
Generated HeSoCs are based on the `Parallel Ultra Low Power (PULP) Platform <https://pulp-platform.org/index.html>`_,
an open-source research and development platform targeting highly parallel architectures for ultra-low-power processing
based on the RISC-V ISA.
The :smallcap:`Richie SLD toolchain` was formerly named :smallcap:`GenOv`.

.. include:: getting_started.rst
.. include:: sld.rst
.. include:: generation.rst
.. include:: verif.rst
.. include:: tools.rst
.. include:: external.rst
