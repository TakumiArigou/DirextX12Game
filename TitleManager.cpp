
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
	m_TestObject.Update();
	m_Polygon2D.Update();

	if (GetKeyState('A') & 0x8000)
	{
		SceneManager::GetInstance()->SetSceneType(SceneType::Game);
	}
}




void TitleManager::Draw()
{

	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();
	m_TestObject.Draw();

	RenderManager::GetInstance()->DrawEnd();

}


