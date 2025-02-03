
#include "GameManager.h"
#include "SceneManager.h"
#include "FadeManager.h"

GameManager::GameManager()
{
	m_Camera.SetCameraPosition(XMFLOAT3(0.0f, 0.0f, -3.5f));

	m_GameUIPlayerHPGage.SetPlayer(&m_Player);

	m_EnemyManager.SetPlayer(&m_Player);

	m_GameUIPlayerGage.SetPlayer(&m_Player);
	
	//m_EnemyManager.AddEnemy();
	//m_EnemyManager.AddEnemy();
}




GameManager::~GameManager()
{
	RenderManager::GetInstance()->WaitGPU();
}





void GameManager::Update()
{
	if (FadeManager::GetInstance()->GetIsScneChange())
	{
		FadeManager::GetInstance()->FadeIN();
	}

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

	FadeManager::GetInstance()->Update();

	if (GetKeyState('Z') & 0x8000)
	{
		if (GetKeyState('Z') & 0x0001)
		{
			FadeManager::GetInstance()->SetSceneType(SceneType::Result);
			FadeManager::GetInstance()->FadeOUT();
		}
	}

}




void GameManager::Draw()
{
	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();

	m_EnemyManager.Draw();
	m_Player.Draw();

	m_GameField.Draw();

	m_Water.Draw();

	m_Sky.Draw();

	m_GameUIScore.Draw();
	m_GameUITime.Draw();
	m_GameUIPlayerGage.Draw();
	m_GameUIPlayerHPGage.Draw();

	FadeManager::GetInstance()->Draw();

	RenderManager::GetInstance()->DrawEnd();
}


