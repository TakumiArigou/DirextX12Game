
#include "GameManager.h"
#include "SceneManager.h"
#include "FadeManager.h"

GameManager::GameManager()
{
	m_Camera.SetCameraPosition(XMFLOAT3(0.0f, 0.0f, -3.5f));

	m_GameUIPlayerHPGage.SetPlayer(&m_Player);

	m_EnemyManager.SetPlayer(&m_Player);

	m_GameUIPlayerGage.SetPlayer(&m_Player);

	isBossDead = false;
	isNone = true;

	m_PlayerHP = 0;

	SceneManager::GetInstance()->SetIsImGui(false);
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

	if (isNone)
	{
		isBossDead = m_EnemyManager.GetBoss();
		m_PlayerHP = m_Player.GetPlayerHP();

		if (isBossDead)
		{
			isNone = false;
		}

		if (m_PlayerHP <= 0)
		{
			isNone = false;
			isBossDead = true;
		}
	}
	else if (!isNone)
	{
		if (isBossDead)
		{
			isBossDead = false;

			ScoreManager::GetInstance()->SetEnemyCount(0);

			FadeManager::GetInstance()->SetSceneType(SceneType::Result);
			FadeManager::GetInstance()->FadeOUT();
		}
	}

	FadeManager::GetInstance()->Update();


	if (!isBossDead)
	{
		m_Camera.Update();
		m_Sky.Update();
		m_Water.Update();
		m_GameField.Update();

		if (!SceneManager::GetInstance()->GetIsImGui())
		{
			m_Player.Update();
			m_EnemyManager.Update();

			m_GameUIScore.Update();
			m_GameUITime.Update();
			m_GameUIPlayerGage.Update();
			m_GameUIPlayerHPGage.Update();
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