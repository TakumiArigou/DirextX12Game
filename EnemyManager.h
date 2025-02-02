#pragma once

#include "EnemyBase.h"
#include "EnemySmall.h"
#include "EnemySmall2.h"

class EnemyManager
{
private:
    std::vector<EnemyBase*> enemies;

    Player*         m_Player;

    float m_Time = 0.0f;

    int m_EnemyCount = 0;

    bool m_AddEnemy = true;
    bool m_EnemyWave1 = true;
    bool m_EnemyWave2 = false;
    bool m_EnemyWave3 = false;

    std::array<EnemySmall, 5> m_Small;
    //std::array<EnemySmall2, 5> m_Small2;

public:
    EnemyManager();

    void Update();
    void Draw();

    void AddEnemySmall();
    void AddEnemySmall2();

    bool CreateEnemySmall();
    bool CreateEnemySmall2();

    void SetPlayer(Player* player);

};