cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME "algorithm-problems")
set(CMAKE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

project(${PROJECT_NAME})

enable_testing()

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
