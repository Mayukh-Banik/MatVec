#include "CreationRoutines.h"

Math* ones(pybind11::object obj, DTypes::DTypes type)
{
	Math* m = new Math(obj, type);
	int n = m->getMathType();
	switch (n)
	{
	case 0: 
		break;
	case 1: break;
	default: break;
	}
	return m;
}