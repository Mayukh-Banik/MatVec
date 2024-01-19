## MatVec

A simple library (hopefully) to implement Vector/Matrix operations. Only for 32 bit Floating Point Values.

Initially aiming at basic operations (multiplication, transpose, etc) but will support several computing types: serial, BLAS, multithreading: C/C++ threads, and GPU versions.

# Installation Guide:

The PYD file is located in x64/Debug/matrix.pyd. Copy and paste into a Windows 11 system to import and use.

# Building:

This was made using the latest version of Visual Studio 2022 as of Jan 1. 
Follow this guide here: https://learn.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2022
Set C++ version to 17. Python 3.12 is currently not supported by VS, alert boxes that can't be disabled always run, so don't use Python 3.12.
