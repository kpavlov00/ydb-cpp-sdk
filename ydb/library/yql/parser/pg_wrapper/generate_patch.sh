#!/usr/bin/env bash
set -u
rm -rf postgresql.patched
cp -a postgresql postgresql.patched
./copy_src.sh > /dev/null 2>&1
diff -ruN postgresql postgresql.patched
rm -rf postgresql.patched
