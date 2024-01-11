#include "Matrix.h"
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "CreationRoutines.h"

Matrix* ones(std::vector<int>& shape, DTypes type)
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

Matrix* mrand(std::vector<int>& shape, DTypes type, int seed)
{
    Matrix* m = new Matrix(shape, type);
    unsigned long long int product = m->elements;
    for (unsigned long long int i = 0; i < m->elements; i++)
    {
        std::srand(seed == 0 ? static_cast<unsigned int> (std::time(nullptr)) : seed);
        //int value = std::rand();
        switch (type)
        {
        case Int8:
            static_cast<dInt8*>(m->matrix)[i] = static_cast<dInt8>(std::rand());
            break;
        case Int16:
            static_cast<dInt16*>(m->matrix)[i] = static_cast<dInt16>(std::rand());
            break;
        case Int32:
            static_cast<dInt32*>(m->matrix)[i] = static_cast<dInt32>(std::rand());
            break;
        case Int64:
            static_cast<dInt64*>(m->matrix)[i] = static_cast<dInt64>(std::rand());
            break;
        case Real32:
            static_cast<dReal32*>(m->matrix)[i] = static_cast<dReal32>(std::rand());
            break;
        case Real64:
            static_cast<dReal64*>(m->matrix)[i] = static_cast<dReal64>(std::rand());
            break;
        case Real64T:
            static_cast<dReal64T*>(m->matrix)[i] = static_cast<dReal64T>(std::rand());
            break;
        default:
            static_cast<dReal64*>(m->matrix)[i] = static_cast<dReal64>(std::rand());
            break;
        }
    }
    return m;
}

Matrix* zero(std::vector<int>& shape, DTypes type)
{
    Matrix* m = new Matrix(shape, type);
    memset(m->matrix, 0, m->size);
    return m;
}

Matrix* fill(std::vector<int>& shape, DTypes type, long double value)
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

Matrix* identity(int n, DTypes type)
{
    std::vector<int> shape = { n, n };
    Matrix* m = new Matrix(shape, type);
    memset(m->matrix, 0, m->size);
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