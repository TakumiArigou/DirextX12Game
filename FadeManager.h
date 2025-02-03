#pragma once

#include "SceneBase.h"

class FadeManager
{
private:
	static FadeManager* m_Instance;

	float m_Alpha;
	bool m_isFadeIN;
	bool m_isFadeOUT;

	bool m_isSceneChange;

	SceneType m_SceneType;

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
	void Draw();

	float GetAlpha() const;
	bool IsFadeOUT() const;
	bool IsFadeIN() const;
	bool GetIsScneChange() const;

	void SetSceneType(SceneType scenetype);
};