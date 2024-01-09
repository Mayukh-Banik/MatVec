#pragma once
#include <vector>
#define PYBIND11_DOCSTRINGS
#include <pybind11/stl.h>
#include "DTypes.h"
#include <>
class Matrix
{
private:
public:
	void* matrix = nullptr;
	std::vector<int> shape;
	unsigned long long int elements;
	DTypes type;

	Matrix(std::vector<int>& shape, DTypes type = Real64);
	~Matrix();
	const std::string toString();


	static Matrix* ones(std::vector<int>& shape, DTypes type = Real64);
	static Matrix* zero(std::vector<int>& shape, DTypes type = Real64);
	static Matrix* fill(std::vector<int>& shape, DTypes type = Real64, long double fill = 0);
	//static Matrix* idnt(std::vector<int>& shape, int value = 0);
};

