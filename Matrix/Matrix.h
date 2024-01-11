#pragma once
#include <vector>
#define PYBIND11_DOCSTRINGS
#include <pybind11/stl.h>
#include "DTypes.h"


class Matrix
{
private:
public:
	void* matrix = nullptr;
	std::vector<int> shape;
	unsigned long long int elements = 0;
	DTypes type = Real64;
	size_t size = 0;
	bool scalar = false;
	Matrix(std::vector<int>& shape, DTypes type = Real64);
	~Matrix();
	std::string toString();
};

