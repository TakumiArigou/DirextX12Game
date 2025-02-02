
#include "Main.h"
#include "EnemyManager.h"


EnemyManager::EnemyManager()
{
    //XMFLOAT3 pos = XMFLOAT3(10.0f, 10.0f, 15.0f);
    //for (auto& smallEnemy : m_Small)
    //{
    //    smallEnemy = EnemySmall(pos, m_Player);
    //}
}

void EnemyManager::Update()
{
    if (m_AddEnemy)
    {
        AddEnemySmall();
        //AddEnemySmall2();

        //AddEnemySmall();
        //AddEnemySmall2();

        m_AddEnemy = false;
    }

    if (CreateEnemySmall())
    {
        m_Time += 1.0f / 60.0f;
        
        if (m_Time >= 2.0f)
        {
            for (auto& smallEnmey : m_Small)
            {
                smallEnmey.SetIsActive(true);
            }

            m_Time = 0.0F;
        }
    }

    if (m_Time >= 0.0f)
    {


                   m_EnemyCount += 1;
    /*               m_Time = 0.0f;*/

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

    for (auto& smallEnmey : m_Small)
    {
        smallEnmey.Update();
    }

    //for (auto enemy : enemies) {
    //    enemy->Update();
    //}

    ////非アクティブな敵を削除
    //enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](EnemyBase* enemy)
    //    {
    //        return enemy->IsDead();
    //    }), enemies.end());
}

void EnemyManager::Draw()
{
    //for (auto enemy : enemies) {
    //    enemy->Draw();
    //}

    for (auto& smallEnmey : m_Small)
    {
        smallEnmey.Draw();
    }
}

void EnemyManager::AddEnemySmall()
{
    XMFLOAT3 pos = XMFLOAT3(10.0f, 10.0f, 15.0f);
    float count = 0;

    for (auto& smallEnemy : m_Small)
    {
        smallEnemy.SetPlayer(m_Player);
        smallEnemy.SetEnemySmallPosition(pos);
        smallEnemy.SetAddCount(count);

        count += 0.5f;
    }
}

void EnemyManager::AddEnemySmall2()
{
    XMFLOAT3 pos = XMFLOAT3(-10.0f, -10.0f, 15.0f);
    EnemySmall2* enemy = new EnemySmall2(pos, m_Player);
    enemies.push_back(enemy);
}

bool EnemyManager::CreateEnemySmall()
{
    XMFLOAT3 pos = XMFLOAT3(10.0f, 10.0f, 15.0f);
    float count = 0;

    for (auto& smallEnemy : m_Small)
    {
        bool isActiveEnemy;
        isActiveEnemy = smallEnemy.IsActive();

        if (isActiveEnemy)
        {
            return false;
        }
        else if (!isActiveEnemy)
        {
            smallEnemy.SetEnemySmallPosition(pos);
            smallEnemy.SetAddCount(count);
        }

        count += 0.5f;
    }

    return true;
}

bool EnemyManager::CreateEnemySmall2()
{
    return false;
}

void EnemyManager::SetPlayer(Player* player)
{
    m_Player = player;
}