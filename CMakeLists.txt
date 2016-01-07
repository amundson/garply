cmake_minimum_required(VERSION 3.0.0)
project(GARPLY)

include_directories(${GARPLY_SOURCE_DIR})
enable_testing()

add_subdirectory(garply)
add_subdirectory(tests)
