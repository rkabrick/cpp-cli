cmake_minimum_required(VERSION 3.24)
project(my-cli)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(my-cli
    src/Main.cc
    src/Command.cc
)
