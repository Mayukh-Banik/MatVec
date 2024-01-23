#pragma once

#include "Class Definitions.h"
#include <exception>

MatVec* createEmptyOfLargerScalar(MatVec* m1, MatVec* m2)
{
	if (m1->elementCount > m2->elementCount)
	{
		return m1->newEmpty();
	}
	return m2->newEmpty();
}

bool canBeAddSub(MatVec* m1, MatVec* m2)
{
	if (m1->isScalar || m2->isScalar)
	{
		return true;
	}
	if (m1->isMatrix && m2->isMatrix)
	{
		if (m1->shape != m2->shape)
		{
			return false;
		}
		return true;
	}
	if ((m1->isMatrix && m2->isVector) ||
		(m1->isVector && m2->isMatrix))
	{
		return false;
	}
	if (m1->isVector && m2->isVector)
	{
		if (m1->shape != m2->shape)
		{
			return false;
		}
	}
	return true;
}

void uFuncAdd(float* holder, float* m1, float* m2, unsigned long long int i, int step1, int step2)
{
	for (unsigned long long int x = 0; x < i; x++)
	{
		holder[x] = m1[x * step1] + m2[x * step2];
	}
}

MatVec* add(MatVec* m1, MatVec* m2)
{
	if (!canBeAddSub(m1, m2))
	{
		throw std::invalid_argument("Can't be added/subbed");
	}
	MatVec* XX = createEmptyOfLargerScalar(m1, m2);
	uFuncAdd(XX->data, m1->data, m2->data, XX->elementCount, m1->stride, m2->stride);
	return XX;
}