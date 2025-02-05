#pragma once

#include "EnemyBase.h"
#include "EnemySmall.h"
#include "EnemySmall2.h"
#include "EnemyBoss.h"

class EnemyManager
{
private:
    std::vector<EnemyBase*> enemies;

    Player*         m_Player;

    float m_Time = 0.0f;
    float m_Time2 = 0.0f;

    bool m_AddEnemy = true;
    bool m_EnemyWave1 = true;
    bool m_EnemyWave2 = false;
    bool m_EnemyWave3 = false;

    std::array<EnemySmall, 5> m_Small;
    std::array<EnemySmall2, 5> m_Small2;
    std::array<EnemyBoss, 1> m_Boss;

public:
    EnemyManager();

    void Update();
    void Draw();

    void AddEnemySmall();
    void AddEnemySmall2();
    void AddEnemyBoss();

    bool CreateEnemySmall();
    bool CreateEnemySmall2();
    bool CreateEnemyBoss();
    bool GetBoss();

    void SetPlayer(Player* player);
};