![](glc.png)

# Golden Leaf Coin

# Requirements

___

+ [g++](https://gcc.gnu.org)
+ [Cmake](https://cmake.org)
+ [Vcpkg](https://vcpkg.io/en/index.html)
+ [GDB](https://www.sourceware.org/gdb/)
+ [Ninja](https://ninja-build.org)

# Dependecy

___

+ C++ 23

# Libraries
[Boost 1.81](https://www.boost.org), [fmt 9.1.0](https://github.com/fmtlib/fmt), [cryptopp 8.7](https://cryptopp.com), [spdlog 1.11.0](https://github.com/gabime/spdlog) 
# Run and Build

___

For Build, you need to install libs from vcpkg and build them, then you need to build application with Cmake

The Application will be of two types: GUI and CLI.

For CLI application type in Windows
use [Windows Terminal](https://apps.microsoft.com/store/detail/windows-terminal/9N0DX20HK701), because it works
correctly with unicode and escape sequences.
Also, logically CLI works in [WSL](https://learn.microsoft.com/en-us/windows/wsl/install) like Linux CLI Application.
Better choice for you is run application in Linux Distributives, 
