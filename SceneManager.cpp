#include "Main.h"
#include "SceneManager.h"


// �R���X�g���N�^
SceneManager::SceneManager()
    : currentScene(SceneType::Game), nextScene(SceneType::Game), isTransitioning(false)
{
}

// �V�[�����X�V����
void SceneManager::Update()
{
    GetCurrentScene();

    // �V�[���J�ڒ��̏ꍇ
    if (isTransitioning)
    {
        // �t�F�[�h�C��/�t�F�[�h�A�E�g�̏���
        std::cout << "�t�F�[�h������..." << std::endl;

        // �t�F�[�h�������I��������J�ڂ����s
        isTransitioning = false;
        currentScene = nextScene;
        std::cout << "�V�[���J��: " << GetSceneName(currentScene) << std::endl;
    }

    switch (currentScene)
    {
    case SceneType::Title:

        break;
    case SceneType::Game:
        m_GameManager.Update();

        break;
    case SceneType::GameOver:

        break;
    case SceneType::Option:

        break;
    default:
        std::cout << "�s���ȃV�[���ł��B" << std::endl;
        break;
    }
}

//�V�[����`�悷��
void SceneManager::Draw()
{
    switch (currentScene)
    {
    case SceneType::Title:

        break;
    case SceneType::Game:
        m_GameManager.Draw();

        break;
    case SceneType::GameOver:

        break;
    case SceneType::Option:

        break;
    default:
        std::cout << "�s���ȃV�[���ł��B" << std::endl;
        break;
    }
}

// �V�[���J�ڂ��J�n����
void SceneManager::TransitionTo(SceneType scene)
{
    if (currentScene != scene)
    {
        nextScene = scene;
        isTransitioning = true;  // �t�F�[�h���J�n
        std::cout << "�J�ڊJ�n: " << GetSceneName(scene) << std::endl;
    }
}

// ���݂̃V�[�����擾
SceneType SceneManager::GetCurrentScene() const
{
    return currentScene;
}

// �V�[�����𕶎���ŕԂ��i�f�o�b�O�p�j
const char* SceneManager::GetSceneName(SceneType scene) const
{
    switch (scene)
    {
    case SceneType::Title: return "Title";
    case SceneType::Game: return "Game";
    case SceneType::GameOver: return "GameOver";
    case SceneType::Option: return "Option";
    default: return "Unknown";
    }


}