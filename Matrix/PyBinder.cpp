#define PYBIND11_DOCSTRINGS
#include <pybind11/pybind11.h>
#include "Matrix.h"
#include "DTypes.h"
#include "CreationRoutines.h"
#include "FileOps.h"
#include "BasicOperations.h"

PYBIND11_MODULE(matrix, m) {
    namespace py = pybind11;

    m.doc() = "A Poor Attempt at Recreating NumPy for Matrices Only";

    py::enum_<DTypes>(m, "DTypes")
        .value("Int8", DTypes::Int8)
        .value("Int16", DTypes::Int16)
        .value("Int32", DTypes::Int32)
        .value("Int64", DTypes::Int64)
        .value("Real32", DTypes::Real32)
        .value("Real64", DTypes::Real64)
        .value("Real64T", DTypes::Real64T)
        .export_values();

    py::class_<Matrix>(m, "matrix")
        .def(py::init<std::vector<int>&, DTypes>(), py::arg("shape"), py::arg("type") = DTypes::Real64)
        .def("__str__", &Matrix::toString);
        
    m.def("readCSV", readCSV, py::arg("file"), py::arg("type") = DTypes::Real64);
    m.def("writeCSV", writeCSV, py::arg("file"), py::arg("Matrix"));
    m.def("ones", &ones, py::arg("shape"), py::arg("type") = DTypes::Real64);
    m.def("zero", &zero, py::arg("shape"), py::arg("type") = DTypes::Real64);
    m.def("fill", &fill, py::arg("shape"), py::arg("type") = DTypes::Real64, py::arg("fill") = 0);
    m.def("identity", &identity, py::arg("n"), py::arg("type") = DTypes::Real64);
    m.def("rand", &mrand, py::arg("shape"), py::arg("type") = DTypes::Real64, py::arg("seed") = 0);

    m.def("add", &mAdd);
}