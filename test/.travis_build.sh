echo "Compiling unit tests..."
clang++ Main.cc -std=c++11 -lgtest -lpthread -o unit_test
echo "Running unit tests..."
./unit_test
result=$?
rm -r unit_test
echo "Unit tests completed : $result"
exit $result
