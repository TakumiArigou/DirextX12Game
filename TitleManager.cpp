
#include "TitleManager.h"
#include "SceneManager.h"


TitleManager::TitleManager()
{
}




TitleManager::~TitleManager()
{
	RenderManager::GetInstance()->WaitGPU();
}





void TitleManager::Update()
{
	m_Camera.Update();
	m_TitleBack.Update();
	m_TitleObject.Update();

	if (GetKeyState('Z') & 0x8000)
	{
		SceneManager::GetInstance()->SetSceneType(SceneType::Game);
	}
}




void TitleManager::Draw()
{

	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();
	m_TitleBack.Draw();
	m_TitleObject.Draw();

	RenderManager::GetInstance()->DrawEnd();

}


