*********
Toolchain
*********

.. figure:: img/richie_toolchain.*
  :figwidth: 90%
  :width: 90%
  :align: center

  The Richie toolchain.

===============
Generation flow
===============
The *generation flow* is the toolchain automation core and enables the seamless and rapid composition of 
accelerator-rich platforms, leveraging the third-party *Mako template library*.

===========================
Platform Specification File
===========================


Accelerator Specification File
==============================

Templates 
=========

List of templates
-----------------
TBD (find a way to make it automated)

Template file extension
-----------------------
Richie includes various types of templates, ranging from HW blocks implemented with HDL to SW libraries, designed in C.

The extension of each template file is a combination of:

* The extension of the generated file, e.g., *sv* for SystemVerilog, **tcl** for *TCL files*, **yml** for *YAML files*, etc.
* The employed template library, e.g., **mako**.

For example, a template component *richie_module_top* implemented in SystemVerilog will have the following name name: *richie_module_top.sv.mako*.

Support for template file extension in Visual Studio Code
---------------------------------------------------------
Visual Studio Code (VSCode) allows associating a standard language style to a 
custom file extension, which can simplify the design of templates in VSCode. 
For this, follow the following instructions:

#. Open VSCode
#. Press **CTRL+SHIFT+p**.
#. Search for *Preferences: Open User Settings (JSON)* and add the following configuration:

.. code-block:: none

	"files.associations": {
		"*.sv.mako": "systemverilog",
		"*.v.mako": "verilog",
		"*.c.mako": "c",
		"*.py.mako": "python",
		"*.tcl.mako": "tcl",
		"*.yml.mako": "yml"
	},
