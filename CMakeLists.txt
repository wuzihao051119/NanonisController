cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(NanonisController LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(/Zc:preprocessor)

add_subdirectory(src)
add_subdirectory(test)
