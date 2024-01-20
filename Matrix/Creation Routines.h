#pragma once
#include "Class Definitions.h"
#include <cstring>

MatVec* fill(std::vector<int> shape, float value);

MatVec* zero(std::vector<int> shape);

MatVec* ones(std::vector<int> shape);

MatVec* identity(int n);

MatVec* empty(std::vector<int> shape);