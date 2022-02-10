# Generated by devtools/yamaker.

LIBRARY()

WITHOUT_LICENSE_TEXTS()

OWNER(
    orivej
    g:cpp-contrib
)

LICENSE(MIT) 
 
PEERDIR(
    contrib/libs/fmt
    contrib/restricted/googletest/googlemock
)

NO_COMPILER_WARNINGS()

NO_UTIL()

CFLAGS(
    -DFMT_LOCALE
    -DFMT_SHARED
    -DGTEST_HAS_STD_WSTRING=1
    -DGTEST_LANG_CXX11=0
    -D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING=1
)

SRCS(
    gtest-extra.cc
    util.cc
)

END()

RECURSE(
    assert-test
    chrono-test
    color-test
    compile-test
    core-test
    format-impl-test
    format-test
    gtest-extra-test
    header-only-test
    locale-test
    os-test
    ostream-test
    posix-mock-test
    printf-test
    ranges-test
    scan-test
)
