#pragma once
#include <vector>
#define PYBIND11_DOCSTRINGS
#include <pybind11/stl.h>
#include "DTypes.h"


class Matrix
{
private:
public:
	void* matrix = nullptr;
	std::vector<int> shape;
	unsigned long long int elements = 0;
	DTypes type = Real64;
	size_t size = 0;
	bool scalar = false;

	Matrix();
	Matrix(std::vector<int>& shape, DTypes type = Real64);
	~Matrix();
	std::string toString();

	/**
	 * @brief Makes a matrix where every value in memory is 1, according to DType passes
	 *	Calls Constructor, potentially throws an exception, which will not be handled.
	 * @param shape Automatic Casting from Python List
	 * @param type Corresponds to data types from C++ Libraries
	 * @return New Instance of Matrix
	*/
	static Matrix* ones(std::vector<int>& shape, DTypes type = Real64);

	/**
	 * @brief Makes a matrix where every value in memory is 0
	 *	Calls Constructor, potentially throws an exception, which will not be handled.
	 * @param shape Automatic Casting from Python List
	 * @param type Corresponds to data types from C++ Libraries
	 * @return New Instance of Matrix
	*/
	static Matrix* zero(std::vector<int>& shape, DTypes type = Real64);

	/**
	 * @brief Makes a matrix where every value in memory is 1, according to DType passes
	 *	Calls Constructor, potentially throws an exception, which will not be handled.
	 * @param shape Automatic Casting from Python List
	 * @param type Corresponds to data types from C++ Libraries
	 * @param fill Fill data type, currently long double so templates don't have to be used on C++ end
	 * @return New Instance of Matrix
	*/
	static Matrix* fill(std::vector<int>& shape, DTypes type = Real64, long double fill = 0);

	/**
	 * @brief Makes a matrix where every value in major diagonal memory is 1, according to DType passes
	 *	Calls Constructor, potentially throws an exception, which will not be handled.
	 * @param n int of dimension
	 * @param type Corresponds to data types from C++ Libraries
	 * @return New Instance of Matrix
	*/
	static Matrix* identity(int i, DTypes type = Real64);

	/**
	 * @brief Makes a matrix where every value in memory is random, according to DType passes
	 *	Calls Constructor, potentially throws an exception, which will not be handled.
	 * @param shape Automatic Casting from Python List
	 * @param type Corresponds to data types from C++ Libraries
	 * @param seed Seed
	 * @return New Instance of Matrix
	*/
	static Matrix* rand(std::vector<int>& shape, DTypes type = Real64, int seed = 0);


	static Matrix* readCSV(const std::string& filepath, DTypes type = Real64);
	static bool writeCSV(const std::string& filepath, Matrix* m);

	template <typename T>
	static Matrix* add(Matrix* m, T m1);
	
	template <typename T>
	static Matrix* sub(Matrix* m1, T m2);

	template <typename T>
	static Matrix* div(Matrix* m1, T m2);

	template <typename T>
	static Matrix* mul(Matrix* m1, T m2);
	static Matrix* transpose(Matrix* m1);
};

