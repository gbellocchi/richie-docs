===================
The generation flow
===================
.. _richie_toolchain_root_generation:

The *generation flow* is the toolchain automation core and enables the seamless and rapid composition of accelerator-rich platforms.

---------------------
Defintion of template
---------------------
*Templates* consist of markup text which is parsed and rendered given an input set of parameters.
This process allows to automate the customization of various types of components, which, in the case of the :smallcap:`Richie toolchain`, range from hardware IPs to software drivers, libraries and tooling scripts.
:smallcap:`Richie` leverages Python and the `*Mako Template Library* <https://www.makotemplates.org/>`_ to implement this template-based approach.

Examples of other frameworks leveraging a similar method to generate modular and composable platforms and components
include `OpenPiton <https://parallel.princeton.edu/openpiton/>`_ and `OpenTitan <https://opentitan.org/>`_.

The extension of the template files is composed of:
* The generated file type, e.g., *sv* for SystemVerilog, **tcl** for *TCL files*, **yml** for *YAML files*, etc.
* The employed template library (**Mako**).

For instance, a template component *richie_module_top* implemented in SystemVerilog will have the following name name: *richie_module_top.sv.mako*.

--------------------
How generation works
--------------------
The :smallcap:`Richie toolchain` adopts a design automation approach, where:

1. *Platform* and *accelerator specification files* are user-defined parameters, which are employed as the design knobs to specialize the HeSoC parts;
2. *Templates* are *rendered* into various output formats, e.g., HW/SW components, scripts, documentation, etc;
3. The *generation flow* provides parameters to a Mako-based *rendering engine*, which parses and renders the toolchain templates;
4. The generation output is a *full-fledged Accelerator-Rich HeSoC*, including a ready-to-go HW/SW stack, simulation testbenches and FPGA scripts.

----------
How to run
----------
The generation flow is triggered with the following command:

.. code-block:: console

  make clean all TARGET_PLATFORM=<TARGET_PLATFORM>

Additionally, add the following arguments:

* **TARGET_PLATFORM**: This is to specify the target platform, where the device-under-test (DUT) is integrated.
  This should match the name declared in the corresponding :ref:`platform specification file <richie_toolchain_root_sld_optimization>`.
  For example, :code:`make clean all TARGET_PLATFORM=richie_example` is run to generate the target platform :code:`richie_example`, which
  specification is kept under :code:`src/platforms/richie_example/specs`.

The generated components will then be available under :code:`output`.
