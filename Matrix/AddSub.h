#pragma once

#include "Class Definitions.h"
#include <exception>

bool canBeAdded()
{
	return true;
}

MatVec* add(MatVec* m1, MatVec* m2)
{
	return nullptr;
}

void uFuncAdd(float* holder, float* m1, float* m2, unsigned long long int i, int step1, int step2)
{

	for (unsigned long long int x = 0; x < i; x++)
	{
		holder[x] = m1[x * step1] + m2[x * step2];
	}
}