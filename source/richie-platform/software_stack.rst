==============
Software stack
==============

.. figure:: ../img/richie_sw.*
  :figwidth: 75%
  :width: 75%
  :align: center

  Software stack.

-------------------
Heterogeneous stack
-------------------
.. _richie_platform_heterogeneous_stack:

The :smallcap:`Richie platform` includes a mature *software stack* to deploy heterogeneous applications to the underlying hardware subsystem.

The :bolditalic:`heterogeneous application` starts on the *host*, while the *device* is targeted via a computation offloading command.
The :bolditalic:`Application Programming Interface (API)`` relaxes the interfacing with diverse platforms, easing code portability and reuse. 
It supports accelerator and DMA control, multi-cluster communication, and memory management.

Host-to-device offloading is supported employing the :bolditalic:`OpenMP` programming model and its *Run-Time Environment (RTE)*.
The *host* invokes a device-specific plugin and provides the *device* with a pointer to the offloaded code and data. 
After an initialization phase, the *device* starts executing.

Besides, an off-the-shelf :bolditalic:`Linux kernel` distribution is adopted to ease the deployment of legacy software on the *host*, while
the :bolditalic:`low-level device RTE` supports the OpenMP constructs, platform-specific routines and functions on the *device* side.
The :bolditalic:`Hardware Abstraction Layer (HAL)` sits on top of the device bare metal and implements optimized primitives and basic functionalities for the underlying hardware.

..
    ------------------------------
    Software Development Kit (SDK)
    ------------------------------

    ^^^^^^^^^^^^^^^
    Reconfigure SDK
    ^^^^^^^^^^^^^^^
    cd hero
    make sdk-arov-cfg

    explain other commands:
    sdk-arov-clean
    sdk-arov-libs
    sdk-arov-refs
    sdk-pulp (ref. HERO documentation)

    ^^^^^^^^^^^^
    PULP runtime
    ^^^^^^^^^^^^
    cd pulp/sdk
    hero-arov-sim
    plpbuild --m pulp-rt build