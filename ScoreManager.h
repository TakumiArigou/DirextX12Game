#pragma once

class ScoreManager
{
private:

	static ScoreManager* m_Instance;

	int m_HighScore;       // �ō��X�R�A
	bool m_IsGameOver;     // �Q�[���I�[�o�[�t���O

public:

    int m_Score;           // ���݂̃X�R�A

	static ScoreManager* GetInstance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new ScoreManager();
		}
		return m_Instance;
	}

	ScoreManager();
	~ScoreManager();
    // �X�R�A�����Z
    void AddScore(int value) {
        if (!m_IsGameOver) {
            m_Score += value;
            if (m_Score > m_HighScore) {
                m_HighScore = m_Score;  // �ō��X�R�A���X�V
            }
        }
    }

    // �X�R�A�����Z
    void SubtractScore(int value);

    // ���݂̃X�R�A���擾
    int GetScore() const;

    // �X�R�A�����Z�b�g
    void ResetScore() {
        m_Score = 0;
    }

    // �Q�[���I�[�o�[���̏���
    void GameOver();

    // �ō��X�R�A��ۑ�
    void SaveHighScore();

    // �ō��X�R�A��ǂݍ���
    void LoadHighScore();

    // �ō��X�R�A���擾
    int GetHighScore() const;

    // �Q�[���I�[�o�[���ǂ������`�F�b�N
    bool IsGameOver() const;

    // ���݂̃X�R�A�ƍō��X�R�A��\��
    void DisplayScore() const;
};