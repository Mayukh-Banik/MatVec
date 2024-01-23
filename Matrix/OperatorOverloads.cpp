#include "Class Definitions.h"
#include <string.h>
float& MatVec::operator[](unsigned long long int i) 
{
	if (!(this->isScalar) && 
		i >= this->elementCount) 
	{
		throw std::out_of_range("Index out of range");
	}
	return data[i * this->stride];
}

bool MatVec::operator==(const MatVec& rhs) const {
	if (this->shape != rhs.shape || 
		this->elementCount != rhs.elementCount)
	{
		return false;
	}
	int x = memcmp(this->data, rhs.data, (size_t) this->elementCount);
	if (x != 0)
	{
		return false;
	}
	return true;
}

bool MatVec::operator!=(const MatVec& rhs) const 
{
	if (this->shape != rhs.shape ||
		this->elementCount != rhs.elementCount)
	{
		return true;
	}
	int x = memcmp(this->data, rhs.data, (size_t)this->elementCount);
	if (x != 0)
	{
		return true;
	}
	return false;
}