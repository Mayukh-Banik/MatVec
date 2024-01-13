#include "ClassDeclarations.h"
#include <cassert>
#include <iostream>
#include <string>
#include <variant>

Scalar::Scalar(pybind11::object obj, DTypes::DTypes type)
{
	this->Array = nullptr;
	this->type = type;
#define FUNCTION_APPLIER(x) Array = new x(); static_cast<x*>(Array)[0] = obj.cast<x>(); pointers = static_cast<x*>(Array); break; 
	switch (type)
	{
	case DTypes::dInt1: FUNCTION_APPLIER(dInt1)
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt2)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt4)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt8)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	default: throw std::invalid_argument("DTypes passed value was incorrect"); break;
	}
#undef FUNCTION_APPLIER
}

Scalar::~Scalar()
{
	std::visit([](auto&& arg) { delete arg; }, pointers);
}