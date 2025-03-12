# NanonisController

## Overview

NanonisController is an application for controlling STM automatically.

At present, NanonisController supports:

- Bias
- BiasSwp
- BiasSpectr
- KelvinCtrl
- PDComp
- Current
- ZCtrl
- SafeTip
- AutoApproach
- ZSpectr
- Piezo
- Scan
- FolMe
- TipRec
- Pattern
- Marks
- TipShaper
- Motor
- GenSwp
- GenPICtrl
- AtomTrack
- LockIn
- LockInFreqSwp
- PLL
- PLLQCtrl
- PLLFreqSwp
- PLLPhasSwp
- PLLSignalAnlzr
- PLLZoomFFT
- OCSync
- Script
- Interf
- Laser
- BeamDefl
- Signals
- UserIn
- UserOut
- DigLines
- DataLog
- TCPLog
- OsciHR
- Osci1T
- Osci2T
- SignalChart
- SpectrumAnlzr
- FunGen1Ch
- FunGen2Ch
- Util

## Installing

Precompiled packages are available for Window (64 bits) on the [Release page](https://github.com/wuzihao051119/NanonisController/releases).

## Compiling (MSVC only now)

NanonisController requires several dependencies to correctly compile for development and production
builds. The following are the main pages of these dependencies.

* [CMake](https://cmake.org/)
* [Qt6](https://github.com/wuzihao051119/NanonisController/releases)
* [Tcl](https://www.tcl-lang.org/)

Building with CMake is fully supported. For example:

```bash
git clone https://github.com/wuzihao051119/NanonisController.git
mkdir build && cd build
cmake .. && cmake --build .
cmake --install .
```

## Usage

You can use C++, Tcl (Tool Command Language) to control the STM. The support of Python, C#, Java is
under development.

## Contributing

This project welcomes contributions and suggestions. You can help by looking at issues or helping
review PRs.

You can also contact me by [e-mail](mailto://wuzihao051119@gmail.com).

## Acknowledgements

Thanks to [Lin Jiao](mailto://lin.jiao@zju.edu.cn), [CCM (Certer for Correlated Matter)](http://ccm.zju.edu.cn/)
for their support during the development.

Thanks to my parents for bringing me up.

Thanks to my friend Xuran Liu for company.
