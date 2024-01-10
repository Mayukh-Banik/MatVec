#include "Matrix.h"
#include <cstring>
#include <cstdlib>
#include <ctime>

Matrix* Matrix::ones(std::vector<int>& shape, DTypes type)
{
    Matrix* m = new Matrix(shape, type);
    for (unsigned long long int i = 0; i < m->elements; i++)
    {
        switch (type)
        {
        case Int8:
            static_cast<dInt8*>(m->matrix)[i] = 1;
            break;
        case Int16:
            static_cast<dInt16*>(m->matrix)[i] = 1;
            break;
        case Int32:
            static_cast<dInt32*>(m->matrix)[i] = 1;
            break;
        case Int64:
            static_cast<dInt64*>(m->matrix)[i] = 1;
            break;
        case Real32:
            static_cast<dReal32*>(m->matrix)[i] = 1;
            break;
        case Real64:
            static_cast<dReal64*>(m->matrix)[i] = 1;
            break;
        case Real64T:
            static_cast<dReal64T*>(m->matrix)[i] = 1;
            break;
        default:
            static_cast<dReal64*>(m->matrix)[i] = 1;
            break;
        }
    }
    return m;
}

Matrix* Matrix::zero(std::vector<int>& shape, DTypes type)
{
    Matrix* m = new Matrix(shape, type);
    unsigned long long int product = m->elements;
    size_t totalSizeInBytes = product * (type == 0 ? sizeof(int) : sizeof(double));
    memset(m->matrix, 0, totalSizeInBytes);
    return m;
}

Matrix* Matrix::fill(std::vector<int>& shape, DTypes type, long double value)
{
    Matrix* m = new Matrix(shape, type);
    unsigned long long int product = m->elements;
    for (unsigned long long int i = 0; i < m->elements; i++)
    {
        switch (type)
        {
        case Int8:
            static_cast<dInt8*>(m->matrix)[i] = static_cast<dInt8>(value);
            break;
        case Int16:
            static_cast<dInt16*>(m->matrix)[i] = static_cast<dInt16>(value);
            break;
        case Int32:
            static_cast<dInt32*>(m->matrix)[i] = static_cast<dInt32>(value);
            break;
        case Int64:
            static_cast<dInt64*>(m->matrix)[i] = static_cast<dInt64>(value);
            break;
        case Real32:
            static_cast<dReal32*>(m->matrix)[i] = static_cast<dReal32>(value);
            break;
        case Real64:
            static_cast<dReal64*>(m->matrix)[i] = static_cast<dReal64>(value);
            break;
        case Real64T:
            static_cast<dReal64T*>(m->matrix)[i] = static_cast<dReal64T>(value);
            break;
        default:
            static_cast<dReal64*>(m->matrix)[i] = static_cast<dReal64>(value);
            break;
        }
    }
    return m;
}

Matrix* Matrix::identity(std::vector<int>& shape, DTypes type)
{
    Matrix* m = new Matrix(shape, type);
    memset(m->matrix, 0, m->size);
    int n = shape[0];
    for (int i = 0; i < n; i++)
    {
        switch (type)
        {
        case Int8:
            static_cast<dInt8*>(m->matrix)[i * n + i] = static_cast<dInt8>(1);
            break;
        case Int16:
            static_cast<dInt16*>(m->matrix)[i * n + i] = static_cast<dInt16>(1);
            break;
        case Int32:
            static_cast<dInt32*>(m->matrix)[i * n + i] = static_cast<dInt32>(1);
            break;
        case Int64:
            static_cast<dInt64*>(m->matrix)[i * n + i] = static_cast<dInt64>(1);
            break;
        case Real32:
            static_cast<dReal32*>(m->matrix)[i * n + i] = static_cast<dReal32>(1);
            break;
        case Real64:
            static_cast<dReal64*>(m->matrix)[i * n + i] = static_cast<dReal64>(1);
            break;
        case Real64T:
            static_cast<dReal64T*>(m->matrix)[i * n + i] = static_cast<dReal64T>(1);
            break;
        default:
            static_cast<dReal64*>(m->matrix)[i * n + i] = static_cast<dReal64>(1);
            break;
        }
    }
    return m;
}

Matrix* Matrix::rand(std::vector<int>& shape, DTypes type, int seed)
{
    Matrix* m = new Matrix(shape, type);
    unsigned long long int product = m->elements;
    for (unsigned long long int i = 0; i < m->elements; i++)
    {
        std::srand(seed == 0 ? std::time(nullptr) : seed);
        int value = std::rand();
        switch (type)
        {
        case Int8:
            static_cast<dInt8*>(m->matrix)[i] = static_cast<dInt8>(value);
            break;
        case Int16:
            static_cast<dInt16*>(m->matrix)[i] = static_cast<dInt16>(value);
            break;
        case Int32:
            static_cast<dInt32*>(m->matrix)[i] = static_cast<dInt32>(value);
            break;
        case Int64:
            static_cast<dInt64*>(m->matrix)[i] = static_cast<dInt64>(value);
            break;
        case Real32:
            static_cast<dReal32*>(m->matrix)[i] = static_cast<dReal32>(value);
            break;
        case Real64:
            static_cast<dReal64*>(m->matrix)[i] = static_cast<dReal64>(value);
            break;
        case Real64T:
            static_cast<dReal64T*>(m->matrix)[i] = static_cast<dReal64T>(value);
            break;
        default:
            static_cast<dReal64*>(m->matrix)[i] = static_cast<dReal64>(value);
            break;
        }
    }
    return m;
}

Matrix* Matrix::array(std::vector<std::vector<int>>& value, DTypes type)
{
    unsigned long long int elements = 0;
    for (std::vector<int> temp : value)
    {
        elements = elements + temp.size();
    }
    return nullptr;
}