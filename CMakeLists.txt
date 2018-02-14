
include(cmake/OpenCVPCHSupport.cmake)

cmake_minimum_required(VERSION 2.8)

project(cv)

find_package(OpenCV REQUIRED)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -std=c++11 -O0 -Wall -g -ggdb ")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -std=c++11 -O3 -Wall ")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

ocv_add_precompiled_header_to_target(main.cpp precomp.hpp)
ocv_add_precompiled_header_to_target(config.cpp precomp.hpp)
ocv_add_precompiled_header_to_target(src/precomp.cpp precomp.hpp)

add_library(precomp src/precomp.cpp)

add_executable(cv main.cpp config.cpp)
target_link_libraries(cv ${OpenCV_LIBS} precomp pthread gflags)
