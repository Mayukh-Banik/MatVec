#include "BasicHelperFunctions.h"
#include <string>
#include <sstream>

template <typename T>
std::string toString(const T& value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}


template <typename T>
std::string templateArrayToString(T* array, unsigned long long int elements, int newline) {
    std::string temp;
    for (unsigned long long int i = 0; i < elements; i++) {
        temp += toString(array[i]) + ((i + 1) % newline == 0 ? "\n" : " ");
    }
    return temp;
}


#define TEMPLATE_DEFINITION(x) template std::string templateArrayToString<x>(x* array, unsigned long long int elements, int newline);
template std::string templateArrayToString<dInt1>(dInt1* array, unsigned long long int elements, int newline);
TEMPLATE_DEFINITION(dInt2)
TEMPLATE_DEFINITION(dInt4)
TEMPLATE_DEFINITION(dInt8)
TEMPLATE_DEFINITION(duInt1)
TEMPLATE_DEFINITION(duInt2)
TEMPLATE_DEFINITION(duInt4)
TEMPLATE_DEFINITION(duInt8)
TEMPLATE_DEFINITION(dReal4)
TEMPLATE_DEFINITION(dReal8)
#undef TEMPLATE_DEFINITION