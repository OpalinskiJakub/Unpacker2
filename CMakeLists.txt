cmake_minimum_required(VERSION 3.22)
project(Unpacker2)

include_directories(include)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.58 REQUIRED)

find_package(ROOT CONFIG REQUIRED PATHS "/home/jakub/Opt/ROOT/root_v6.30.04.Linux-ubuntu22.04-x86_64-gcc11.4/root/cmake")


include_directories(${ROOT_INCLUDE_DIRS})

add_executable(Unpacker2
        src/EventIII.cc
        src/TDCChannel.cc
        src/Unpacker2.cc
        src/Unpacker2D.cc
        src/main.cpp
)
