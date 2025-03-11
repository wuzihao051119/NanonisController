# Copyright (c) 2025 Zihao Wu
# Use of this source code is governed by the MIT license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(NanonisController LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(/Zc:preprocessor /utf-8)

add_subdirectory(src)
add_subdirectory(test)
