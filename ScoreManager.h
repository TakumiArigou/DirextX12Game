#pragma once

class ScoreManager
{
private:

	static ScoreManager* m_Instance;

    int     m_ClearScore;
	int		m_EnemyCount;
	std::array<float, 4> m_ClearTime;

	int m_HighScore;       // 最高スコア
	bool m_IsGameOver;     // ゲームオーバーフラグ

public:

    int m_Score;           // 現在のスコア

	static ScoreManager* GetInstance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new ScoreManager();
		}
		return m_Instance;
	}

	ScoreManager();
	~ScoreManager();

	void Update();

	void AddScore(int addscore);
	void AddEnemyCount(int addenemycount);

	const std::array<float, 4>& GetClearTime() const;
	void SetClearTime(std::array<float, 4> cleartime);

	int GetClearScore() const;
	void SetClearScore(int clearscore);

	int GetEnemyCount() const;
	void SetEnemyCount(int enemycount);
};