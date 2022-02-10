# POSIX additions to <stdlib.h>
# http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdlib.h.html

cdef extern from "<stdlib.h>" nogil: 
    void   _Exit(int)
    double drand48()
    double erand48(unsigned short *)
    int    getsubopt(char **, char *const *, char **)
    void   lcong48(unsigned short *)
    long   lrand()
    char  *mkdtemp(char *)
    int    mkstemp(char *)
    long   mrand()
    long   nrand48(unsigned short *)
    int    posix_memalign(void **, size_t, size_t)
    int    posix_openpt(int)
    char  *ptsname(int)
    int    putenv(char *)
    int    rand_r(unsigned *)
    long   random()
    char  *realpath(const char *, char *)
    unsigned short *seed48(unsigned short *)
    int    setenv(const char *, const char *, int)
    void   setkey(const char *)
    char  *setstate(char *)
    void   srand48(long)
    void   srandom(unsigned)
    int    unlockpt(int)
    int    unsetenv(const char *)
