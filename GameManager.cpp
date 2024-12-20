

#include "GameManager.h"
#include "SceneManager.h"

GameManager::GameManager()
{
	m_Camera.SetCameraPosition(XMFLOAT3(0.0f, 0.0f, -3.5f));
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


	if (GetKeyState('Z') & 0x8000)
	{
		SceneManager::GetInstance()->SetSceneType(SceneType::Result);
	}

}




void GameManager::Draw()
{
	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();

	m_Player.Draw();

	m_Sky.Draw();



	RenderManager::GetInstance()->DrawEnd();

}


