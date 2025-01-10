
#include "GameManager.h"
#include "SceneManager.h"

GameManager::GameManager()
{
	m_Camera.SetCameraPosition(XMFLOAT3(0.0f, 0.0f, -3.5f));

	m_Enemy.SetPlayer(&m_Player);
}




GameManager::~GameManager()
{
	RenderManager::GetInstance()->WaitGPU();
}





void GameManager::Update()
{
	m_Camera.Update();
	m_Sky.Update();
	m_Player.Update();
	m_Enemy.Update();

	m_GameUIScore.Update();
	m_GameUITime.Update();
	m_GameUIPlayerGage.Update();
	m_GameUIPlayerHPGage.Update();


	if (GetKeyState('Z') & 0x8000)
	{
		SceneManager::GetInstance()->SetSceneType(SceneType::Result);
	}

}




void GameManager::Draw()
{
	RenderManager::GetInstance()->DrawBegin();

	m_GameUIScore.Draw();
	m_GameUITime.Draw();
	m_GameUIPlayerGage.Draw();
	m_GameUIPlayerHPGage.Draw();

	m_Camera.Draw();

	m_Enemy.Draw();
	m_Player.Draw();





	m_Sky.Draw();

	RenderManager::GetInstance()->DrawEnd();

}


