#pragma once

class EnemyBase
{
public:

    // �R���X�g���N�^
    EnemyBase();
    ~EnemyBase() = default;

    // �V�[�����X�V����
    virtual void Update() = 0;

    // �V�[����`�悷��
    virtual void Draw() = 0;

    virtual bool IsActive() = 0;
    virtual bool IsDead()= 0;
};