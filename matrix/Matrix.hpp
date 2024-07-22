#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <vector>

class Matrix
{
private:

public:
    Matrix(void);
    Matrix(const Matrix &toCopy);
    Matrix	&operator = (const Matrix &toCopy);
    ~Matrix(void);
};

#endif
