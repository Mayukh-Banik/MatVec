#include "Matrix.h"
#include <cstring>
#include "Small Helper Functions.h"

//Matrix* Matrix::ones(std::vector<int>& shape, int type) 
//{
//    Matrix* m = new Matrix(shape, type);
//    //Matrix m(shape, type);
//    unsigned long long int product = m->elements;
//
//    if (type == 0) 
//    {
//        helper_fill(m->matrix, m->elements, 1, 0);
//        //int* mat = static_cast<int*>(m->matrix);
//        //std::fill(mat, mat + product, 1);
//    }
//    else 
//    {
//        helper_fill(m->matrix, m->elements, 1.0, 1);
//
//        //double* mat = static_cast<double*>(m->matrix);
//        //std::fill(mat, mat + product, 1.0);
//    }
//    return m;
//}
//
//Matrix* Matrix::zero(std::vector<int>& shape, int type) 
//{
//    Matrix* m = new Matrix(shape, type);
//    unsigned long long int product = m->elements;
//
//    // Calculate the total size in bytes
//    size_t totalSizeInBytes = product * (type == 0 ? sizeof(int) : sizeof(double));
//
//    // Use memset to set the memory to zero
//    memset(m->matrix, 0, totalSizeInBytes);
//    return m;
//}
//
//Matrix* Matrix::fill(std::vector<int>& shape, int type, long double value) 
//{
//    Matrix* m = new Matrix(shape, type);
//    unsigned long long int product = m->elements;
//    if (type == 0)
//    {
//        helper_fill(m->matrix, m->elements, value, 0);
//        //int* mat = static_cast<int*>(m->matrix);
//        //std::fill(mat, mat + product, (int) value);
//    }
//    else
//    {
//        helper_fill(m->matrix, m->elements, value, 1);
//        //double* mat = static_cast<double*>(m->matrix);
//        //std::fill(mat, mat + product, (double) value);
//    }
//    return m;
//}
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