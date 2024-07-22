#include "Matrix.hpp"

Matrix::Matrix(void)
{
}

Matrix    &Matrix::operator = (const Matrix &toCopy)
{
    if (this == &toCopy)
        return (*this);
    return (*this);
}

Matrix::Matrix(const Matrix &toCopy)
{
    (*this) = toCopy;
}

Matrix::~Matrix(void)
{
}
