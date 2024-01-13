#pragma once

#include <cstdint>
#include <complex>

namespace DTypes{
	enum DTypes
	{
		dInt1 = 0,
		dInt2 = 1,
		dInt4 = 2,
		dInt8 = 3,
		duInt1 = 4,
		duInt2 = 5,
		duInt4 = 6,
		duInt8 = 7,
		dReal4 = 8,
		dReal8 = 9,
	};

}

using dInt1 = int8_t;
using dInt2 = int16_t;
using dInt4 = int32_t;
using dInt8 = int64_t;
using duInt1 = uint8_t;
using duInt2 = uint16_t;
using duInt4 = uint32_t;
using duInt8 = uint64_t;
using dReal4 = float;
using dReal8 = double;
