#include "BasicOperations.h"
#include <iostream>

/**
 * @brief Compares two int vectors, checks btw 0->n-2 and if n-1 is the same of if v2 is 1
 * @param v1 
 * @param v2 
 * @return 
*/
static bool compareVectors(const std::vector<int>& v1, const std::vector<int>& v2) {
    if (v1.size() != v2.size()) 
    {
        return false;
    }
    for (size_t i = 0; i < v1.size() - 1; ++i) 
    {
        if (v1[i] != v2[i]) 
        {
            return false;
        }
    }
    if (v1.back() == v2.back() || v2.back() == 1) 
    {
        return true;
    }
    return false;
}

Matrix* mAdd(Matrix* m1, pybind11::object obj)
{
    namespace py = pybind11;

    if (py::isinstance<Matrix>(obj)) 
    {
        Matrix* m2 = py::cast<Matrix*>(obj);
        if (compareVectors(m1->shape, m2->shape) == false)
        {
            throw std::logic_error("Shape is incompatible");
            return nullptr;
        }
        if (m1->shape.back() != m2->shape.back())
        {
            
        }
        else
        {

        }
        std::cout << "Matrix";
    }
    else if (py::isinstance<py::int_>(obj)) {
        std::cout << "Int";
    }
    else if (py::isinstance<py::float_>(obj)) {
        std::cout << "Float";
    }
    else {
        std::cout << "Other type";
    }
    std::cout << std::endl;
    return nullptr;
}