#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Constants/ClassConstants.h"
#include <vector>
#include <cstdlib>
#include <iostream>


/**
 * @brief Main MatVec Class with constructors
 * 
 */
class MatVec
{
public:
    MatVec()
    {
        std::cout << "In default constructor" << std::endl;
        this->Data = nullptr;
        this->ElementCount = 0;
        this->Dimension = {};
    }

    MatVec(double value)
    {
        std::cout << "In single constructor" << std::endl;
        // std::cout << "1" << std::endl;
        this->Data = static_cast<double*>(malloc(sizeof(double)));
        // std::cout << "2" << std::endl;
        this->Data[0] = value;
        // std::cout << "3" << std::endl;
        this->ElementCount = 1;
        // std::cout << "4" << std::endl;
        this->Dimension = {1, 1};
        // std::cout << "5" << std::endl;
    }

    MatVec(const std::vector<double>& vec)
    {
        std::cout << "In vector constructor" << std::endl;

        this->ElementCount = vec.size();
        this->Dimension = {static_cast<unsigned long long int>(vec.size())};

        this->Data = static_cast<double*>(malloc(vec.size() * sizeof(double)));
        std::memcpy(this->Data, vec.data(), vec.size() * sizeof(double));
    }

    ~MatVec()
    {
        if (this->Data != nullptr) {
            free(this->Data);
        }
    }

private:
    double* Data;
    unsigned long long int ElementCount;
    std::vector<unsigned long long int> Dimension;
};
