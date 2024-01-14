#include "ClassDeclarations.h"
#include <cassert>
#include <iostream>
#include <string>
#include <variant>
#include "BasicHelperFunctions.h"

Scalar::Scalar(pybind11::object obj, DTypes::DTypes type)
{
	this->Array = nullptr;
	this->type = type;
#define FUNCTION_APPLIER(x) this->Array = new x[1]; static_cast<x*>(this->Array)[0] = obj.cast<x>(); break; 
	switch (type)
	{
	case DTypes::dInt1: FUNCTION_APPLIER(dInt1)
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt2)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt4)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt8)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	default: throw std::invalid_argument("DTypes passed value was incorrect"); break;
	}
#undef FUNCTION_APPLIER
}

Scalar::~Scalar()
{
#define FUNCTION_APPLIER(x) delete[] static_cast<x*>(this->Array); break;
	switch (this->type)
	{
	case DTypes::dInt1: delete[] static_cast<dInt1*>(this->Array); break;
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt2)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt4)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt8)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	}
#undef FUNCTION_APPLIER
}

std::string Scalar::toString()
{
	std::string temp = "Scalar Value: ";
	switch (this->type)
	{
#define FUNCTION_APPLIER(x) temp = temp + std::to_string(static_cast<x*>(Array)[0]); break;
	case DTypes::dInt1: temp = temp + std::to_string(static_cast<dInt1*>(Array)[0]); break;
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt2)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt4)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt8)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	}
	return temp;
}

Vector::Vector(std::vector<int> shape, DTypes::DTypes type)
{
	this->Array = nullptr;
	this->type = type;
	if (shape.size() == 2)
	{
		this->shape = std::vector<int>(shape);
	}
	else
	{
		this->shape = std::vector<int>(shape);
		this->shape.push_back(1);
	}
	this->elements = static_cast<decltype(this->elements)>(this->shape[0] * this->shape[1]);

#define FUNCTION_APPLIER(x) this->Array = new x[this->elements]; break;
	switch (type)
	{
	case DTypes::dInt1: FUNCTION_APPLIER(dInt1)
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt1)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	default: throw std::invalid_argument("DType was not valid"); break;
	}
#undef FUNCTION_APPLIER
}

Vector::~Vector()
{
#define FUNCTION_APPLIER(x) delete[] static_cast<x*>(this->Array); break;
	switch (this->type)
	{
	case DTypes::dInt1: delete[] static_cast<dInt1*>(this->Array); break;
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt2)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt4)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt8)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	}
#undef FUNCTION_APPLIER
}

std::string Vector::toString()
{
	std::string temp = "Vector Dimensions: [" + std::to_string(shape[0]) + ", " + std::to_string(shape[1]) + "]\n";
#define FUNCTION_APPLIER(x) temp = temp + templateArrayToString(static_cast<x*>(Array), this->elements, this->shape[0]); break;
	switch (this->type)
	{
	case DTypes::dInt1: temp = temp + templateArrayToString(static_cast<dInt1*>(Array), this->elements, this->shape[0]); break;
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt2)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt4)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt8)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	}
#undef FUNCTION_APPLIER
	return temp;
}

Matrix::Matrix(std::vector<int> shape, DTypes::DTypes type)
{
	this->Array = nullptr;
	this->type = type;
	this->shape = std::vector<int>(shape);
	this->elements = static_cast<decltype(this->elements)>(this->shape[0] * this->shape[1]);

#define FUNCTION_APPLIER(x) this->Array = new x[this->elements]; break;
	switch (type)
	{
	case DTypes::dInt1: FUNCTION_APPLIER(dInt1)
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt1)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	default: throw std::invalid_argument("DType was not valid"); break;
	}
#undef FUNCTION_APPLIER
}

Matrix::~Matrix()
{
#define FUNCTION_APPLIER(x) delete[] static_cast<x*>(this->Array); break;
	switch (this->type)
	{
	case DTypes::dInt1: delete[] static_cast<dInt1*>(this->Array); break;
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt2)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt4)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt8)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	default: throw std::invalid_argument("DType was not valid"); break;
	}
#undef FUNCTION_APPLIER
}

std::string Matrix::toString()
{
	std::string temp = "Matrix Dimensions: [" + std::to_string(shape[0]) + ", " + std::to_string(shape[1]) + "]\n";
	std::cout << "Hello" << ((double*)Array)[0] << std::endl;
#define FUNCTION_APPLIER(x) temp = temp + templateArrayToString(static_cast<x*>(Array), this->elements, this->shape[0]); break;
	switch (this->type)
	{
	case DTypes::dInt1: temp = temp + templateArrayToString(static_cast<dInt1*>(Array), this->elements, this->shape[0]); break;
	case DTypes::dInt2: FUNCTION_APPLIER(dInt2)
	case DTypes::dInt4: FUNCTION_APPLIER(dInt4)
	case DTypes::dInt8: FUNCTION_APPLIER(dInt8)
	case DTypes::duInt1: FUNCTION_APPLIER(duInt1)
	case DTypes::duInt2: FUNCTION_APPLIER(duInt2)
	case DTypes::duInt4: FUNCTION_APPLIER(duInt4)
	case DTypes::duInt8: FUNCTION_APPLIER(duInt8)
	case DTypes::dReal4: FUNCTION_APPLIER(dReal4)
	case DTypes::dReal8: FUNCTION_APPLIER(dReal8)
	}
#undef FUNCTION_APPLIER
	return temp;
}

Math::Math(pybind11::object obj, DTypes::DTypes type)
{
	this->scalar = nullptr;
	this->matrix = nullptr;
	this->vector = nullptr;

	if (pybind11::isinstance<pybind11::list>(obj)) 
	{
		try 
		{
			std::vector<int> shape = obj.cast<std::vector<int>>();
			if (shape.size() == 0 || shape.size() > 2)
			{
				throw std::invalid_argument("Number of parameters in list error");
			}
			if (shape.size() == 2)
			{
				if (shape[0] == 1 || shape[1] == 1)
				{
					this->vector = new Vector(shape, type);
					this->elements = this->vector->elements;
					this->Array = this->vector->Array;
				}
				else
				{
					this->matrix = new Matrix(shape, type);
					this->elements = this->matrix->elements;
					this->Array = this->matrix->Array;
				}
			}
			else
			{
				this->vector = new Vector(shape, type);
				this->elements = this->vector->elements;
				this->Array = this->vector->Array;
			}
		}
		catch (...) 
		{
			throw std::invalid_argument("Converting to an int list error");
		}
	}
	else if (pybind11::isinstance<pybind11::int_>(obj) || pybind11::isinstance<pybind11::float_>(obj))
	{
		this->scalar = new Scalar(obj, type);
		this->elements = 1;
		this->Array = this->scalar->Array;
	}
	else 
	{
		throw std::invalid_argument("Invalid data type passed");
	}
	this->type = type;
}

Math::~Math()
{
	delete this->matrix;
	delete this->scalar;
	delete this->vector;
}

std::string Math::toString()
{
	if (this->scalar != nullptr)
	{
		return this->scalar->toString();
	}
	else if (this->vector != nullptr)
	{
		return this->vector->toString();
	}
	else
	{
		return this->matrix->toString();
	}
}

int Math::getMathType()
{
	if (this->matrix != nullptr)
	{
		return 0;
	}
	else if (this->vector != nullptr)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}