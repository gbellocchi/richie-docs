===============
Getting Started
===============

--------------------
Clone the Repository
--------------------
Clone the repository with its Git submodules using :code:`git clone --recursive <url>` or fetch the submodules
afterwards with :code:`git submodule update --init --recursive`.

---------------------------------------------------
Integration within the :smallcap:`Richie framework`
---------------------------------------------------
This toolchain is employed as part of the :smallcap:`Richie framework`, which includes the HW/SW components to design,
build, and deploy a full-fledged accelerator-rich HeSoC.
This ecosystem leverages the :smallcap:`Richie toolchain` to generate the necessary HW/SW sources to drive the specialization
of the target HeSoC platform.
To safely let the framework parts interact, the root of the :smallcap:`Richie` hardware subsystem (:code:`RICHIE_HW`) must be defined accordingly:

.. code-block:: console

  export RICHIE_HW=<global-path-to-richie>/richie/hardware

--------------------------
Python Virtual Environment
--------------------------
The toolchain leverages a Python virtual environment to manage the tool dependencies.
The toolchain has been tested with :code:`Python 3.8.10`, so we recommend sticking with this version.
To create the environment and install the required packages (listed inside :code:`requirements.txt`), simply run:

.. code-block:: console

    make py_env_init

Then, the environment can be activated by :code:`source richie-py-env/bin/activate`.
If new packages are added, the environment can be updated with the following command:

.. code-block:: console

    make py_env_update_reqs

Note that the :code:`py_env_init` command should be run again to install newly added packages and/or update old ones.

--------------------------
Third-Party Git Submodules
--------------------------
Third-party submodules can be pulled with the following command:

.. code-block:: console

    make richie_gen_init

-----------------
Third-Party Tools
-----------------
More information under :ref:`tools <richie_toolchain_tools>`.
