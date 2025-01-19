#pragma once

class EnemyBase
{
public:

    // コンストラクタ
    EnemyBase();
    ~EnemyBase() = default;

    // シーンを更新する
    virtual void Update() = 0;

    // シーンを描画する
    virtual void Draw() = 0;

    virtual bool IsActive() = 0;
    virtual bool IsDead()= 0;
};