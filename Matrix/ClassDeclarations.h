#pragma once

#include "DataTypes.h"
#include <variant>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <vector>
#include <exception>
#include <string>

class Scalar;
class Vector;
class Matrix;
class Math;

class Scalar {
public:
    DTypes::DTypes type;
    void* Array;

    Scalar(pybind11::object obj, DTypes::DTypes type = DTypes::dReal8);
    ~Scalar();

    std::string toString();
};

class Vector {
public:
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
    Scalar* scalar = nullptr;
    Vector* vector = nullptr;
    Matrix* matrix = nullptr;

    DTypes::DTypes type;
    unsigned long long int elements;
    void* Array = nullptr;

    Math(pybind11::object obj, DTypes::DTypes type = DTypes::dReal8);

    ~Math();

    std::string toString();
    int getMathType();
};