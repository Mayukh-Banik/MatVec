#include <iostream>
#include <pybind11/pybind11.h>
#include <Classes/MatVec.h>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(MatVec, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");

    py::class_<MatVec>(m, "MatVec")
        .def(py::init<>())
        .def(py::init<double>())
        .def(py::init<const std::vector<double>>());
}
