##################
:smallcap:`Richie`
##################

.. figure:: img/richie.*
  :figwidth: 90%
  :width: 90%
  :align: center

  The :smallcap:`Richie` framework.
  
:smallcap:`Richie` is an open-source **System-Level Design (SLD) framework**, which is meant to facilitate
the *assembling* and *specialization* of accelerator-rich Heterogeneous Systems-on-Chip (HeSoCs).
The project consists of the following key components:

- :smallcapbold:`Platform`—Modular and composable accelerator-rich architecture, based on the RISC-V Instruction Set Architecture (ISA);
- :smallcapbold:`SLD toolchain`—Automatic design and specialization accelerator-rich, multi-cluster platforms;
- :smallcapbold:`Exploration flow`—Weigh design trade-offs, identifying the best candidate at meeting your application needs. :smallcap:`Richie` leverages FPGAs to emulate full-stack applications and navigate the HeSoC design space, enabling deeper introspection into the non-idealities occurring at system-level.

..  figure:: img/pulp_logo_icon.*
    :figwidth: 15%
    :align: right

:smallcap:`Richie` is a joint development effort leaded by the University of Modena and Reggio Emilia (UNIMORE) and the 
`PULP (Parallel Ultra-Low Power) Platform group <https://pulp-platform.org/index.html>`_, from ETH Zürich and the University of Bologna.

.. toctree::
  :maxdepth: 3
  :numbered:
  :caption: Contents:

  richie-platform/index
  richie-sld-toolchain/index
  richie-exploration/index
  general/getting-started
  general/environments
  general/tutorial
  general/contributing
  publications/publications
  general/license
  general/team

.. note::

   This project is under active development.
