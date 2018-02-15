
include(cmake/OpenCVPCHSupport.cmake)

cmake_minimum_required(VERSION 2.8)

project(cv)

find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)
find_package(gflags REQUIRED)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -std=c++11 -O0 -Wall -g -ggdb ")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -std=c++11 -O3 -Wall ")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

include_directories(./ include/ ${OpenCV_INCLUDE_DIR} ${gflags_INCLUDE_DIR})

ocv_add_precompiled_header_to_target(main.cpp precomp.hpp)
ocv_add_precompiled_header_to_target(config.cpp precomp.hpp)
ocv_add_precompiled_header_to_target(src/precomp.cpp precomp.hpp)

add_executable(cv main.cpp src/precomp.cpp config.cpp images_read.cpp images_process.cpp)
target_link_libraries(cv ${OpenCV_LIBS} ${gflags_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
