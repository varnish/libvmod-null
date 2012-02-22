=========
vmod_null
=========

---------------------
Varnish Nulldata VMOD
---------------------

:Author: Kristian Lyngstøl
:Date: 2011-09-29
:Version: 1.0
:Manual section: 3

SYNOPSIS
========

import null;

null.synth(STRING, LENGTH);


DESCRIPTION
===========

Vmod for sending synthetic data with binary content. Typically used through
in-line C.

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
        allowing null-data. Must be used in vcl_error.
Example
        ::

                Vmod_Func_null.synth(sp,"TEST",4);

INSTALLATION
============

The source tree is based on autotools to configure the building, and
does also have the necessary bits in place to do functional unit tests
using the varnishtest tool.

Usage::

 ./configure VARNISHSRC=DIR [VMODDIR=DIR]

`VARNISHSRC` is the directory of the Varnish source tree for which to
compile your vmod. Both the `VARNISHSRC` and `VARNISHSRC/include`
will be added to the include search paths for your module.

Optionally you can also set the vmod install directory by adding
`VMODDIR=DIR` (defaults to the pkg-config discovered directory from your
Varnish installation).

Make targets:

* make - builds the vmod
* make install - installs your vmod in `VMODDIR`
* make check - runs the unit tests in ``src/tests/*.vtc``

BUGS
====

While not entirely a bug, it is dangerous to use this vmod anywhere outside
of vcl_error, due to the way objects may disappear.

HISTORY
=======

This manual page was released as part of the libvmod-null package.

COPYRIGHT
=========

This document is licensed under the same license as the
libvmod-null project. See LICENSE for details.

* Copyright (c) 2011 Varnish Software
