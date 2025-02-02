#pragma once

class FadeManager
{
private:
	static FadeManager* m_Instance;

	float m_alpha;
	bool m_isFadeIN;
	bool m_isFadeOUT;

public:
	static FadeManager* GetInstance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new FadeManager();
		}
		return m_Instance;
	}

	FadeManager();
	~FadeManager();


	void FadeIN();
	void FadeOUT();
	void Update();

	float GetAlpha() const;
	bool IsFading() const;
};