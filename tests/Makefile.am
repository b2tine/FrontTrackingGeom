AM_CPPFLAGS= $(GTEST_CPPFLAGS) -I$(top_srcdir)/src

AM_CXXFLAGS = $(GTEST_CXXFLAGS)

AM_LDFLAGS = $(GTEST_LDFLAGS) $(GTEST_LIBS) -lgmock_main -lgmock

# Build rules for tests.
# TESTS_ENVIRONMENT: Set environment variables for the test run
# TESTS: Define programs run automatically by "make check"
# check_PROGRAMS: Define programs built by "make check" but not necessarily run

TESTS_ENVIRONMENT = 

TESTS =
check_PROGRAMS =

TESTS += InterfaceTests
check_PROGRAMS += InterfaceTests

InterfaceTests_SOURCES = InterfaceTests.cpp

