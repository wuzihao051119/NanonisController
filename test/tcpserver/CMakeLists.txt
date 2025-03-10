# Copyright (c) 2025 Zihao Wu
# Use of this source code is governed by the MIT license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(NanonisControllerTcpServerTest LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

qt_standard_project_setup()

qt_add_executable(NanonisControllerTcpServerTest
    tcpserverwidget.cpp tcpserverwidget.h
    main.cpp
)

set_target_properties(NanonisControllerTcpServerTest PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(NanonisControllerTcpServerTest PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network)
