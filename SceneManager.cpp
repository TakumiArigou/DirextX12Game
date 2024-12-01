#include "Main.h"
#include "SceneManager.h"


// コンストラクタ
SceneManager::SceneManager()
    : currentScene(SceneType::Game), nextScene(SceneType::Game), isTransitioning(false)
{
}

// シーンを更新する
void SceneManager::Update()
{
    GetCurrentScene();

    // シーン遷移中の場合
    if (isTransitioning)
    {
        // フェードイン/フェードアウトの処理
        std::cout << "フェード処理中..." << std::endl;

        // フェード処理が終了したら遷移を実行
        isTransitioning = false;
        currentScene = nextScene;
        std::cout << "シーン遷移: " << GetSceneName(currentScene) << std::endl;
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
        std::cout << "不明なシーンです。" << std::endl;
        break;
    }
}

//シーンを描画する
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
        std::cout << "不明なシーンです。" << std::endl;
        break;
    }
}

// シーン遷移を開始する
void SceneManager::TransitionTo(SceneType scene)
{
    if (currentScene != scene)
    {
        nextScene = scene;
        isTransitioning = true;  // フェードを開始
        std::cout << "遷移開始: " << GetSceneName(scene) << std::endl;
    }
}

// 現在のシーンを取得
SceneType SceneManager::GetCurrentScene() const
{
    return currentScene;
}

// シーン名を文字列で返す（デバッグ用）
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