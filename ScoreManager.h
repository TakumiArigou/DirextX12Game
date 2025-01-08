#pragma once

class ScoreManager
{
private:

	static ScoreManager* m_Instance;

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
    // スコアを加算
    void AddScore(int value) {
        if (!m_IsGameOver) {
            m_Score += value;
            if (m_Score > m_HighScore) {
                m_HighScore = m_Score;  // 最高スコアを更新
            }
        }
    }

    // スコアを減算
    void SubtractScore(int value);

    // 現在のスコアを取得
    int GetScore() const;

    // スコアをリセット
    void ResetScore() {
        m_Score = 0;
    }

    // ゲームオーバー時の処理
    void GameOver();

    // 最高スコアを保存
    void SaveHighScore();

    // 最高スコアを読み込む
    void LoadHighScore();

    // 最高スコアを取得
    int GetHighScore() const;

    // ゲームオーバーかどうかをチェック
    bool IsGameOver() const;

    // 現在のスコアと最高スコアを表示
    void DisplayScore() const;
};