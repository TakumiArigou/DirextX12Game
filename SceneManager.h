#pragma once

#include "GameManager.h"

// シーンの種類を定義する enum class
enum class SceneType
{
    Title,      // タイトル画面
    Game,       // ゲーム画面
    GameOver,   // ゲームオーバー画面
    Option      // オプション画面
};

// SceneManager クラスの定義
class SceneManager
{
public:
    // コンストラクタ
    SceneManager();

    // シーンを更新する
    void Update();

    // シーンを描画する
    void Draw();

    // シーン遷移を開始する
    void TransitionTo(SceneType scene);

    // 現在のシーンを取得
    SceneType GetCurrentScene() const;

    // シーン名を文字列で返す（デバッグ用）
    const char* GetSceneName(SceneType scene) const;

private:

    GameManager m_GameManager;

    SceneType currentScene;   // 現在のシーン
    SceneType nextScene;      // 次に遷移するシーン
    bool isTransitioning;     // 遷移中かどうか
};