cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(NanonisController LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

qt_standard_project_setup()

qt_add_executable(NanonisController
    mainwindow.cpp mainwindow.h
    socket.cpp socket.h
    command.cpp command.h
    function.h format.h type.h macro.h
    main.cpp
)

target_include_directories(NanonisController PRIVATE C:/Libraries/tcl9.0.1/include)

set_target_properties(NanonisController PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(NanonisController PRIVATE C:/Libraries/tcl9.0.1/lib/tcl90.lib C:/Libraries/tcl9.0.1/lib/tclstub.lib)
target_link_libraries(NanonisController PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network)
