#!/bin/sh

echo "Compiling unit tests..."
gyp --check --depth=. -f make --toplevel-dir=. -DTRAVIS_BUILD=ON && make
echo "Running unit tests..."
./out/Default/test
result=$?
echo "Unit tests completed : $result"
exit $result
