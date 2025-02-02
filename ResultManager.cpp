
#include "ResultManager.h"
#include "SceneManager.h"

ResultManager::ResultManager()
{
	m_Camera.SetCameraPosition(XMFLOAT3(0.0f, 0.0f, -3.5f));
}




ResultManager::~ResultManager()
{
	RenderManager::GetInstance()->WaitGPU();
}




void ResultManager::Update()
{
	m_Camera.Update();

	m_ResultScore.Update();
	m_ResultTime.Update();

	if (GetKeyState('B') & 0x8000)
	{
		if (GetKeyState('B') & 0x0001)
		{
			SceneManager::GetInstance()->SetSceneType(SceneType::Title);
		}
	}

	if (GetKeyState('N') & 0x8000)
	{
		if (GetKeyState('N') & 0x0001)
		{
			SceneManager::GetInstance()->SetSceneType(SceneType::Game);
		}
	}

	if (GetKeyState('M') & 0x8000)
	{
		if (GetKeyState('M') & 0x0001)
		{
			PostQuitMessage(0);
			RenderManager::GetInstance()->WaitGPU();
		}
	}
}




void ResultManager::Draw()
{

	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();

	m_ResultScore.Draw();
	m_ResultTime.Draw();

	RenderManager::GetInstance()->DrawEnd();

}