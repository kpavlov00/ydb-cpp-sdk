# Generated by devtools/yamaker. 
 
LIBRARY() 
 
OWNER(
    orivej
    g:cpp-contrib
)
 
VERSION(0.4.5) 
 
LICENSE(Apache-2.0) 
 
LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR( 
    contrib/libs/openssl 
    contrib/restricted/aws/aws-c-common 
) 
 
ADDINCL( 
    GLOBAL contrib/restricted/aws/aws-c-cal/include 
) 
 
NO_COMPILER_WARNINGS() 
 
NO_RUNTIME() 
 
SRCS( 
    source/cal.c 
    source/der.c 
    source/ecc.c 
    source/hash.c 
    source/hmac.c 
    source/unix/openssl_platform_init.c 
    source/unix/opensslcrypto_ecc.c 
    source/unix/opensslcrypto_hash.c 
    source/unix/opensslcrypto_hmac.c 
) 
 
END() 
