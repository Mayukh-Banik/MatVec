#pragma once

#include <cstdint>
#include <cfloat>

enum DTypes {
    Int8 = 0,
    Int16 = 1,
    Int32 = 2,
    Int64 = 3,
    Real32 = 5,
    Real64 = 6,
    Real64T = 7
};

using dInt8 = int8_t;
using dInt16 = int16_t;
using dInt32 = int32_t;
using dInt64 = int64_t;
using dReal32 = float;
using dReal64 = double;
using dReal64T = long double;