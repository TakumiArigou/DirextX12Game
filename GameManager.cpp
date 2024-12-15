

#include "GameManager.h"
#include "SceneManager.h"

GameManager::GameManager()
{

}




GameManager::~GameManager()
{
	RenderManager::GetInstance()->WaitGPU();
}





void GameManager::Update()
{
	m_Camera.Update();
	m_Field.Update();
	m_TestObject.Update();

	if (GetKeyState('A') & 0x8000)
	{
		SceneManager::GetInstance()->SetSceneType(SceneType::Result);
	}

}




void GameManager::Draw()
{
	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();
	m_Field.Draw();
	m_TestObject.Draw();

	RenderManager::GetInstance()->DrawEnd();

}


