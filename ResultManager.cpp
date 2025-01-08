
#include "ResultManager.h"
#include "SceneManager.h"

ResultManager::ResultManager()
{
}




ResultManager::~ResultManager()
{
	RenderManager::GetInstance()->WaitGPU();
}





void ResultManager::Update()
{
	m_Camera.Update();
	m_Plyaer.Update();

	if (GetKeyState('Z') & 0x8000)
	{
		SceneManager::GetInstance()->SetSceneType(SceneType::Title);
	}
}




void ResultManager::Draw()
{

	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();
	m_Plyaer.Draw();

	RenderManager::GetInstance()->DrawEnd();

}