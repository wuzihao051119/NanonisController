# Copyright (c) 2025 Zihao Wu
# Use of this source code is governed by the MIT license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(NanonisControllerFunctionTest LANGUAGES CXX)

add_executable(NanonisControllerFunctionTest
    function.cpp
    ../../src/type.cpp ../../src/type.h
)
