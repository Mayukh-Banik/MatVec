#include "Class Definitions.h"
#include <exception>

MatVec::MatVec(std::vector<int> shape) 
{
	this->shape = shape;
	this->isScalar = false;
	this->isVector = false;
	this->isMatrix = false;
	this->elementCount = 1;
	for (int dim : shape) 
	{
		this->elementCount *= dim;
	}
	if (shape.size() == 1) 
	{
		if (shape[0] == 1) 
		{
			this->isScalar = true;
			this->shape.push_back(1);
		}
		else 
		{
			this->isVector = true;
			this->shape.push_back(1);
		}
	}
	else if (shape.size() == 2) 
	{
		if ((shape[0] == 1 && shape[1] != 1) || 
			(shape[1] == 1 && shape[0] != 1)) 
		{
			this->isVector = true;
		}
		else if (shape[0] != 1 && shape[1] != 1) 
		{
			this->isMatrix = true;
		}
		else if (shape[0] == 1 && shape[1] == 1) 
		{
			this->isScalar = true;
		}
	}
	else if (shape.size() > 2) 
	{
		throw std::invalid_argument("Tensors not Supported Yet.");
	}
	this->data = new float[elementCount];
	if (this->isScalar)
	{
		this->stride = 0;
	}
	else
	{
		this->stride = 1;
	}
}

MatVec::MatVec(float n)
{
	this->data = new float(n);
	this->shape = { 1,1 };
	this->elementCount = 1;
	this->isScalar = true;
	this->isVector = false;
	this->isMatrix = false;
	this->stride = 0;
}

MatVec::~MatVec()
{
	delete[] this->data;
}

std::string MatVec::toString()
{
	std::string s;
	if (this->isScalar)
	{
		s = s + "Scalar\n";
	}
	else if (this->isVector)
	{
		s = s + "Vector\n";
	}
	else
	{
		s = s + "Matrix";
	}
	s = s + "Shape: ";
	for (int i : this->shape)
	{
		s = s + std::to_string(i) + " ";
	}
	s = s + "\nNumber of values: " + std::to_string(this->elementCount) + "\nValues:\n";
	for (unsigned long long int i = 0; i < this->elementCount; i++)
	{
		s = s + std::to_string(this->data[i]) + " ";
		if (this->shape[0] % (i + 1) == 0)
		{
			s = s + "\n";
		}
	}
	return s;
}

//class MatVec
//{
//	float* array;
//	std::vector<int> shape;
//	unsigned long long int elementCount;
//	bool isScalar;
//	bool isVector;
//	bool isMatrix;
//
//	MatVec(std::vector<int> shape);
//	MatVec(float n);
//
//	~MatVec();
//};