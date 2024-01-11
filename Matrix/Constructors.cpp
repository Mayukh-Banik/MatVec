#include "Matrix.h"
//#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <pybind11/stl.h>
#include "DTypes.h"
#include <cstdint>
#include <cfloat>
#include <cerrno>
#include <stdexcept>

Matrix::Matrix(std::vector<int>& shape, DTypes type)
{
	this->shape = std::vector<int>(shape);
	this->type = type;
	unsigned long long int product = 1;
	for (int i = 0; i < shape.size(); i++)
	{
		product = product * shape[i];
	}
	this->elements = product;
	switch (type)
	{
	case DTypes::Int8:
		this->size = sizeof(dInt8) * static_cast<size_t>(elements);
		break;
	case DTypes::Int16:
		this->size = sizeof(dInt16) * static_cast<size_t>(elements);
		break;
	case DTypes::Int32:
		this->size = sizeof(dInt32) * static_cast<size_t>(elements);
		break;
	case DTypes::Int64:
		this->size = sizeof(dInt64) * static_cast<size_t>(elements);
		break;
	case DTypes::Real32:
		this->size = sizeof(dReal32) * static_cast<size_t>(elements);
		break;
	case DTypes::Real64:
		this->size = sizeof(dReal64) * static_cast<size_t>(elements);
		break;
	case DTypes::Real64T:
		this->size = sizeof(dReal64T) * static_cast<size_t>(elements);
		break;
	default:
		throw std::invalid_argument("DType was something other than ENUM values.");
	}
	this->matrix = malloc(this->size);
	if (this->matrix == NULL)
	{
		throw std::bad_alloc();
	}
}


Matrix::~Matrix()
{
	free(this->matrix);
}


std::string Matrix::toString() {
	std::string result;
	for (unsigned long long int i = 0; i < this->elements; i++)
	{
		switch (type)
		{
		case DTypes::Int8:
			result += std::to_string(static_cast<int>(static_cast<dInt8*>(this->matrix)[i]));
			break;
		case DTypes::Int16:
			result += std::to_string(static_cast<int>(static_cast<dInt16*>(this->matrix)[i]));
			break;
		case DTypes::Int32:
			result += std::to_string(static_cast<int>(static_cast<dInt32*>(this->matrix)[i]));
			break;
		case DTypes::Int64:
			result += std::to_string(static_cast<int>(static_cast<dInt64*>(this->matrix)[i]));
			break;
		case DTypes::Real32:
			result += std::to_string(static_cast<double>(static_cast<dReal32*>(this->matrix)[i]));
			break;
		case DTypes::Real64:
			result += std::to_string(static_cast<double>(static_cast<dReal64*>(this->matrix)[i]));
			break;
		case DTypes::Real64T:
			result += std::to_string(static_cast<double>(static_cast<dReal64T*>(this->matrix)[i]));
			break;
		default:
			result += std::to_string(static_cast<double>(static_cast<dReal64*>(this->matrix)[i]));
			break;
		}

		if ((i+1) % this->shape[0] == 0)
		{
			result += "\n";
		}
		else
		{
			result += " ";
		}
	}

	return result;
}