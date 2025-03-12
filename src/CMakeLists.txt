# Copyright (c) 2025 Zihao Wu
# Use of this source code is governed by the MIT license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(NanonisController LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

qt_standard_project_setup()

qt_add_executable(NanonisController
    mainwindow.cpp mainwindow.h
    type.cpp type.h
    socket.cpp socket.h
    tclwrapper.cpp tclwrapper.h
    command.cpp command.h
    function.h format.h macro.h
    main.cpp
)

target_include_directories(NanonisController PRIVATE C:/Libraries/tcl9.0.1/include)

set_target_properties(NanonisController PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(NanonisController PRIVATE C:/Libraries/tcl9.0.1/lib/tcl90.lib C:/Libraries/tcl9.0.1/lib/tclstub.lib)
target_link_libraries(NanonisController PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network)

install(TARGETS NanonisController
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET NanonisController
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
