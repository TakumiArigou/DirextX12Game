
#include "Main.h"
#include "EnemyManager.h"
#include "ScoreManager.h"

EnemyManager::EnemyManager()
{
}

void EnemyManager::Update()
{
    ScoreManager* scoreManager = ScoreManager::GetInstance();

    if (m_AddEnemy)
    {
        AddEnemySmall();
        AddEnemySmall2();
        AddEnemyBoss();

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

    if (CreateEnemySmall2())
    {
        m_Time2 += 1.0f / 60.0f;

        if (m_Time2 >= 3.0f)
        {
            for (auto& smallEnmey2 : m_Small2)
            {
                smallEnmey2.SetIsActive(true);
            }

            m_Time2 = 0.0F;
        }
    }

    for (auto& smallEnmey : m_Small)
    {
        smallEnmey.Update();
    }

    for (auto& smallEnmey2 : m_Small2)
    {
        smallEnmey2.Update();
    }

    for (auto& boss : m_Boss)
    {
        boss.Update();
    }
}

void EnemyManager::Draw()
{
    for (auto& smallEnmey : m_Small)
    {
        smallEnmey.Draw();
    }

    for (auto& smallEnmey2 : m_Small2)
    {
        smallEnmey2.Draw();
    }

    for (auto& boss : m_Boss)
    {
        boss.Draw();
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
    XMFLOAT3 pos = XMFLOAT3(-15.0f, -15.0f, 15.0f);
    float count = 0;

    for (auto& smallEnemy2 : m_Small2)
    {
        smallEnemy2.SetPlayer(m_Player);
        smallEnemy2.SetEnemySmallPosition(pos);
        smallEnemy2.SetAddCount(count);

        count += 0.5f;
    }
}

void EnemyManager::AddEnemyBoss()
{
    XMFLOAT3 pos = XMFLOAT3(-17.0f, 17.0f, 19.0f);
    float count = 0;

    for (auto& boss : m_Boss)
    {
        boss.SetPlayer(m_Player);
        boss.SetEnemySmallPosition(pos);
        boss.SetAddCount(count);

        count += 0.5f;
    }
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
    XMFLOAT3 pos = XMFLOAT3(-15.0f, -15.0f, 15.0f);
    float count = 0;

    for (auto& smallEnemy2 : m_Small2)
    {
        bool isActiveEnemy;
        isActiveEnemy = smallEnemy2.IsActive();

        if (isActiveEnemy)
        {
            return false;
        }
        else if (!isActiveEnemy)
        {
            smallEnemy2.SetEnemySmallPosition(pos);
            smallEnemy2.SetAddCount(count);
        }

        count += 0.5f;
    }

    return true;
}

bool EnemyManager::CreateEnemyBoss()
{
    for (auto& boss : m_Boss)
    {
        bool isActiveEnemy;
        isActiveEnemy = boss.IsActive();

        if (isActiveEnemy)
        {
            return false;
        }
        else if (!isActiveEnemy)
        {
            return true;
        }
    }
}

bool EnemyManager::GetBoss()
{
    return CreateEnemyBoss();
}

void EnemyManager::SetPlayer(Player* player)
{
    m_Player = player;
}
