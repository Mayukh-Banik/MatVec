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

	MatVec()
	{
		this->data = nullptr;
		this->shape = { 0 };
		this->elementCount = 0;
		this->isScalar = false;
		this->isMatrix = false;
		this->isVector = false;
		this->stride = 0;
	}

	MatVec(std::vector<int> shape);
	MatVec(float n);

	~MatVec();

	std::string toString();

	float& operator[](unsigned long long int i);

    // Comparison operators
    bool operator==(const MatVec& rhs) const;
    bool operator!=(const MatVec& rhs) const;

	MatVec* newEmpty()
	{
		MatVec* x = new MatVec();
		x->data = new float[this->elementCount];
		x->shape = std::vector<int>(this->shape);
		x->elementCount = this->elementCount;
		x->isScalar = this->isScalar;
		x->isVector = this->isVector;
		x->isMatrix = this->isMatrix;
		x->stride = this->stride;
		return x;
	}
};