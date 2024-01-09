#include <Windows.h>
#include <pybind11/pybind11.h>
#include "Matrix.h"

namespace py = pybind11;

PYBIND11_MODULE(matrix, m) {
    m.doc() = "A copy of numpy basic features, using single threaded cpu, multi-threading on CPUs, or GPUS.";

    py::class_<Matrix>(m, "matrix")
        .def(py::init<std::vector<int>&, int>(), py::arg("shape"), py::arg("type") = 0)
        .def("__str__", &Matrix::toString)
        .def_static("ones", &Matrix::ones, py::arg("shape"), py::arg("type") = 0)
        .def_static("zero", &Matrix::zero, py::arg("shape"), py::arg("type") = 0);
}