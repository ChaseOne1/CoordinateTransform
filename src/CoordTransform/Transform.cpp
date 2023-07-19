#include "Transform.h"
#include "..\MathHelper\Matrix.h"

Matrix *Transform::m_mpCamMatrix;
Matrix *Transform::m_mpViewMatrix;

void Transform::SetCameraMatrix(Matrix *const camMatrix)
{
    if (this->m_mpCamMatrix)
        delete this->m_mpCamMatrix;
    m_mpCamMatrix = camMatrix;
    ClacViewMatrix();
}

void Transform::SetCameraMatrix(const Vector3 &camPosn, const Vector3 &targetPosn, const Vector3 &upVec)
{
    if (this->m_mpCamMatrix)
        delete this->m_mpCamMatrix;
    Vector3 at = targetPosn - camPosn;
    at.Normalise();
    Vector3 right = Vector3::CrossProduct(upVec, at);
    right.Normalise();
    Vector3 up = Vector3::CrossProduct(at, right);
    up.Normalise();
    m_mpCamMatrix = new Matrix(right, up, at, camPosn);
    ClacViewMatrix();
}

void Transform::ClacViewMatrix()
{
    if (this->m_mpViewMatrix)
        delete this->m_mpViewMatrix;
    Matrix &t_camMat = (new Matrix(*m_mpCamMatrix))->Transpose();

    t_camMat._41 = Vector3::DotProduct(-m_mpCamMatrix->GetRight3(), m_mpCamMatrix->GetPosition3());
    t_camMat._42 = Vector3::DotProduct(-m_mpCamMatrix->GetUp3(), m_mpCamMatrix->GetPosition3());
    t_camMat._43 = Vector3::DotProduct(-m_mpCamMatrix->GetAt3(), m_mpCamMatrix->GetPosition3());

    t_camMat._14 = t_camMat._24 = t_camMat._34 = 0;
    t_camMat._44 = 1;
    this->m_mpViewMatrix = &t_camMat;
}

Transform::~Transform()
{
    if (this->m_mpCamMatrix)
        delete m_mpCamMatrix;
    if (this->m_mpViewMatrix)
        delete m_mpViewMatrix;
}

Vector3 Transform::WorldToCam(const Vector3 &source) const
{
    Vector4 res = Vector4(source, 1) * *m_mpViewMatrix;
    return Vector3(res.x, res.y, res.z);
}

Vector3 Transform::CamToWorld(const Vector3 &source) const
{
    Vector4 res = Vector4(source, 1) * *m_mpCamMatrix;
    return Vector3(res.x, res.y, res.z);
}
