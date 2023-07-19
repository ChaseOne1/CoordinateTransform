#include <iostream>
#include "Matrix.h"
#include "Vector4.h"

Matrix::Matrix(const Vector3 &right, const Vector3 &up, const Vector3 &at, const Vector3 &pos)
{
    memcpy(this, &Vector4(right, 0), sizeof(Vector4));
    memcpy((Vector4 *)this + 1, &Vector4(up, 0), sizeof(Vector4));
    memcpy((Vector4 *)this + 2, &Vector4(at, 0), sizeof(Vector4));
    memcpy((Vector4 *)this + 3, &Vector4(pos, 1), sizeof(Vector4));
}
#ifdef _DEBUG
void Matrix::PrintData()
{
    for (int i = 0, k = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j, ++k)
            std::cout << this->m[i][j] << " ";
        std::cout << std::endl;
    }
}
#endif

Matrix &Matrix::SetUnity()
{
    memset(this, 0, sizeof(Matrix));
    this->_11 = this->_22 = this->_33 = this->_44 = 1;
    return *this;
}

Matrix &Matrix::Transpose()
{
    for (int i = 0; i < 4; ++i)
        for (int j = i; j < 4; ++j)
            std::swap(this->m[i][j], this->m[j][i]);
    return *this;
}