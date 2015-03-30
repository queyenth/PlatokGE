#!/bin/sh

echo "Compiling unit tests..."
gyp --check --depth=. -f make --toplevel-dir=. && make
echo "Running unit tests..."
./out/Default/test
result=$?
rm -rf out
echo "Unit tests completed : $result"
exit $result
