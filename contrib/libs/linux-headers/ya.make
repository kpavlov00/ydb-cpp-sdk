# Generated by devtools/yamaker from nixpkgs 980c4c3c2f664ccc5002f7fd6e08059cf1f00e75. 
 
LIBRARY() 
 
OWNER(
    orivej
    g:cpp-contrib
)
 
VERSION(5.7) 
 
ORIGINAL_SOURCE(mirror://kernel/linux/kernel/v5.x/linux-5.7.tar.xz) 
 
LICENSE(
    "(GPL-2.0-only WITH Linux-syscall-note OR BSD-2-Clause)" AND
    "(GPL-2.0-only WITH Linux-syscall-note OR BSD-3-Clause)" AND
    "(GPL-2.0-only WITH Linux-syscall-note OR CDDL-1.0)" AND
    "(GPL-2.0-only WITH Linux-syscall-note OR Linux-OpenIB)" AND
    "(GPL-2.0-only WITH Linux-syscall-note OR MIT)" AND
    "(GPL-2.0-or-later WITH Linux-syscall-note OR BSD-3-Clause)" AND
    BSD-2-Clause AND
    BSD-3-Clause AND
    GPL-1.0-or-later WITH Linux-syscall-note AND
    GPL-2.0-only WITH Linux-syscall-note AND
    GPL-2.0-or-later WITH Linux-syscall-note AND
    ISC AND
    Khronos AND
    LGPL-2.0-only AND
    LGPL-2.0-or-later WITH Linux-syscall-note AND
    LGPL-2.1-only AND
    LGPL-2.1-only WITH Linux-syscall-note AND
    LGPL-2.1-or-later WITH Linux-syscall-note AND
    MIT AND
    NTP AND
    Public-Domain
)
 
LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

DISABLE(NEED_PLATFORM_PEERDIRS) 

DISABLE(WITH_VALGRIND) 
 
DISABLE(OPENSOURCE_EXPORT)

ADDINCL( 
    GLOBAL contrib/libs/linux-headers 
    GLOBAL contrib/libs/linux-headers/_nf 
) 
 
NO_PLATFORM() 
 
END() 
