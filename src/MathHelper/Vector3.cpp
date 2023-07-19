#include "Vector3.h"
#include <cmath>

float Vector3::DotProduct(const Vector3 &left, const Vector3 &right)
{
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

Vector3 Vector3::CrossProduct(const Vector3 &left, const Vector3 &right)
{
    float x = left.y * right.z - left.z * right.y;
    float y = left.z * right.x - left.x * right.z;
    float z = left.x * right.y - left.y * right.x;

    return Vector3(x, y, z);
}

float Vector3::Length() const
{
    return sqrt(x * x + y * y + z * z);
}

void Vector3::Normalise()
{
    float len = this->Length();
    if (fabs(len) < 1e-7)
        return;
    this->x /= len;
    this->y /= len;
    this->z /= len;
}

Vector3 Vector3::operator-() const
{
    return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator-(const Vector3 &vec) const
{
    return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

Vector3 Vector3::operator*(const float multiplier) const
{
    return Vector3(x * multiplier, y * multiplier, z * multiplier);
}

Vector3 &Vector3::operator*=(const float multiplier)
{
    x *= multiplier;
    y *= multiplier;
    z *= multiplier;
    return *this;
}
