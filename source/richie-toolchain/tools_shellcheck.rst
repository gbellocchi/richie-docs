----------
ShellCheck
----------
`ShellCheck <https://www.shellcheck.net/>`_ is a shell script static analysis tool, which can detect style elements that are in violation of the `Google Shell Style Guide <https://google.github.io/styleguide/shellguide.html>`_.

^^^^^^^^^^^^^^
How to install
^^^^^^^^^^^^^^
Consult the `ShellCheck repository <https://github.com/koalaman/shellcheck>`_ and learn how to install the tool.
We suggest downloading pre-compiled binaries for the latest release.

The example below is for Linux x86-64 (statically linked):

.. code-block:: console

  wget https://github.com/koalaman/shellcheck/releases/download/stable/shellcheck-stable.linux.x86_64.tar.xz
  tar -xf shellcheck-stable.linux.x86_64.tar.xz

^^^^^^^^^^
How to use
^^^^^^^^^^
Run the following command from the Toolchain root:

.. code-block:: console

    make check_shell

