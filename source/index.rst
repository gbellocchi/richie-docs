######
Richie
######

*Richie* is an open-source research SLD framework to simplify the design and exploration of Accelerator-Rich HeSoCs, based on the RISC-V ISA.

.. figure:: img/richie_summary.*
  :figwidth: 90%
  :width: 90%
  :align: center

  The Richie framework.

This document defines the interface protocols and modules that are used
to enable connecting HWPEs in a PULP system. Typically, such a module is
divided in a **streamer** interface towards the memory system, a
**control/peripheral** interface used for programming it, and an
**engine** containing the actual datapath of the accelerator.

.. toctree::
  :maxdepth: 3
  :numbered:
  :caption: Contents:

  platform
  toolchain
  richie-toolchain/richie-toolchain
  exploration
  papers
  license
  contributing
  team

.. note::

   This project is under active development.