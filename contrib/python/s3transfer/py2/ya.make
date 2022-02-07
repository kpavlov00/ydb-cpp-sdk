# Generated by devtools/yamaker (pypi).

PY2_LIBRARY()

OWNER(gebetix g:python-contrib)

VERSION(0.4.2)

LICENSE(Apache-2.0)

PEERDIR(
    contrib/python/botocore
    contrib/python/futures
)

NO_LINT()

NO_CHECK_IMPORTS(
    s3transfer.crt
)

PY_SRCS(
    TOP_LEVEL
    s3transfer/__init__.py
    s3transfer/bandwidth.py
    s3transfer/compat.py
    s3transfer/constants.py
    s3transfer/copies.py
    s3transfer/crt.py
    s3transfer/delete.py
    s3transfer/download.py
    s3transfer/exceptions.py
    s3transfer/futures.py
    s3transfer/manager.py
    s3transfer/processpool.py
    s3transfer/subscribers.py
    s3transfer/tasks.py
    s3transfer/upload.py
    s3transfer/utils.py
)

RESOURCE_FILES(
    PREFIX contrib/python/s3transfer/py2/
    .dist-info/METADATA
    .dist-info/top_level.txt
)

END()

RECURSE_FOR_TESTS(
    tests
)
