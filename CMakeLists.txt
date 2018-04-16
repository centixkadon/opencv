
cmake_minimum_required(VERSION 2.8)

project(cv)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CONFIGURATION_TYPES Debug;${CMAKE_BUILD_TYPE})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(libexstl PATHS .. REQUIRED)
find_package(libimages PATHS .. REQUIRED)

add_subdirectory(${libexstl_PATH} libexstl)
add_subdirectory(${libimages_PATH} libimages)

include_directories(${libexstl_INCLUDE_DIR} ${libimages_INCLUDE_DIR})

add_subdirectory(src)
