#include <pybind11/pybind11.h>
#include <variant>
#include <iostream>

#include "DataTypes.h"
#include "ClassDeclarations.h"

namespace py = pybind11;

PYBIND11_MODULE(matrix, m) {
    m.doc() = "A module to implement numpy functions from scalars -> vectors -> 2D Matrixes"; 

    py::enum_ < DTypes::DTypes > (m, "DTypes")
        .value("dInt1", DTypes::dInt1)
        .value("dInt2", DTypes::dInt2)
        .value("dInt4", DTypes::dInt4)
        .value("dInt8", DTypes::dInt8)
        .value("duInt1", DTypes::duInt1)
        .value("duInt2", DTypes::duInt2)
        .value("duInt4", DTypes::duInt4)
        .value("duInt8", DTypes::duInt8)
        .value("dReal4", DTypes::dReal4)
        .value("dReal8", DTypes::dReal8)
        .export_values();

    py::class_<Scalar>(m, "Scalar")
        .def(py::init<py::object, DTypes::DTypes>(), py::arg("obj"), py::arg("type") = DTypes::dReal8);
}
