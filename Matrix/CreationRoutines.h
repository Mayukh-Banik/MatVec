#pragma once

#include "Matrix.h"

/**
* @brief Makes a matrix where every value in memory is 1, according to DType passes
* Calls Constructor, potentially throws an exception, which will not be handled.
* @param shape Automatic Casting from Python List
* @param type Corresponds to data types from C++ Libraries
* @return New Instance of Matrix
*/
Matrix* ones(std::vector<int>& shape, DTypes type = Real64);

/**
 * @brief Makes a matrix where every value in memory is 0
 *	Calls Constructor, potentially throws an exception, which will not be handled.
 * @param shape Automatic Casting from Python List
 * @param type Corresponds to data types from C++ Libraries
 * @return New Instance of Matrix
*/
Matrix* zero(std::vector<int>& shape, DTypes type = Real64);

/**
 * @brief Makes a matrix where every value in memory is 1, according to DType passes
 *	Calls Constructor, potentially throws an exception, which will not be handled.
 * @param shape Automatic Casting from Python List
 * @param type Corresponds to data types from C++ Libraries
 * @param fill Fill data type, currently long double so templates don't have to be used on C++ end
 * @return New Instance of Matrix
*/
Matrix* fill(std::vector<int>& shape, DTypes type = Real64, long double fill = 0);

/**
 * @brief Makes a matrix where every value in major diagonal memory is 1, according to DType passes
 *	Calls Constructor, potentially throws an exception, which will not be handled.
 * @param n int of dimension
 * @param type Corresponds to data types from C++ Libraries
 * @return New Instance of Matrix
*/
Matrix* identity(int i, DTypes type = Real64);

/**
 * @brief Makes a matrix where every value in memory is random, according to DType passes
 *	Calls Constructor, potentially throws an exception, which will not be handled.
 * @param shape Automatic Casting from Python List
 * @param type Corresponds to data types from C++ Libraries
 * @param seed Seed
 * @return New Instance of Matrix
*/
Matrix* mrand(std::vector<int>& shape, DTypes type = Real64, int seed = 0);