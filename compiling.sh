g++ -Wall -std=c++11 -O2 -c main.cpp -o main.o   # c++11 required for std::shared_ptr
g++ -ldl main.o -o main

g++ -O3 -std=c++17 -w -o a.out -I/usr/include src/testbug.cpp

