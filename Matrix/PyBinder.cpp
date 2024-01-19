#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Class Definitions.h"

namespace py = pybind11;

PYBIND11_MODULE(MatVec, m) 
{
	m.doc() = "A Python Library built on C++ to perform 32 bit Floating Point Operations.";

	//py::class_<MatVec>(m, "MatVec")
	//	.def(py::init<std::vector<int>>())
	//	.def(py::init<float>(), "This will create an internal type of Scalar, use the generated ")
	//	.def("__str__", &MatVec::toString);

	py::class_<MatVec>(m, "MatVec")
		.def(py::init<std::vector<int>>())
		.def(py::init<float>())
		.def("__str__", &MatVec:: toString);
	
}

