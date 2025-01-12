cmake_minimum_required(VERSION 3.30)
project(HackAssembler)

set(CMAKE_CXX_STANDARD 20)

add_executable(HackAssembler main.cpp
        Parser.cpp
        Parser.h
        BinaryConverter.cpp
        BinaryConverter.h
        Utils.cpp
        Utils.h)
