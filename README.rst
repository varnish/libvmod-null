=========
vmod_null
=========

-----------------
Varnish NULL VMOD
-----------------

:Author: Kristian Lyngstøl
:Author: Reza Naghibi
:Date: 2016-07-05
:Version: 1.2
:Manual section: 3

SYNOPSIS
========

import null;

null.synth(STRING, LENGTH);

DESCRIPTION
===========

VMOD for sending synthetic data with binary content.

FUNCTIONS
=========

synth
-----

Prototype
        ::

                synth(STRING s, INT length)
Return value
	VOID
Description
	Does the same as synthetic() in VCL, but uses a set length, thus
        allowing null-data. Must be used in vcl_synth or vcl_backend_error.
Example
        ::

                null.synth("TEST",4);

INSTALLATION
============

The source tree is based on autotools to configure the building, and
does also have the necessary bits in place to do functional unit tests
using the ``varnishtest`` tool.

Building requires the Varnish header files and uses pkg-config to find
the necessary paths.

Pre-requisites::

 sudo apt-get install -y autotools-dev make automake libtool pkg-config libvarnishapi1 libvarnishapi-dev

Usage::

 ./autogen.sh
 ./configure

If you have installed Varnish to a non-standard directory, call
``autogen.sh`` and ``configure`` with ``PKG_CONFIG_PATH`` pointing to
the appropriate path. For example, when varnishd configure was called
with ``--prefix=$PREFIX``, use

 PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
 export PKG_CONFIG_PATH

Make targets:

* make - builds the vmod.
* make install - installs your vmod.
* make check - runs the unit tests in ``src/tests/*.vtc``
* make distcheck - run check and prepare a tarball of the vmod.

Installation directories
------------------------

By default, the vmod ``configure`` script installs the built vmod in
the same directory as Varnish, determined via ``pkg-config(1)``. The
vmod installation directory can be overridden by passing the
``VMOD_DIR`` variable to ``configure``.

Other files like man-pages and documentation are installed in the
locations determined by ``configure``, which inherits its default
``--prefix`` setting from Varnish.

HISTORY
=======

Version 1.0
        Initial release

Version 1.1
        Fixes manual-path. Adds strict tests to ensure execution only takes
        place in vcl_error.

Version 1.2
        4.0 and 4.1 support.

SEE ALSO
========

* varnishd(1)
* vcl(7)

COPYRIGHT
=========

This document is licensed under the same license as the
libvmod-null project. See LICENSE for details.

* Copyright (c) 2011-2016 Varnish Software
