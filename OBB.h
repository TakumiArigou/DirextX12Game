#pragma once


class OBB
{
protected:
    XMFLOAT3 m_Pos;                  // �ʒu
    XMFLOAT3 m_NormaDirect[3];       // �����x�N�g���i3�̎��j
    float m_fLength[3];              // �e�������̒���

public:
    // �R���X�g���N�^
    OBB(const XMFLOAT3& position, const XMFLOAT3& dirX, const XMFLOAT3& dirY, const XMFLOAT3& dirZ, float lenX, float lenY, float lenZ);

    // �w�莲�ԍ��̕����x�N�g�����擾
    XMFLOAT3 GetDirect(int elem);

    // �w�莲�����̒������擾
    float GetLen_W(int elem);

    // �ʒu���擾
    XMFLOAT3 GetPos_W();

    // �x�N�g�����擾���邽�߂�DirectXMath�`����XMVECTOR�ł̊֐�
    XMVECTOR GetDirectXM(int elem);
};