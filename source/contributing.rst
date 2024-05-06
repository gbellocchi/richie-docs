******************
Contribution Guide
******************
We are happy to accept pull requests and issues from any contributors. 
Please note that we try to maintain a consistent quality standard.

==================
Git Considerations
==================

* Separate subject from body with a blank line
* Limit the subject line to 72 characters
* Capitalize the subject line
* Do not end the subject line with a period
* Use the imperative mood in the subject line
* Use the body to explain what and why vs. how

For further information please see the excellent
[guide](https://chris.beams.io/posts/git-commit/) by Chris Beams.

============
Coding Style
============

-------
General
-------
Consistent code style is important. We try to follow existing style conventions, as much as possible:

* For RTL we adhere to the `lowRISC Verilog Coding Style Guide <https://github.com/lowRISC/style-guides/blob/master/VerilogCodingStyle.md>`_.
* For C/C++ we follow the `LLVM's style guide <https://llvm.org/docs/CodingStandards.html>`_., please note the `clang-format` in the projects root.
* For Python code we follow the official `PEP8 style guide <https://peps.python.org/pep-0008/>`_.
* Use the `EditorConfig <https://editorconfig.org>`_ to format all files correctly.

Please make sure that any code you submit is adhering to the correct standard.

--------------------------
About the Richie Toolchain
--------------------------
The *Richie Toolchain* leverages linters to automatically analyze various code sources and detect bugs, convention violations and style guidelines.
More information is available in the corresponding :ref:`here <richie_toolchain_tools>`.