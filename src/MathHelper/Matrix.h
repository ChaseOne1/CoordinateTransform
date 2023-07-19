#pragma once
#include "Vector3.h"
#include "Vector4.h"

class Matrix
{
public:
    union
    {
        struct
        {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;
        };
        float m[4][4];
    };

    Matrix()
    {
        this->SetUnity();
    }
    Matrix(const Vector3 &right, const Vector3 &up, const Vector3 &at, const Vector3 &pos);
    ~Matrix() {}

#ifdef _DEBUG
    void PrintData();
#endif
    Matrix &SetUnity();
    Matrix &Transpose();

    Vector3 GetRight3()
    {
        return Vector3(_11, _12, _13);
    }
    Vector4 GetRight4() { return Vector4(_11, _12, _13, _14); }

    Vector3 GetUp3()
    {
        return Vector3(_21, _22, _23);
    }
    Vector4 GetUp4() { return Vector4(_21, _22, _23, _24); }

    Vector3 GetAt3()
    {
        return Vector3(_31, _32, _33);
    }
    Vector4 GetAt4() { return Vector4(_31, _32, _33, _34); }

    Vector3 GetPosition3()
    {
        return Vector3(_41, _42, _43);
    }
    Vector4 GetPosition4() { return Vector4(_41, _42, _43, _44); }
};
