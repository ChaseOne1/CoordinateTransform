#include "Vector4.h"
#include "Matrix.h"

Vector4 Vector4::operator-() const
{
    return Vector4(-x, -y, -z, -w);
}

Vector4 Vector4::operator*(const float multiplier) const
{
    return Vector4(Vector3(x, y, z) * multiplier, w * multiplier);
}

Vector4 &Vector4::operator*=(const float multiplier)
{
    this->x *= multiplier;
    this->y *= multiplier;
    this->z *= multiplier;
    this->w *= multiplier;
    return *this;
}

Vector4 Vector4::operator*(const Matrix &matrix) const
{
    float x = this->x * matrix._11 + this->y * matrix._21 + this->z * matrix._31 + this->w * matrix._41;
    float y = this->x * matrix._12 + this->y * matrix._22 + this->z * matrix._32 + this->w * matrix._42;
    float z = this->x * matrix._13 + this->y * matrix._23 + this->z * matrix._33 + this->w * matrix._43;
    float w = this->x * matrix._14 + this->y * matrix._24 + this->z * matrix._34 + this->w * matrix._44;
    return Vector4(x, y, z, w);
}

Vector4 &Vector4::operator*=(const Matrix &matrix)
{
    Vector4 src(*this);
    this->x = src.x * matrix._11 + src.y * matrix._21 + src.z * matrix._31 + src.w * matrix._41;
    this->y = src.x * matrix._12 + src.y * matrix._22 + src.z * matrix._32 + src.w * matrix._42;
    this->z = src.x * matrix._13 + src.y * matrix._23 + src.z * matrix._33 + src.w * matrix._43;
    this->w = src.x * matrix._14 + src.y * matrix._24 + src.z * matrix._34 + src.w * matrix._44;
    return *this;
}
