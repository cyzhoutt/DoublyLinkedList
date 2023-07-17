cmake_minimum_required(VERSION 3.13)
project(DllProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src)
add_subdirectory(testing)
