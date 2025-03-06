cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(NanonisControllerFormatTest LANGUAGES CXX)
project(NanonisControllerBiasTest LANGUAGES CXX)

add_executable(NanonisControllerFormatTest
    format.cpp
)

add_executable(NanonisControllerBiasTest
    bias.cpp
)
