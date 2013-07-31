#
# Makefile.am
#
# Written by: Francesco Salvestrini <f DOT salvestrini AT nextworks DOT it>
#

include Makefile.inc

EXTRA_DIST =

if BUILD_WRAPPERS_JAVA

edit = $(SED)							\
        -e 's|@abs_top_builddir[@]|$(abs_top_builddir)|g'	\
        -e 's|@builddir[@]|$(builddir)|g'			\
        -e 's|@libdir[@]|$(libdir)|g'				\
        -e 's|@SHELL[@]|$(SHELL)|g'				\
        -e 's|@JAVA[@]|$(JAVA)|g'				\
        -e 's|@JAVAC[@]|$(JAVAC)|g'

run-java: Makefile run-java.in
	rm -f $@ $@.tmp
	srcdir=''; \
	  test -f ./$@.in || srcdir=$(srcdir)/; \
	  $(edit) $${srcdir}$@.in >$@.tmp
	chmod +x $@.tmp
	chmod a-w $@.tmp
	mv $@.tmp $@

CLEANFILES = run-java

noinst_SCRIPTS = run-java

endif

EXTRA_DIST += run-java.in
EXTRA_DIST += SWIGTest.java

COMMONCPPFLAGS =				\
	-I$(top_srcdir)/include			\
	$(LIBNL3_CFLAGS)			\
	$(LIBNLGENL3_CFLAGS)			\
	$(CPPFLAGS_EXTRA)

COMMONLDFLAGS =					\
	$(LIBNL3_LIBS)				\
	$(LIBNLGENL3_LIBS)

REGRESSIONLDFLAGS = $(COMMONLDFLAGS) $(top_builddir)/src/librina-stubbed.la
FUNCTIONALLDFLAGS = $(COMMONLDFLAGS) $(top_builddir)/src/librina.la

#
# Regression tests
#

test_01_SOURCES  = test-01.cc
test_01_CPPFLAGS = $(COMMONCPPFLAGS)
test_01_LDFLAGS  = $(REGRESSIONLDFLAGS)

test_02_SOURCES  = test-02.cc
test_02_CPPFLAGS = $(COMMONCPPFLAGS)
test_02_LDFLAGS  = $(REGRESSIONLDFLAGS)

test_03_SOURCES  = test-03.cc
test_03_CPPFLAGS = $(COMMONCPPFLAGS)
test_03_LDFLAGS  = $(REGRESSIONLDFLAGS)

#
# Functional tests
#

test_netlink_manager_SOURCES  = test-netlink-manager.cc
test_netlink_manager_CPPFLAGS = $(COMMONCPPFLAGS) -I$(top_srcdir)/src
test_netlink_manager_LDFLAGS  = $(FUNCTIONALLDFLAGS)

test_netlink_parsers_SOURCES  = test-netlink-parsers.cc
test_netlink_parsers_CPPFLAGS = $(COMMONCPPFLAGS) -I$(top_srcdir)/src
test_netlink_parsers_LDFLAGS  = $(FUNCTIONALLDFLAGS)

test_concurrency_SOURCES  = test-concurrency.cc
test_concurrency_CPPFLAGS = $(COMMONCPPFLAGS) -I$(top_srcdir)/src
test_concurrency_LDFLAGS  = $(FUNCTIONALLDFLAGS)

test_core_SOURCES  = test-core.cc
test_core_CPPFLAGS = $(COMMONCPPFLAGS) -I$(top_srcdir)/src
test_core_LDFLAGS  = $(FUNCTIONALLDFLAGS)

test_syscalls_SOURCES  = test-syscalls.cc
test_syscalls_CPPFLAGS = $(COMMONCPPFLAGS) -I$(top_srcdir)/src
test_syscalls_LDFLAGS  = $(FUNCTIONALLDFLAGS)

test_librina_SOURCES  = test-librina.cc
test_librina_CPPFLAGS = $(COMMONCPPFLAGS) -I$(top_srcdir)/src
test_librina_LDFLAGS  = $(FUNCTIONALLDFLAGS)

check_PROGRAMS =				\
	test-01					\
	test-02					\
	test-03					\
	test-netlink-manager			\
	test-netlink-parsers			\
	test-concurrency			\
	test-core				\
	test-syscalls				\
	test-librina

XFAIL_TESTS =					\
	test-03

PASS_TESTS =					\
	test-01					\
	test-02

TESTS = $(PASS_TESTS) $(XFAIL_TESTS)

FUNCTIONAL_PASS_TESTS =				\
	test-netlink-manager			\
	test-netlink-parsers			\
	test-concurrency			\
	test-core				\
	test-syscalls				\
	test-librina

FUNCTIONAL_XFAIL_TESTS =

FUNCTIONAL_TESTS = $(FUNCTIONAL_PASS_TESTS) $(FUNCTIONAL_XFAIL_TESTS)

check-functional: check-functional-am

check-all: check check-functional