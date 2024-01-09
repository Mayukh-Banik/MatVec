#pragma once
#include <vector>
#include <pybind11/stl.h>

class Matrix
{
private:
public:
	void* matrix = nullptr;
	std::vector<int> shape;
	unsigned long long int elements;
	int type;


	Matrix(std::vector<int>& shape, int value = 0);
	~Matrix();
	std::string toString();
	static Matrix ones(std::vector<int>& shape, int value = 0);
};