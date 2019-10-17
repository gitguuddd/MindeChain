cmake_minimum_required(VERSION 3.13)
project(MindeChain)

set(CMAKE_CXX_STANDARD 14)
#[[set(CMAKE_CXX_FLAGS -O3)]]

add_executable(MindeChain src/main.cpp src/Helperfuncs.h src/Helperfuncs.cpp src/User.h src/HashFuncs.h src/HashFuncs.cpp src/MindeHash.h src/Transaction.h)