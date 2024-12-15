#pragma once

class FadeManager
{
private:
	float m_alpha;
	bool m_isFadeIN;
	bool m_isFadeOUT;

public:
	FadeManager();
	~FadeManager();


	void FadeIN();
	void FadeOUT();
	void Update(float deltaTime);

	float GetAlpha() const;
	bool IsFading() const;
};