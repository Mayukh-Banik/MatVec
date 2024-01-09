#pragma once
#include <vector>
#include <pybind11/stl.h>
#include "Small Helper Functions.h"

class Matrix
{
private:
public:
	void* matrix = nullptr;
	std::vector<int> shape;
	unsigned long long int elements;
	int type;

	Matrix();
	Matrix(std::vector<int>& shape, int value = 0);
	~Matrix();
	std::string toString();


	static Matrix* ones(std::vector<int>& shape, int value = 0);
	static Matrix* zero(std::vector<int>& shape, int value = 0);
	static Matrix* fill(std::vector<int>& shape, int value = 0, long double fill = 0);
};

