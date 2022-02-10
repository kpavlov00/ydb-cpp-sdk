# Generated by devtools/yamaker (pypi).

PY3_LIBRARY()

OWNER(g:python-contrib)
 
VERSION(2.0.1)

LICENSE(BSD-3-Clause)

NO_COMPILER_WARNINGS()

NO_LINT()

SRCS(
    markupsafe/_speedups.c
)

PY_REGISTER(
    markupsafe._speedups
)

PY_SRCS(
    TOP_LEVEL
    markupsafe/__init__.py
    markupsafe/_native.py
    markupsafe/_speedups.pyi
)

RESOURCE_FILES(
    PREFIX contrib/python/MarkupSafe/py3/
    .dist-info/METADATA
    .dist-info/top_level.txt
    markupsafe/py.typed
)

END()

RECURSE_FOR_TESTS(
    tests
)
