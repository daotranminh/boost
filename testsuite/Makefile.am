# global preprocessor flags
AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir) \
	$(BM_CPPFLAGS) \
	$(BOOST_CPPFLAGS) \
	$(LOG4CXX_CFLAGS) \
	@LIBCURL_CPPFLAGS@

# global linker flags
AM_LDFLAGS = \
	$(BOOST_SYSTEM_LDFLAGS) \
	$(BOOST_THREAD_LDFLAGS) \
	$(BOOST_SERIALIZATION_LDFLAGS) \
	$(BOOST_UNIT_TEST_FRAMEWORK_LDFLAGS)

# global libs
LIBS = \
	$(BOOST_THREAD_LIBS) \
	$(BOOST_GRAPH_LIBS) \
	$(BOOST_SERIALIZATION_LIBS) \
	$(BOOST_UNIT_TEST_FRAMEWORK_LIBS) \
	$(BOOST_SYSTEM_LIBS) \
	$(LOG4CXX_LIBS)

TESTS_ENVIRONMENT = \
	EXAMPLESDIR=$(top_srcdir)/examples \
	BOOST_TEST_REPORT_LEVEL=detailed \
	BOOST_TEST_LOG_LEVEL=all

TESTS = \
	testListParser

check_PROGRAMS = \
	testListParser

testListParser_SOURCES = testListParser.cpp
testListParser_LDADD = 	$(top_builddir)/src/parser/libparser.la \
			$(top_builddir)/src/base/libbase.la 