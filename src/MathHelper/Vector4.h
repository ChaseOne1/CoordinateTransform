#pragma once
#include "Vector3.h"

struct Vector4
{
    float x, y, z, w;
    Vector4() { x = y = z = w = 0.0f; }
    Vector4(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) {}
    Vector4(const Vector3 &vec, float W = 0.0f) : x(vec.x), y(vec.y), z(vec.z), w(W) {}

    Vector4 operator-() const;
    Vector4 operator*(const float multiplier) const;
    Vector4 &operator*=(const float multiplier);
    Vector4 operator*(const class Matrix &matrix) const;
    Vector4 &operator*=(const class Matrix &matrix);
};