# Generated by devtools/yamaker.

LIBRARY()

OWNER(
    orivej
    g:cpp-contrib
)

LICENSE(
    BSD-3-Clause AND
    BSL-1.0
)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/poco/Foundation
)

ADDINCL(
    GLOBAL contrib/libs/poco/JSON/include
    contrib/libs/poco/Foundation/include
    contrib/libs/poco/JSON/src
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    src/Array.cpp
    src/Handler.cpp
    src/JSONException.cpp
    src/Object.cpp
    src/ParseHandler.cpp
    src/Parser.cpp
    src/ParserImpl.cpp
    src/PrintHandler.cpp
    src/Query.cpp
    src/Stringifier.cpp
    src/Template.cpp
    src/TemplateCache.cpp
    src/pdjson.c
)

END()
