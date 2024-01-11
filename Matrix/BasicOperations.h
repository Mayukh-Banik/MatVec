#pragma once

#include "Matrix.h"

template <typename T>
Matrix* mAdd(Matrix* m1, T m2);

template <typename T>
Matrix* mSub(Matrix* m1, T m2);

template <typename T>
Matrix* mMul(Matrix* m1, T m2);

template <typename T>
Matrix* mDiv(Matrix* m1, T m2);