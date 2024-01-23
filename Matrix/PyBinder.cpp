#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Class Definitions.h"
#include "AddSub.h"
#include "Creation Routines.h"

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
	
	m.def("fill", &fill, py::arg("shape"), py::arg("value"));
	m.def("zero", &zero, py::arg("shape"));
	m.def("ones", &ones, py::arg("shape"));
	m.def("identity", &identity, py::arg("n"));
	m.def("empty", &empty, py::arg("shape"));

	m.def("add", &add);
}

