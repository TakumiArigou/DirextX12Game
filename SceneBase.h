#pragma once

#include "Main.h"

#include "RenderManager.h"
#include "Camera.h"
#include "Player.h"

class SceneBase
{
private:

public:

    // �R���X�g���N�^
    SceneBase();
    virtual ~SceneBase() = default;

    // �V�[�����X�V����
    virtual void Update() = 0;

    // �V�[����`�悷��
    virtual void Draw() = 0;

};