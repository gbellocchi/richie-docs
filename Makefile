# Minimal makefile for Sphinx documentation
#

# You can set these variables from the command line, and also
# from the environment for the first two.
SPHINXOPTS    =
SPHINXBUILD   = sphinx-build
SOURCEDIR     = source
BUILDDIR      = build

# Put it first so that "make" without argument is like "make help".
help:
	@$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.PHONY: help Makefile

# deps/svprettyplot:
# 	git submodule init
# 	git submodule sync

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: # Makefile deps/svprettyplot
	@$(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

open:
	firefox build/html/index.html
# build:
# 	sphinx-build -M html docs/source/ docs/build/

# Installation

py-env-install:
	python -m pip install --upgrade pip
	python -m pip install -r requirements.txt
py-env-init:
	python -m venv richie-docs-py-venv
