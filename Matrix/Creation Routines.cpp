#include "Creation Routines.h"

MatVec* fill(std::vector<int> shape, float value)
{
	MatVec* m = new MatVec(shape);
	for (unsigned long long int i = 0; i < m->elementCount; i++)
	{
		m->data[i] = value;
	}
	return m;
}

MatVec* zero(std::vector<int> shape)
{
	MatVec* m = new MatVec(shape);
	memset(m->data, 0, sizeof(float) * m->elementCount);
	return m;
}

MatVec* ones(std::vector<int> shape)
{
	return fill(shape, 1);
}

MatVec* identity(int n)
{
	std::vector<int> shape = { n ,n };
	MatVec* m = zero(shape);
	unsigned long long int i = 0;
	while (i < m->elementCount)
	{
		m->data[i] = 1;
		i = i + n + 1;
	}
	return m;
}

MatVec* empty(std::vector<int> shape)
{
	return new MatVec(shape);
}