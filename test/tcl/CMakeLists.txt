cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(NanonisControllerTclTest LANGUAGES CXX)

add_executable(NanonisControllerTclTest
    tclcommand.cpp tclcommand.h
    main.cpp
)

target_include_directories(NanonisControllerTclTest PRIVATE C:/Libraries/tcl9.0.1/include)

target_link_libraries(NanonisControllerTclTest PRIVATE C:/Libraries/tcl9.0.1/lib/tcl90.lib C:/Libraries/tcl9.0.1/lib/tclstub.lib)
