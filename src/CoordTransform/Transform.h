#pragma once

struct Vector3;
class Matrix;

class Transform
{
    static Matrix *m_mpCamMatrix;
    static Matrix *m_mpViewMatrix;

    void ClacViewMatrix();

public:
    Transform() {}
    ~Transform();
    void SetCameraMatrix(Matrix *const camMatrix);
    void SetCameraMatrix(const Vector3 &camPosn, const Vector3 &targetPosn, const Vector3 &upVec);
    Vector3 WorldToCam(const Vector3 &source) const;
    Vector3 CamToWorld(const Vector3 &source) const;
};