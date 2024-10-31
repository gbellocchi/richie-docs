=====================
Hardware architecture
=====================

.. figure:: ../img/richie_hw.*
  :figwidth: 90%
  :width: 90%
  :align: center

  Hardware architecture.

--------------------------
Heterogeneous architecture
--------------------------
.. _richie_platform_heterogeneous_architecture:

The :smallcap:`Richie platform` consists of an HeSoC, including two *hardware subsystems*.

The :bolditalic:`host` is a Linux-capable multi-core *application-class processor*, implementing either:

* CVA6, a 6-stage RISC-V CPU (RV64), which is implemented on FPGA;
* Arm Cortex-A53 CPU, a hard macro available on Zynq Ultrascale+ MPSoCs.

The :bolditalic:`device` is an *accelerator-rich subsystem*, hierarchically organized as shared-memory clusters,
communicating over a fully-connected AXI-4 crossbar.
The *L2 memory* is implemented as a multi-port, multi-banked instruction and data ScratchPad Memory (SPM).

--------------
Cluster fabric
--------------
.. _richie_platform_cluster_fabric:

The :bolditalic:`cluster` comprises two main sets of components:

* *data-crunching accelerators*, responding to computational requirements;
* *support devices*, supporting through various services, such as programming, storage, communication and synchronization.

The *proxy core* is a low-cost bare metal :math:`\mu`-controller, meant to streamline the supervision of the many HW/SW tasks
co-existing inside the cluster, including local accelerator control.
It implements the RV32 ISA and fetches instructions from the L2 memory and through an instruction cache.

The *L1 memory* is a multi-banked, SW-programmable, data SPM, accessible by accelerators and proxy cores via the Logarithmic Interconnect (LIC),
a fully-connected crossbar with single-cycle latency and a word-level interleaving scheme to reduce the probability of contention.
A *Direct Memory Access (DMA) engine* is employed for bi-directional, multi-channel and SW-programmable 64-bit data transfers across the memory hierarchies.
A strict collaboration with the proxy allows for tight control of the DMA bandwidth.
Finally, the cluster includes an *Event Unit (EU)* to synchronize cores with accelerators, peripherals, other processors, or other clusters, thus allowing
the application tasks sequencing by the exchange of 32-bit events signals.

---------------------------------
Application-specific accelerators
---------------------------------
.. _richie_platform_accelerators:

:bolditalic:`Accelerators` are the primary computational units embraced by :smallcap:`Richie` inside its device subsystem.
:smallcap:`Richie` adopts the *Hardware Processing Engine (HWPE) interface* to establish a flexible communication between
its accelerators and the cluster components.

An HWPE module is composed of three key components:

* The `engine <https://hwpe-doc.readthedocs.io/en/latest/github.html>`_ implements the datapath, thus is application-specific and operates on latency-insensitive data streams;
* The `streamer <https://hwpe-doc.readthedocs.io/en/latest/modules.html#basic-modules-hwpe-stream>`_ converts the memory-mapped communication protocol of the L1 memory into a data stream for the datapath, and vice versa. It exposes a configurable number of LIC master ports toward the L1 memory to flexibly accommodate application-specific bandwidth requirements;
* The `controller <https://hwpe-doc.readthedocs.io/en/latest/modules.html#control-interface-modules-hwpe-periph>`_ exposes a memory-mapped control interface for the \proxy{} to access and program the HWPE control registers and a FSM implementing coarse-grained accelerator control/(re)configuration.

HWPEs are coupled to the proxy core at the L1 memory level.
Their execution is readily triggered by the latter via the exchange of a set of pointers.
Multiple HWPEs can be connected inside the cluster, where they share bandwidth with the proxy core and the DMA over the LIC.

Take a look at the `HWPE documentation <https://hwpe-doc.readthedocs.io/en/latest/index.html>`_ for more information concerning HWPE,
its protocol, components, usage, etc.
