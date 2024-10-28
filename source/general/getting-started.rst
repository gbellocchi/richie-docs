***************
Getting Started
***************
.. _general_getting_started:

================
External sources
================
:smallcap:`Richie` uses Git submodules that have to be initialized. Either clone the repository recursively using

.. code-block:: console

  git clone --recursive <url>

or fetch the submodules afterwards in the repository

.. code-block:: console

  git submodule update --init --recursive

=============
Prerequisites
=============

----
HERO
----
HERO is leveraged as a build system for the software components of :smallcap:`Richie`, thus its installation is mandatory.
We therefore recommend:

* Adhering the following list of `prerequisites <https://github.com/pulp-platform/hero/blob/master/PREREQUISITES.md>`_;
* Installing HERO as described in its `documentation <https://github.com/pulp-platform/hero/blob/master/README.md>`_.
