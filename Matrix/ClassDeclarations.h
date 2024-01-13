#pragma once

#include "DataTypes.h"
#include <variant>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <vector>


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

    Matrix(std::vector<int> shape, DTypes::DTypes type = DTypes::dReal8);
    ~Matrix();
};

class Math {
public:
    using DataTypeVariant = std::variant<
        Scalar*, Vector*, Matrix*
    >;
    DataTypeVariant pointers;

    Math(std::vector<int> shape, DTypes::DTypes type = DTypes::dReal8);
    Math(double value, DTypes::DTypes type = DTypes::dReal8);
    Math(int value, DTypes::DTypes type = DTypes::dReal8);
    ~Math();
};