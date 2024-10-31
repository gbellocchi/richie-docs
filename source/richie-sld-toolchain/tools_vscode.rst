--------------------------
Template support in VSCode
--------------------------
Visual Studio Code (VSCode) allows to define language styles for custom file extensions.

^^^^^^^^^^^^^^
How to install
^^^^^^^^^^^^^^
Follow the following instructions:

1. Open VSCode
2. Press **CTRL+SHIFT+p**.
3. Search for *Preferences: Open User Settings (JSON)* and add the following configuration:

.. code-block:: none

	"files.associations": {
		"*.sv.mako": "systemverilog",
		"*.v.mako": "verilog",
		"*.c.mako": "c",
		"*.py.mako": "python",
		"*.tcl.mako": "tcl",
		"*.yml.mako": "yml"
	}
