#include "Matrix.h"
//#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <pybind11/stl.h>


Matrix::Matrix(std::vector<int>& shape, int value)
{
	this->shape = shape;
	unsigned long long int product = 1;
	for (int i = 0; i < shape.size(); ++i) {
		product *= shape[i];
	}
	if (value == 0)
	{
		this->matrix = (int*)malloc(sizeof(int) * product);
	}
	else
	{
		this->matrix = (double*)malloc(sizeof(double) * product);
	}
	this->type = value;
	this->elements = product;
}


Matrix::~Matrix()
{
	free(this->matrix);
}


std::string Matrix::toString() {
	std::string result;
	for (unsigned long long int i = 0; i < this->elements; ++i) {
		if (this->type == 0) {
			// int type
			result += std::to_string(((int*)this->matrix)[i]);
			result += " ";
		}
		else {
			// double type
			result += std::to_string(((double*)this->matrix)[i]);
			result += " ";
		}
	}
	return result;
}