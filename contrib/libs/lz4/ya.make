# Generated by devtools/yamaker from nixpkgs 5852a21819542e6809f68ba5a798600e69874e76.

LIBRARY()

OWNER( 
    orivej 
    g:cpp-contrib 
) 

VERSION(1.9.3)

ORIGINAL_SOURCE(https://github.com/lz4/lz4/archive/v1.9.3.tar.gz)

LICENSE( 
    BSD-2-Clause AND
    BSD-3-Clause 
) 

LICENSE_TEXTS(.yandex_meta/licenses.list.txt) 
 
PEERDIR(
    contrib/libs/xxhash
)

ADDINCL(
    contrib/libs/xxhash
)

NO_RUNTIME()

SRCS(
    lz4.c
    lz4frame.c
    lz4hc.c
)

END()
