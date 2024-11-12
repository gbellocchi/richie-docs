-------
Verible
-------
`Verible <https://chipsalliance.github.io/verible/>`_ is an open-source SystemVerilog style linter and formatting tool.
The style linter is relatively mature and is used as part of our generation flow to analyze RTL components.
Linting serves as a productivity tool for designers to quickly find typos and bugs at the time when the RTL is designed.

We leverage Verible to capture different aspects of the code and detect style elements that violate the `lowRISC Verilog Coding Style Guide <https://github.com/lowRISC/style-guides/blob/master/VerilogCodingStyle.md>`_, thus reducing manual code alignment steps.

^^^^^^^^^^^^^^
How to Install
^^^^^^^^^^^^^^
You can download and build Verible from scratch as explained on the `Verible GitHub page <https://github.com/google/verible/>`_.
However, since this requires the Bazel build system we recommend consulting the `Verible releases <https://github.com/google/verible/releases>`_
and download a pre-built binary for your machine.

The example below is for Ubuntu 20.04:

.. code-block:: console

  export VERIBLE_VERSION=v0.0-3644-g6882622d
  wget https://github.com/google/verible/releases/download/${VERIBLE_VERSION}/verible-${VERIBLE_VERSION}-Ubuntu-20.04-focal-x86_64.tar.gz
  tar -xf verible-${VERIBLE_VERSION}-Ubuntu-20.04-focal-x86_64.tar.gz

If you are using Ubuntu 18.04 then instead use:

.. code-block:: console

  export VERIBLE_VERSION=v0.0-3644-g6882622d
  wget https://github.com/google/verible/releases/download/${VERIBLE_VERSION}/verible-${VERIBLE_VERSION}-Ubuntu-18.04-bionic-x86_64.tar.gz
  tar -xf verible-${VERIBLE_VERSION}-Ubuntu-18.04-bionic-x86_64.tar.gz

Note that we currently use version v0.0-3644-g6882622d, but it is expected that this version is going to be updated frequently, since the tool is under active development.

^^^^^^^^^^
How to Use
^^^^^^^^^^
Once the generation flow completes, Verible can be used to analyze the generated RTL.
The tool arguments and invocations are managed in :code:`scripts/verible-format.py`.

For example, the generated RTL of the target platform :code:`richie_example` is analyzed by running the following command from the Toolchain root:

.. code-block:: console

    make check_systemverilog TARGET_PLATFORM=richie_example

