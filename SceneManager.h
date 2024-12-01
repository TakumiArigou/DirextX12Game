#pragma once

#include "GameManager.h"

// �V�[���̎�ނ��`���� enum class
enum class SceneType
{
    Title,      // �^�C�g�����
    Game,       // �Q�[�����
    GameOver,   // �Q�[���I�[�o�[���
    Option      // �I�v�V�������
};

// SceneManager �N���X�̒�`
class SceneManager
{
public:
    // �R���X�g���N�^
    SceneManager();

    // �V�[�����X�V����
    void Update();

    // �V�[����`�悷��
    void Draw();

    // �V�[���J�ڂ��J�n����
    void TransitionTo(SceneType scene);

    // ���݂̃V�[�����擾
    SceneType GetCurrentScene() const;

    // �V�[�����𕶎���ŕԂ��i�f�o�b�O�p�j
    const char* GetSceneName(SceneType scene) const;

private:

    GameManager m_GameManager;

    SceneType currentScene;   // ���݂̃V�[��
    SceneType nextScene;      // ���ɑJ�ڂ���V�[��
    bool isTransitioning;     // �J�ڒ����ǂ���
};