#pragma once


#include "TitleManager.h"
#include "GameManager.h"
#include "ResultManager.h"
#include "ScoreManager.h"


enum class SceneType 
{
	Title,
	Game,
	Result,
};

class SceneManager
{
private:
	static SceneManager* m_Instance;

	SceneType		m_Scene;

	std::unique_ptr<TitleManager> m_Title;
	std::unique_ptr<GameManager> m_Game;
	std::unique_ptr<ResultManager> m_Result;

	void InitializeScene(SceneType sceneType);
	void FinalizeScene(SceneType sceneType);

public:
	static SceneManager* GetInstance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new SceneManager();
		}
		return m_Instance;
	}

	SceneManager();
	~SceneManager();

	void Update();
	void Draw();

	void SetSceneType(SceneType sceneType);
};