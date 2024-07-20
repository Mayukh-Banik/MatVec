#pragma once

#include <pybind11/pybind11.h>
#include "Constants/ClassConstants.h"

/**
 * @brief Main MatVec Class with constructors
 * 
 */
class MatVec
{
public:
    MatVec()
    {
        this->Data = nullptr;
        this->ElementCount = 0;
        this->Dimension = nullptr;
    }
    MatVec(double value);
    MatVec(double* value);
    
private:
    double* Data;
    unsigned long long int ElementCount;
    unsigned long long int* Dimension;

};