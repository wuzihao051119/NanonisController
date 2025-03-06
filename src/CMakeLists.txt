cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(NanonisController LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

qt_standard_project_setup()

set(functions_source
    functions/bias.cpp functions/bias.h
    functions/biasswp.cpp functions/biasswp.h
    functions/biasspectr.cpp functions/biasspectr.h
    functions/kelvinctrl.cpp functions/kelvinctrl.h
    functions/pdcomp.cpp functions/pdcomp.h
    functions/current.cpp functions/current.h
    functions/zctrl.cpp functions/zctrl.h
    functions/safetip.cpp functions/safetip.h
    functions/autoapproach.cpp functions/autoapproach.h
    functions/zspectr.cpp functions/zspectr.h
    functions/piezo.cpp functions/piezo.h
    functions/scan.cpp functions/scan.h
    functions/folme.cpp functions/folme.h
    functions/tiprec.cpp functions/tiprec.h
    functions/pattern.cpp functions/pattern.h
    functions/marks.cpp functions/marks.h
    functions/tipshaper.cpp functions/tipshaper.h
    functions/motor.cpp functions/motor.h
    functions/genswp.cpp functions/genswp.h
    functions/genpictrl.cpp functions/genpictrl.h
    functions/atomtrack.cpp functions/atomtrack.h
    functions/lockin.cpp functions/lockin.h
    functions/lockinfreqswp.cpp functions/lockinfreqswp.h
    functions/pll.cpp functions/pll.h
    functions/pllqctrl.cpp functions/pllqctrl.h
    functions/pllfreqswp.cpp functions/pllfreqswp.h
    functions/pllphasswp.cpp functions/pllphasswp.h
    functions/pllsignalanlzr.cpp functions/pllsignalanlzr.h
    functions/pllzoomfft.cpp functions/pllzoomfft.h
    functions/ocsync.cpp functions/ocsync.h
    functions/script.cpp functions/script.h
    functions/interf.cpp functions/interf.h
    functions/laser.cpp functions/laser.h
    functions/beamdefl.cpp functions/beamdefl.h
    functions/signals.cpp functions/signals.h
    functions/userin.cpp functions/userin.h
    functions/userout.cpp functions/userout.h
    functions/diglines.cpp functions/diglines.h
    functions/datalog.cpp functions/datalog.h
    functions/tcplog.cpp functions/tcplog.h
    functions/oscihr.cpp functions/oscihr.h
    functions/osci1t.cpp functions/osci1t.h
    functions/osci2t.cpp functions/osci2t.h
    functions/signalchart.cpp functions/signalchart.h
    functions/spectrumanlzr.cpp functions/spectrumanlzr.h
    functions/fungen1ch.cpp functions/fungen1ch.h
    functions/fungen2ch.cpp functions/fungen2ch.h
    functions/util.cpp functions/util.h
)

qt_add_executable(NanonisController
    ${functions_source}
    mainwindow.cpp mainwindow.h
    socket.cpp socket.h
    command.cpp command.h
    parser.h type.h macro.h
    main.cpp
)

set_target_properties(NanonisController PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(NanonisController PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network)
