cmake_minimum_required(VERSION 2.8)

# project information
project(bif4-cge)
set(APPLICATION_NAME ${PROJECT_NAME})

# environment
set(CMAKE_CXX_FLAGS "-g -Wall")

# add subdirectories
add_subdirectory(src)