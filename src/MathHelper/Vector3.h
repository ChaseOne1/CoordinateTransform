#pragma once

struct Vector3
{
    float x, y, z;

    Vector3() { x = y = z = 0.0f; };
    Vector3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

    static float DotProduct(const Vector3 &left, const Vector3 &right);
    static Vector3 CrossProduct(const Vector3 &left, const Vector3 &right);

    float Length() const;
    void Normalise();

    Vector3 operator-() const;
    Vector3 operator-(const Vector3 &vec) const;
    Vector3 operator*(const float multiplier) const;
    Vector3 &operator*=(const float multiplier);
};