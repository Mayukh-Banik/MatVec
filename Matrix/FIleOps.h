#pragma once

#include "Matrix.h"

Matrix* readCSV(const std::string& filepath, DTypes type = Real64);
bool writeCSV(const std::string& filepath, Matrix* m);