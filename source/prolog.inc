.. # Load pre-defined aliases and graphical characters like © from docutils
   # <file> is used to denote the special path
   # <Python>\Lib\site-packages\docutils\parsers\rst\include
.. include:: <isonum.txt>
.. include:: <mmlalias.txt>

.. # define a hard line break for HTML
.. |br| raw:: html

   <br />

.. # define horizontal line for HTML
.. |hr| raw:: html

   <hr />

.. # define additional CSS based styles and ReST roles for HTML
.. raw:: html

   <style type="text/css">
     span.bolditalic {font-weight: bold; font-style: italic; }
     span.underline {text-decoration: underline; }
     span.smallcap {font-variant: small-caps;}
     span.smallcapbold {font-variant: small-caps; font-weight: bold;}
   </style>

.. role:: bolditalic
   :class: bolditalic

.. role:: underline
   :class: underline

.. role:: smallcap
   :class: smallcap

.. role:: smallcapbold
   :class: smallcapbold

.. role:: xlarge
   :class: xlarge

.. role:: pycode(code)
   :language: python
   :class: highlight

.. # CSS implementations (under _static/css/custom.css)

.. role:: button
   :class: button

.. role:: strike
    :class: strike

.. Color profiles for Sphinx.
.. Has to be used with hacks.css
.. (https://bitbucket.org/lbesson/web-sphinx/src/master/.static/hacks.css)
.. (c) Lilian Besson, 2011-2016, https://bitbucket.org/lbesson/web-sphinx/

.. role:: black
.. role:: gray
.. role:: grey
.. role:: silver
.. role:: white
.. role:: maroon
.. role:: red
.. role:: magenta
.. role:: fuchsia
.. role:: pink
.. role:: orange
.. role:: yellow
.. role:: lime
.. role:: green
.. role:: olive
.. role:: teal
.. role:: cyan
.. role:: aqua
.. role:: blue
.. role:: navy
.. role:: purple

.. role:: under
.. role:: over
.. role:: blink
.. role:: line
.. role:: strike

.. role:: it
.. role:: ob

.. role:: small
.. role:: large

.. role:: center
.. role:: left
.. role:: right