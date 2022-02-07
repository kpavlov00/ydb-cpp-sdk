# Generated by devtools/yamaker.

GTEST()

WITHOUT_LICENSE_TEXTS()

OWNER(
    orivej
    g:cpp-contrib
)

LICENSE(MIT)

ADDINCL(
    contrib/libs/fmt/include
)

NO_COMPILER_WARNINGS()

NO_UTIL()

CFLAGS(
    -DFMT_LOCALE
    -DGTEST_HAS_STD_WSTRING=1
    -DGTEST_LANG_CXX11=0
    -D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING=1
)

SRCDIR(contrib/libs/fmt)

SRCS(
    src/format.cc
    test/gtest-extra.cc
    test/posix-mock-test.cc
    test/util.cc
)

END()
