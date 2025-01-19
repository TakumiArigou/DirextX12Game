
#include "GameManager.h"
#include "SceneManager.h"


GameManager::GameManager()
{
	m_Camera.SetCameraPosition(XMFLOAT3(0.0f, 0.0f, -3.5f));

	m_GameUIPlayerHPGage.SetPlayer(&m_Player);

	m_EnemyManager.SetPlayer(&m_Player);
	//m_EnemyManager.AddEnemy();
	//m_EnemyManager.AddEnemy();
}




GameManager::~GameManager()
{
	RenderManager::GetInstance()->WaitGPU();
}





void GameManager::Update()
{
	m_Camera.Update();
	m_Sky.Update();
	m_Water.Update();
	m_GameField.Update();
	m_Player.Update();
	m_EnemyManager.Update();

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

	m_EnemyManager.Draw();
	m_Player.Draw();

	m_GameField.Draw();

	m_Water.Draw();

	m_Sky.Draw();

	RenderManager::GetInstance()->DrawEnd();

}


