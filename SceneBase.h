#pragma once

#include "Main.h"

#include "RenderManager.h"
#include "Camera.h"
#include "Player.h"

enum class SceneType
{
    Title,
    Game,
    Result,
};

class SceneBase
{
private:

public:

    // コンストラクタ
    SceneBase();
    virtual ~SceneBase() = default;

    // シーンを更新する
    virtual void Update() = 0;

    // シーンを描画する
    virtual void Draw() = 0;

};