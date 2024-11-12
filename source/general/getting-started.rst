***************
Getting Started
***************
.. _general_getting_started:

====================
Repository Structure
====================
The |repository_structure_emphasized_hyperlink|_ includes various components, which are organized as follows:

- :code:`hw`: *Hardware subsystem*, including the platform and accelerators designs, a FPGA build flow and a RTL simulation setup;
- :code:`sw`: *Software subsystem*, including benchmarks and board boot scripts;
- :code:`sld-tools`: *SLD toolchain*, to automate and facilitate the hardware-software co-design and specialization of HeSoC components;
- :code:`third-party`: *Third-party components*, including the HERO software toolchains and PULP SDK;
- :code:`env`: *Environment scripts*, to set up the repository for different design stages and flows, including FPGA deployment, RTL simulation, HLS synthesis, etc.

.. |repository_structure_emphasized_hyperlink| replace:: :smallcap:`Richie repository`
.. _repository_structure_emphasized_hyperlink: https://github.com/Advanced-Architectures-UNIMORE/richie

================
External Sources
================
:smallcap:`Richie` uses Git submodules that have to be initialized. Either clone the repository recursively using

.. code-block:: console

  git clone --recursive <url>

or fetch the submodules afterwards in the repository

.. code-block:: console

  git submodule update --init --recursive

=============
Prerequisites
=============

----
HERO
----
HERO is leveraged as a build system for the software components of :smallcap:`Richie`, thus its installation is mandatory.
We therefore recommend:

* Adhering the following list of `prerequisites <https://github.com/pulp-platform/hero/blob/master/PREREQUISITES.md>`_;
* Installing HERO as described in its `documentation <https://github.com/pulp-platform/hero/blob/master/README.md>`_.
