------
Pylint
------
`Pylint <https://docs.pylint.org/index.html>`_ is a static code analyser for Python 2 or 3.

We leverage Pylint to detect style elements that are in violation of the `PEP8 Python Code Style Guide <https://peps.python.org/pep-0008/>`_, thus reducing manual code alignment steps.

^^^^^^^^^^^^^^
How to install
^^^^^^^^^^^^^^
Pylint is automatically installed within the Python Virtual Environment of the :smallcap:`Richie toolchain`.

^^^^^^^^^^
How to use
^^^^^^^^^^
Run the following command from the Toolchain root:

.. code-block:: console

    make check_python

