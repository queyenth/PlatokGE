#!/bin/sh

echo "Compiling unit tests..."
gyp --check --depth=. -f make --toplevel-dir=. && make
echo "Running unit tests..."
./out/Default/test
result=$?
coveralls || echo 'coveralls upload failed'
rm -rf out
echo "Unit tests completed : $result"
exit $result
