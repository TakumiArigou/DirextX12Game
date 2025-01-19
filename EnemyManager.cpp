
#include "Main.h"
#include "EnemyManager.h"


EnemyManager::EnemyManager()
{

}

void EnemyManager::Update()
{
    if (m_AddEnemy)
    {
        AddEnemySmall();
        AddEnemySmall2();

        AddEnemySmall();
        AddEnemySmall2();

        m_AddEnemy = false;
    }

    m_Time += 1.0f / 60.0f;

    if (m_Time >= 0.0f)
    {


                   m_EnemyCount += 1;
                   m_Time = 0.0f;

                   //if (m_EnemyCount >= 5)
                   //{
                   //    m_EnemyWave1 = false;
                   //    m_EnemyWave2 = true;
                   //}
    }

    if (m_EnemyWave1 && !m_EnemyWave2 && !m_EnemyWave3)
    {


        m_EnemyWave1 = false;
    }
    else if (!m_EnemyWave1 && m_EnemyWave2 && !m_EnemyWave3)
    {
 /*       if (m_Time >= 5.0f)
        {
            AddEnemy(std::make_shared<Enemy>());

            m_EnemyCount += 1;
            m_Time = 0.0f;

            if (m_EnemyCount >= 5)
            {
                m_EnemyWave2 = false;
                m_EnemyWave3 = true;
            }
        }*/
    }
    else if (!m_EnemyWave1 && !m_EnemyWave2 && m_EnemyWave3)
    {
        //if (m_Time >= 5.0f)
        //{
        //    AddEnemy(std::make_shared<Enemy>());

        //    m_EnemyCount += 1;
        //    m_Time = 0.0f;

        //    if (m_EnemyCount >= 5)
        //    {
        //        m_EnemyWave3 = false;
        //        m_EnemyWave1 = true;
        //    }
        //}
    }


    for (auto enemy : enemies) {
        enemy->Update();
    }

    //非アクティブな敵を削除
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](EnemyBase* enemy)
        {
            return enemy->IsDead();
        }), enemies.end());
}

void EnemyManager::Draw()
{
    for (auto enemy : enemies) {
        enemy->Draw();
    }
}

void EnemyManager::AddEnemySmall()
{
    XMFLOAT3 pos = XMFLOAT3(10.0f, 10.0f, 15.0f);
    EnemySmall* enemy = new EnemySmall(pos, m_Player);
    enemies.push_back(enemy);
}

void EnemyManager::AddEnemySmall2()
{
    XMFLOAT3 pos = XMFLOAT3(-10.0f, -10.0f, 15.0f);
    EnemySmall2* enemy = new EnemySmall2(pos, m_Player);
    enemies.push_back(enemy);
}

void EnemyManager::SetPlayer(Player* player)
{
    m_Player = player;
}