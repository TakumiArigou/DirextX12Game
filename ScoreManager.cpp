
#include "Main.h"
#include "ScoreManager.h"

ScoreManager* ScoreManager::m_Instance = nullptr;


ScoreManager::ScoreManager()
{
    m_Instance = this;

    m_Score = 0;
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::SubtractScore(int value)
{
    if (!m_IsGameOver) {
        m_Score -= value;
        if (m_Score < 0) m_Score = 0;  // �X�R�A�����ɂȂ�Ȃ��悤�ɂ���
    }
}

int ScoreManager::GetScore() const
{
    return m_Score;
}

void ScoreManager::GameOver()
{
    m_IsGameOver = true;
    SaveHighScore();  // �Q�[���I�[�o�[���ɃX�R�A��ۑ�
}

void ScoreManager::SaveHighScore()
{
    std::ofstream outFile("highscore.txt");
    if (outFile.is_open()) {
        outFile << m_HighScore;  // �ō��X�R�A����������
        outFile.close();
    }
}

void ScoreManager::LoadHighScore()
{
    std::ifstream inFile("highscore.txt");
    if (inFile.is_open()) {
        inFile >> m_HighScore;  // �t�@�C������ō��X�R�A��ǂݍ���
        inFile.close();
    }
}

int ScoreManager::GetHighScore() const
{
    return m_HighScore;
}

bool ScoreManager::IsGameOver() const
{
    return m_IsGameOver;
}

void ScoreManager::DisplayScore() const
{
    std::cout << "Score: " << m_Score << std::endl;
    std::cout << "High Score: " << m_HighScore << std::endl;
}