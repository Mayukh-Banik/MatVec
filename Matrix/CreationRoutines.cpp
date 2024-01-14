#include "CreationRoutines.h"

Math* ones(pybind11::object obj, DTypes::DTypes type)
{
	Math* m = new Math(obj, type);
	return m;
}