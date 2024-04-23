*********
Toolchain
*********

Templates 
=========

Template file extension
-----------------------
Richie includes various types of templates, ranging from HW blocks implemented with Hardware Description Lanaguges to SW libraries, designed in C.

The extension of each template file is a combination of:

* The extension of the generated file, e.g., *sv* for SystemVerilog, **tcl** for *TCL files*, **yml** for *YAML files*, etc.
* The employed template library, e.g., **mako**.

Support for template file extension in Visual Studio Code
---------------------------------------------------------
Visual Studio Code (VSCode) allows associating a standard language style to a 
custom file extension, which can simplify the design of templates in VSCode. 
For this, follow the following instructions:

#. Open VSCode
#. Press **CTRL+SHIFT+p**.
#. Search for *Preferences: Open User Settings (JSON)* and add the following configuration:

.. code-block:: yaml

	"files.associations": {
		"*.sv.mako": "systemverilog",
		"*.v.mako": "verilog",
		"*.c.mako": "c",
		"*.py.mako": "python",
		"*.tcl.mako": "tcl",
		"*.yml.mako": "yml"
	},
