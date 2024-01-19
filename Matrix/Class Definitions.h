#pragma once

#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

class MatVec
{
public:
	float* data;
	std::vector<int> shape;
	unsigned long long int elementCount;
	bool isScalar;
	bool isVector;
	bool isMatrix;
	int stride;

	MatVec(std::vector<int> shape);
	MatVec(float n);

	~MatVec();

	std::string toString();
};