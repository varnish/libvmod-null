AM_CPPFLAGS = @VMOD_INCLUDES@ -Wall -Werror

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_null.la

libvmod_null_la_LDFLAGS = -module -export-dynamic -avoid-version -shared

libvmod_null_la_SOURCES = \
	vmod_null.c

nodist_libvmod_null_la_SOURCES = \
	vcc_if.c \
	vcc_if.h

vmod_null.lo: vcc_if.c vcc_if.h

vcc_if.c: vcc_if.h

vcc_if.h: @VMODTOOL@ $(top_srcdir)/src/vmod_null.vcc
	@VMODTOOL@ $(top_srcdir)/src/vmod_null.vcc

VMOD_TESTS = $(top_srcdir)/src/tests/*.vtc
.PHONY: $(VMOD_TESTS)

$(top_srcdir)/src/tests/*.vtc: libvmod_null.la
	@VARNISHTEST@ -Dvarnishd=@VARNISHD@ -Dvmod_topbuild=$(abs_top_builddir) $@

check: $(VMOD_TESTS)

EXTRA_DIST = \
	vmod_null.vcc \
	$(VMOD_TESTS)

CLEANFILES = \
	$(builddir)/vcc_if.c \
	$(builddir)/vcc_if.h \
	$(builddir)/vmod_null.rst \
	$(builddir)/vmod_null.man.rst
