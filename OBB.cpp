
#include "Main.h"
#include "OBB.h"

OBB::OBB(const XMFLOAT3& position, const XMFLOAT3& dirX, const XMFLOAT3& dirY, const XMFLOAT3& dirZ, float lenX, float lenY, float lenZ)
{
    m_Pos = position;
    m_NormaDirect[0] = dirX;
    m_NormaDirect[1] = dirY;
    m_NormaDirect[2] = dirZ;
    m_fLength[0] = lenX;
    m_fLength[1] = lenY;
    m_fLength[2] = lenZ;
}

XMFLOAT3 OBB::GetDirect(int elem)
{
    if (elem >= 0 && elem < 3)
        return m_NormaDirect[elem];
    return XMFLOAT3(0.0f, 0.0f, 0.0f); // 無効なインデックスの場合
}

float OBB::GetLen_W(int elem)
{
    if (elem >= 0 && elem < 3)
        return m_fLength[elem];
    return 0.0f; // 無効なインデックスの場合
}

XMFLOAT3 OBB::GetPos_W()
{
    return m_Pos;
}

XMVECTOR OBB::GetDirectXM(int elem)
{
    if (elem >= 0 && elem < 3)
        return XMLoadFloat3(&m_NormaDirect[elem]);
    return XMVectorZero(); // 無効なインデックスの場合
}