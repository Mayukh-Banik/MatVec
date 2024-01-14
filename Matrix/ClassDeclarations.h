#pragma once

#include "DataTypes.h"
#include <variant>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <vector>
#include <exception>
#include <string>


class Scalar {
public:
    using DataTypeVariant = std::variant<
        dInt1*, dInt2*, dInt4*, dInt8*,
        duInt1*, duInt2*, duInt4*, duInt8*,
        dReal4*, dReal8*
    >;
    DataTypeVariant pointers;
    DTypes::DTypes type;
    void* Array;

    Scalar(pybind11::object obj, DTypes::DTypes type = DTypes::dReal8);
    ~Scalar();

    std::string toString();
};

class Vector {
public:
    using DataTypeVariant = std::variant<
        dInt1*, dInt2*, dInt4*, dInt8*,
        duInt1*, duInt2*, duInt4*, duInt8*,
        dReal4*, dReal8*
    >;
    DataTypeVariant pointers;

    DTypes::DTypes type;
    void* Array;
    unsigned long long int elements;
    std::vector<int> shape;
    

    Vector(std::vector<int> shape, DTypes::DTypes type = DTypes::dReal8);
    ~Vector();

    std::string toString();
};

class Matrix {
public:
    using DataTypeVariant = std::variant<
        dInt1*, dInt2*, dInt4*, dInt8*,
        duInt1*, duInt2*, duInt4*, duInt8*,
        dReal4*, dReal8*
    >;
    DataTypeVariant pointers;
    DTypes::DTypes type;
    void* Array;
    unsigned long long int elements;
    std::vector<int> shape;

    Matrix(std::vector<int> shape, DTypes::DTypes type = DTypes::dReal8);
    ~Matrix();

    std::string toString();
};

class Math {
public:
    using DataTypeVariant = std::variant<
        Scalar*, Vector*, Matrix*
    >;
    DataTypeVariant pointers;

    Scalar* scalar = nullptr;
    Vector* vector = nullptr;
    Matrix* matrix = nullptr;

    DTypes::DTypes type;

    Math(pybind11::object obj, DTypes::DTypes type = DTypes::dReal8);

    ~Math();

    std::string toString();
};