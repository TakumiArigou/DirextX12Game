
#include "GameManager.h"
#include "OBBManager.h"

// OBB v.s. OBB
bool OBBManager::ColOBBs(OBB& obb1, OBB& obb2)
{
    // �e�����x�N�g���̊m��
    // �iNAe1: �W���������x�N�g���AAe1: OBB�̒������|�����x�N�g���j
    XMVECTOR NAe1 = XMLoadFloat3(&obb1.GetDirect(0));
    XMVECTOR Ae1 = XMVectorScale(NAe1, obb1.GetLen_W(0));

    XMVECTOR NAe2 = XMLoadFloat3(&obb1.GetDirect(1));
    XMVECTOR Ae2 = XMVectorScale(NAe2, obb1.GetLen_W(1));

    XMVECTOR NAe3 = XMLoadFloat3(&obb1.GetDirect(2));
    XMVECTOR Ae3 = XMVectorScale(NAe3, obb1.GetLen_W(2));

    XMVECTOR NBe1 = XMLoadFloat3(&obb2.GetDirect(0));
    XMVECTOR Be1 = XMVectorScale(NBe1, obb2.GetLen_W(0));

    XMVECTOR NBe2 = XMLoadFloat3(&obb2.GetDirect(1));
    XMVECTOR Be2 = XMVectorScale(NBe2, obb2.GetLen_W(1));

    XMVECTOR NBe3 = XMLoadFloat3(&obb2.GetDirect(2));
    XMVECTOR Be3 = XMVectorScale(NBe3, obb2.GetLen_W(2));

    XMVECTOR Interval = XMLoadFloat3(&obb1.GetPos_W()) - XMLoadFloat3(&obb2.GetPos_W());

    // ������ : Ae1
    float rA = XMVectorGetX(XMVector3Length(Ae1));
    float rB = LenSegOnSeparateAxis(&NAe1, &Be1, &Be2, &Be3);
    float L = fabs(XMVectorGetX(XMVector3Dot(Interval, NAe1)));
    if (L > rA + rB)
        return false; // �Փ˂��Ă��Ȃ�

    // ������ : Ae2
    rA = XMVectorGetX(XMVector3Length(Ae2));
    rB = LenSegOnSeparateAxis(&NAe2, &Be1, &Be2, &Be3);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, NAe2)));
    if (L > rA + rB)
        return false;

    // ������ : Ae3
    rA = XMVectorGetX(XMVector3Length(Ae3));
    rB = LenSegOnSeparateAxis(&NAe3, &Be1, &Be2, &Be3);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, NAe3)));
    if (L > rA + rB)
        return false;

    // ������ : Be1
    rA = LenSegOnSeparateAxis(&NBe1, &Ae1, &Ae2, &Ae3);
    rB = XMVectorGetX(XMVector3Length(Be1));
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, NBe1)));
    if (L > rA + rB)
        return false;

    // ������ : Be2
    rA = LenSegOnSeparateAxis(&NBe2, &Ae1, &Ae2, &Ae3);
    rB = XMVectorGetX(XMVector3Length(Be2));
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, NBe2)));
    if (L > rA + rB)
        return false;

    // ������ : Be3
    rA = LenSegOnSeparateAxis(&NBe3, &Ae1, &Ae2, &Ae3);
    rB = XMVectorGetX(XMVector3Length(Be3));
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, NBe3)));
    if (L > rA + rB)
        return false;

    // ������ : C11
    XMVECTOR Cross = XMVector3Cross(NAe1, NBe1);
    rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
    rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, Cross)));
    if (L > rA + rB)
        return false;

    // ������ : C12
    Cross = XMVector3Cross(NAe1, NBe2);
    rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
    rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, Cross)));
    if (L > rA + rB)
        return false;

    // ������ : C13
    Cross = XMVector3Cross(NAe1, NBe3);
    rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
    rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, Cross)));
    if (L > rA + rB)
        return false;

    // ������ : C21
    Cross = XMVector3Cross(NAe2, NBe1);
    rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
    rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, Cross)));
    if (L > rA + rB)
        return false;

    // ������ : C22
    Cross = XMVector3Cross(NAe2, NBe2);
    rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
    rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, Cross)));
    if (L > rA + rB)
        return false;

    // ������ : C23
    Cross = XMVector3Cross(NAe2, NBe3);
    rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
    rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, Cross)));
    if (L > rA + rB)
        return false;

    // ������ : C31
    Cross = XMVector3Cross(NAe3, NBe1);
    rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
    rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, Cross)));
    if (L > rA + rB)
        return false;

    // ������ : C32
    Cross = XMVector3Cross(NAe3, NBe2);
    rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
    rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, Cross)));
    if (L > rA + rB)
        return false;

    // ������ : C33
    Cross = XMVector3Cross(NAe3, NBe3);
    rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
    rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
    L = fabs(XMVectorGetX(XMVector3Dot(Interval, Cross)));
    if (L > rA + rB)
        return false;

    // �������ʂ����݂��Ȃ��̂Łu�Փ˂��Ă���v
    return true;
}

// �������ɓ��e���ꂽ���������瓊�e���������Z�o
float OBBManager::LenSegOnSeparateAxis(XMVECTOR* Sep, XMVECTOR* e1, XMVECTOR* e2, XMVECTOR* e3)
{
    // 3�̓��ς̐�Βl�̘a�œ��e���������v�Z
    float r1 = fabs(XMVectorGetX(XMVector3Dot(*Sep, *e1)));
    float r2 = fabs(XMVectorGetX(XMVector3Dot(*Sep, *e2)));
    float r3 = e3 ? fabs(XMVectorGetX(XMVector3Dot(*Sep, *e3))) : 0;
    return r1 + r2 + r3;
}
