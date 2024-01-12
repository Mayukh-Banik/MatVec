#pragma once

#include "Matrix.h"
#include <pybind11/pybind11.h>

Matrix* mAdd(Matrix* m1, pybind11::object obj);