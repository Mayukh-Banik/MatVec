#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Constants/ClassConstants.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cuda_runtime.h>
#include <cuda.h>
#include <cuda_runtime_api.h>

/**
 * @brief Main MatVec Class with constructors
 * 
 */
class MatVec
{
public:
    MatVec()
    {
        this->Data = static_cast<double*>(malloc(0));
        this->ElementCount = 0;
        this->Dimension = {};
        this->Host = true;
    }

    MatVec(double value)
    {
        this->Data = static_cast<double*>(malloc(sizeof(double)));
        this->Data[0] = value;
        this->ElementCount = 1;
        this->Dimension = {1, 1};
        this->Host = true;
    }

    MatVec(std::vector<double>& values)
    {
        std::cout << "one array" << std::endl;
        this->Host = true;

    }

    MatVec(std::vector<std::vector<double>>& values)
    {
        std::cout << "2 array" << std::endl;
        this->Host = true;
    }

    ~MatVec()
    {
        if (this->Host == true)
        {
            free(this->Data);
        }
        else
        {
            cudaFree(this->Data);
        }
    }

private:
    double* Data = NULL;
    unsigned long long int ElementCount = 0;
    std::vector<unsigned long long int> Dimension = {};
    bool Host;
};
