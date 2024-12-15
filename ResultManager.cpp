
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
	m_TestObject.Update();
	m_Polygon2D.Update();


	if (GetKeyState('A') & 0x8000)
	{
		SceneManager::GetInstance()->SetSceneType(SceneType::Title);
	}
}




void ResultManager::Draw()
{

	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();
	m_TestObject.Draw();

	RenderManager::GetInstance()->DrawEnd();

}