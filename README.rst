=========
vmod_null
=========

---------------------
Varnish Nulldata VMOD
---------------------

:Author: Kristian Lyngstøl
:Date: 2012-02-22
:Version: 1.1
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

Installation requires the Varnish source tree (only the source matching the
binary installation).

1. `./autogen.sh`  (for git-installation)
2. `./configure VARNISHSRC=/path/to/your/varnish/source/varnish-cache`
3. `make`
4. `make install` (may require root: sudo make install)
5. `make check` (Optional for regression tests)

VARNISHSRCDIR is the directory of the Varnish source tree for which to
compile your vmod. Both the VARNISHSRCDIR and VARNISHSRCDIR/include
will be added to the include search paths for your module.

Optionally you can also set the vmod install dir by adding VMODDIR=DIR
(defaults to the pkg-config discovered directory from your Varnish
installation).

BUGS
====

While not entirely a bug, it is dangerous to use this vmod anywhere outside
of vcl_error, due to the way objects may disappear.

HISTORY
=======

Version 1.0
        Initial release

Version 1.1
        Fixes manual-path. Adds strict tests to ensure execution only takes
        place in vcl_error.

SEE ALSO
========

* varnishd(1)
* vcl(7)

COPYRIGHT
=========

This document is licensed under the same license as the
libvmod-null project. See LICENSE for details.

* Copyright (c) 2011 Varnish Software
