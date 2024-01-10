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
	unsigned long long int elements;
	DTypes type;
	size_t size;

	Matrix(std::vector<int>& shape, DTypes type = Real64);
	~Matrix();
	std::string toString();


	static Matrix* ones(std::vector<int>& shape, DTypes type = Real64);
	static Matrix* zero(std::vector<int>& shape, DTypes type = Real64);
	static Matrix* fill(std::vector<int>& shape, DTypes type = Real64, long double fill = 0);
	static Matrix* identity(std::vector<int>& shape, DTypes type = Real64);
	static Matrix* rand(std::vector<int>& shape, DTypes type = Real64, int seed = 0);
};

