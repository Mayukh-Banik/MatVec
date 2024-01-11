# Matrix

Making some rudimentary NumPy functions in a c++ shared library to be accesible in Python.

This is to complete Matrix/Tensor operations from scratch using Random, Ones, Zeros, and Filled 
arrays.

Loading from CSVs will be supported to ensure a test suite.

The goal is to support multithreading, using C threads or GPUs.

Will support some scalar, vector, and Matrix operations.

All errors will be uncaught and throw a Python exception. Exceptions will never be handled.
