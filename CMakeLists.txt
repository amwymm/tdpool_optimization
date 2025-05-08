cmake_minimum_required(VERSION 3.30)
project(tdpool_optimization)

set(CMAKE_CXX_STANDARD 20)

add_executable(tdpool_optimization threadpool.h
        test.cpp)
