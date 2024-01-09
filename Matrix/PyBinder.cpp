#define PYBIND11_DOCSTRINGS
#include <pybind11/pybind11.h>
#include "Matrix.h"
#include "DTypes.h"

PYBIND11_MODULE(matrix, m) {
    namespace py = pybind11;

    m.doc() = "A Poor Attempt at Recreating NumPy";

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
        .def("__str__", &Matrix::toString)
        .def_static("ones", &Matrix::ones, py::arg("shape"), py::arg("type") = DTypes::Real64)
        .def_static("zero", &Matrix::zero, py::arg("shape"), py::arg("type") = DTypes::Real64);
        //.def_static("fill", &Matrix::fill, py::arg("shape"), py::arg("type") = DTypes::Real64, py::arg("fill") = 0);


}
