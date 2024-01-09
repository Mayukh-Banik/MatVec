#include "Matrix.h"
#include <cstring>

Matrix* Matrix::ones(std::vector<int>& shape, DTypes type) 
{
    Matrix* m = new Matrix(shape, type);
    unsigned long long int product = m->elements;
    for (unsigned long long int i = 0; i < m->elements; i++)
    {
        switch (type)
        {
        case Int8:
            ((dInt8*)m->matrix)[i] = 1;
            break;
        case Int16:
            ((dInt16*)m->matrix)[i] = 1;
            break;
        case Int32:
            ((dInt32*)m->matrix)[i] = 1;
            break;
        case Int64:
            ((dInt64*)m->matrix)[i] = 1;
            break;
        case Real32:
            ((dReal32*)m->matrix)[i] = 1;
            break;
        case Real64:
            ((dReal64*)m->matrix)[i] = 1;
            break;
        case Real64T:
            ((dReal64T*)m->matrix)[i] = 1;
            break;
        default:
            ((dReal64*)m->matrix)[i] = 1;
            break;
        }
    }
    return m;
}
//
Matrix* Matrix::zero(std::vector<int>& shape, DTypes type)
{
    Matrix* m = new Matrix(shape, type);
    unsigned long long int product = m->elements;

    // Calculate the total size in bytes
    size_t totalSizeInBytes = product * (type == 0 ? sizeof(int) : sizeof(double));

    // Use memset to set the memory to zero
    memset(m->matrix, 0, totalSizeInBytes);
    return m;
}
//
Matrix* Matrix::fill(std::vector<int>& shape, DTypes type, long double value)
{
    Matrix* m = new Matrix(shape, type);
    unsigned long long int product = m->elements;
    for (unsigned long long int i = 0; i < m->elements; i++)
    {
        switch (type)
        {
        case Int8:
            ((dInt8*)m->matrix)[i] = (dInt8)value;
            break;
        case Int16:
            ((dInt16*)m->matrix)[i] = (dInt16)value;
            break;
        case Int32:
            ((dInt32*)m->matrix)[i] = (dInt32)value;
            break;
        case Int64:
            ((dInt64*)m->matrix)[i] = (dInt64)value;
            break;
        case Real32:
            ((dReal32*)m->matrix)[i] = (dReal32)value;
            break;
        case Real64:
            ((dReal64*)m->matrix)[i] = (dReal64)value;
            break;
        case Real64T:
            ((dReal64T*)m->matrix)[i] = (dReal64T)value;
            break;
        default:
            ((dReal64*)m->matrix)[i] = (dReal64)value;
            break;
        }
    }
    return m;
}
//
//Matrix* Matrix::idnt(std::vector<int>& shape, int type)
//{
//    Matrix* m = new Matrix(shape, type);
//    unsigned long long int product = m->elements;
//    if (type == 0)
//    {
//        int* temp = (int*)m->matrix;
//    }
//    else
//    {
//        double* temp = (double*)m->matrix;
//    }
//    return m;
//}