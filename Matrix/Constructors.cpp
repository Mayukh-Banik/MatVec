#include "Matrix.h"
//#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <pybind11/stl.h>
#include "DTypes.h"
#include <cstdint>
#include <cfloat>

Matrix::Matrix(std::vector<int>& shape, DTypes type)
{
	this->shape = shape;
	this->type = type;
	unsigned long long int product = 1;
	for (int i = 0; i < shape.size(); i++)
	{
		product = shape[i];
	}
	this->elements = product;
	switch (type)
	{
	case DTypes::Int8:
		this->matrix = malloc(sizeof(dInt8) * elements);
		break;
	case DTypes::Int16:
		this->matrix = malloc(sizeof(dInt16) * elements);
		break;
	case DTypes::Int32:
		this->matrix = malloc(sizeof(dInt32) * elements);
		break;
	case DTypes::Int64:
		this->matrix = malloc(sizeof(dInt64) * elements);\
			break;
	case DTypes::Real32:
		this->matrix = malloc(sizeof(dReal32) * elements);
		break;
	case DTypes::Real64:
		this->matrix = malloc(sizeof(dReal64) * elements);
		break;
	case DTypes::Real64T:
		this->matrix = malloc(sizeof(dReal64T) * elements);
		break;
	default:
		this->matrix = malloc(sizeof(dReal64) * elements);
		break;
	}
}


Matrix::~Matrix()
{
	free(this->matrix);
}


const std::string Matrix::toString() {
	std::string result;
	for (unsigned long long int i = 0; i < this->elements; i++)
	{
		switch (type)
		{
		case DTypes::Int8:
			result += std::to_string(((dInt8*)this->matrix)[i]);
			break;
		case DTypes::Int16:
			result += std::to_string(((dInt16*)this->matrix)[i]);
			break;
		case DTypes::Int32:
			result += std::to_string(((dInt32*)this->matrix)[i]);
			break;
		case DTypes::Int64:
			result += std::to_string(((dInt64*)this->matrix)[i]);
			break;
		case DTypes::Real32:
			result += std::to_string(((dReal32*)this->matrix)[i]);
			break;
		case DTypes::Real64:
			result += std::to_string(((dReal64*)this->matrix)[i]);
			break;
		case DTypes::Real64T:
			result += std::to_string(((dReal64T*)this->matrix)[i]);
			break;
		default:
			result += std::to_string(((dReal64*)this->matrix)[i]);
			break;
		}
		result += " ";
	}
	return result;
}