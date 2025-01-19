#pragma once

#include "EnemyBase.h"
#include "EnemySmall.h"
#include "EnemySmall2.h"

class EnemyManager
{
private:
    std::vector<EnemyBase*> enemies;

    Player* m_Player;

    float m_Time = 0.0f;

    int m_EnemyCount = 0;

    bool m_AddEnemy = true;
    bool m_EnemyWave1 = true;
    bool m_EnemyWave2 = false;
    bool m_EnemyWave3 = false;

public:
    EnemyManager();

    void Update();
    void Draw();

    void AddEnemySmall();
    void AddEnemySmall2();

    void SetPlayer(Player* player);

};