
#include "SceneManager.h"

SceneManager* SceneManager::m_Instance = nullptr;

SceneManager::SceneManager()
{
	m_Instance = this;

	m_Scene = SceneType::Title;

	m_Title = std::make_unique<TitleManager>();
	m_Game = std::make_unique<GameManager>();
	m_Result = std::make_unique<ResultManager>();
}

SceneManager::~SceneManager()
{
	FinalizeScene(m_Scene);

	delete m_Instance;
}

void SceneManager::Update()
{
	//GetSceneType();

	switch (m_Scene) {
	case SceneType::Title:

		m_Title->Update();
		break;

	case SceneType::Game:

		m_Game->Update();
		break;

	case SceneType::Result:

		m_Result->Update();
		break;

	default:
		break;
	}

}

void SceneManager::Draw()
{
	switch (m_Scene) {
	case SceneType::Title:

		m_Title->Draw();
		break;

	case SceneType::Game:

		m_Game->Draw();
		break;

	case SceneType::Result:

		m_Result->Draw();
		break;

	default:
		break;
	}
}

void SceneManager::InitializeScene(SceneType sceneType)
{
	switch (sceneType)
	{
	case SceneType::Title:
		if (!m_Title) m_Title = std::make_unique<TitleManager>();
		break;
	case SceneType::Game:
		if (!m_Game) m_Game = std::make_unique<GameManager>();
		break;
	case SceneType::Result:
		if (!m_Result) m_Result = std::make_unique<ResultManager>();
		break;
	}
}

void SceneManager::FinalizeScene(SceneType sceneType)
{
	switch (sceneType)
	{
	case SceneType::Title:
		m_Title.reset();
		break;
	case SceneType::Game:
		m_Game.reset();
		break;
	case SceneType::Result:
		m_Result.reset();
		break;
	}
}

void SceneManager::SetSceneType(SceneType sceneType)
{
	FinalizeScene(m_Scene);
	m_Scene = sceneType;
	InitializeScene(sceneType);
}