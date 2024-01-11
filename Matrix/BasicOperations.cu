#include "BasicOperations.h"

template <typename T>
Matrix* mAdd(Matrix* m1, T m2)
{
	return nullptr;
}

template Matrix* mAdd<dInt8>(Matrix* m1, dInt8 m2);
template Matrix* mAdd<dInt16>(Matrix* m1, dInt16 m2);
template Matrix* mAdd<dInt32>(Matrix* m1, dInt32 m2);
template Matrix* mAdd<dInt64>(Matrix* m1, dInt64 m2);
template Matrix* mAdd<dReal32>(Matrix* m1, dReal32 m2);
template Matrix* mAdd<dReal64>(Matrix* m1, dReal64 m2);
template Matrix* mAdd<dReal64T>(Matrix* m1, dReal64T m2);

// Subtraction
template <typename T>
Matrix* mSub(Matrix* m1, T m2)
{
    return nullptr;  // Implement your logic here
}

template Matrix* mSub<dInt8>(Matrix* m1, dInt8 m2);
template Matrix* mSub<dInt16>(Matrix* m1, dInt16 m2);
template Matrix* mSub<dInt32>(Matrix* m1, dInt32 m2);
template Matrix* mSub<dInt64>(Matrix* m1, dInt64 m2);
template Matrix* mSub<dReal32>(Matrix* m1, dReal32 m2);
template Matrix* mSub<dReal64>(Matrix* m1, dReal64 m2);
template Matrix* mSub<dReal64T>(Matrix* m1, dReal64T m2);

// Multiplication
template <typename T>
Matrix* mMul(Matrix* m1, T m2)
{
    return nullptr;  // Implement your logic here
}

template Matrix* mMul<dInt8>(Matrix* m1, dInt8 m2);
template Matrix* mMul<dInt16>(Matrix* m1, dInt16 m2);
template Matrix* mMul<dInt32>(Matrix* m1, dInt32 m2);
template Matrix* mMul<dInt64>(Matrix* m1, dInt64 m2);
template Matrix* mMul<dReal32>(Matrix* m1, dReal32 m2);
template Matrix* mMul<dReal64>(Matrix* m1, dReal64 m2);
template Matrix* mMul<dReal64T>(Matrix* m1, dReal64T m2);

// Division
template <typename T>
Matrix* mDiv(Matrix* m1, T m2)
{
    return nullptr;  // Implement your logic here
}

template Matrix* mDiv<dInt8>(Matrix* m1, dInt8 m2);
template Matrix* mDiv<dInt16>(Matrix* m1, dInt16 m2);
template Matrix* mDiv<dInt32>(Matrix* m1, dInt32 m2);
template Matrix* mDiv<dInt64>(Matrix* m1, dInt64 m2);
template Matrix* mDiv<dReal32>(Matrix* m1, dReal32 m2);
template Matrix* mDiv<dReal64>(Matrix* m1, dReal64 m2);
template Matrix* mDiv<dReal64T>(Matrix* m1, dReal64T m2);

