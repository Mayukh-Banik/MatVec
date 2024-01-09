#include "Small Helper Functions.h"

void helper_fill(void* pointer, unsigned long long int elements, 
	long double fill, int type)
{
	if (type == 0)
	{
		for (unsigned long long int i = 0; i < elements; i++)
		{
			((int*)pointer)[i] = (int)fill;
		}
	}
	else
	{
		for (unsigned long long int i = 0; i < elements; i++)
		{
			((double*)pointer)[i] = (double)fill;
		}
	}
}