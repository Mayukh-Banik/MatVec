#include <iostream>
#include <pybind11/pybind11.h>
#include <Classes/MatVec.h>

namespace py = pybind11;

PYBIND11_MODULE(MatVec, m) 
{
    m.doc() = "MatVec, a simple constant, vector, matrix multiplication package. CPU/GPU supported"; 
    py::class_<MatVec>(m, "MatVec")
        .def(py::init<>())
        .def(py::init<double>())
        .def(py::init<std::vector<double>&>())
        .def(py::init<std::vector<std::vector<double>>&>());
}
