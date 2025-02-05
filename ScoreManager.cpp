
#include "Main.h"
#include "ScoreManager.h"

ScoreManager* ScoreManager::m_Instance = nullptr;


ScoreManager::ScoreManager()
{
    m_Instance = this;

    m_ClearScore = 10000;
    m_EnemyCount = 0;
    m_Score = 0;
}


ScoreManager::~ScoreManager()
{
}


void ScoreManager::Update()
{
}


void ScoreManager::AddScore(int addscore)
{
    m_ClearScore += addscore;
}

void ScoreManager::AddEnemyCount(int addenemycount)
{
    m_EnemyCount += addenemycount;
}

const std::array<float, 4>& ScoreManager::GetClearTime() const
{
    return m_ClearTime;
}

void ScoreManager::SetClearTime(std::array<float, 4> cleartime)
{
    m_ClearTime = cleartime;
}

int ScoreManager::GetClearScore() const
{
    return m_ClearScore;
}

void ScoreManager::SetClearScore(int clearscore)
{
    m_ClearScore = clearscore;
}

int ScoreManager::GetEnemyCount() const
{
    return m_EnemyCount;
}

void ScoreManager::SetEnemyCount(int enemycount)
{
    m_EnemyCount = enemycount;
}
