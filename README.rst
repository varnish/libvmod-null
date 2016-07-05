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

Installation requires the Varnish source tree (only the source matching the
binary installation).

1. `./autogen.sh`  (for git-installation)
2. `./configure`
3. `make`
4. `make check` (Optional)
5. `make install` (may require root: sudo make install)

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
