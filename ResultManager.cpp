
#include "ResultManager.h"
#include "SceneManager.h"
#include "FadeManager.h"

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
	if (FadeManager::GetInstance()->GetIsScneChange())
	{
		FadeManager::GetInstance()->FadeIN();
	}

	m_Camera.Update();

	m_Plyaer.Update();

	m_ResultScore.Update();
	m_ResultTime.Update();

	FadeManager::GetInstance()->Update();

	if (GetAsyncKeyState('B') & 0x0001)
	{
		FadeManager::GetInstance()->SetSceneType(SceneType::Title);
		FadeManager::GetInstance()->FadeOUT();
	}

	if (GetAsyncKeyState('N') & 0x0001)
	{
		FadeManager::GetInstance()->SetSceneType(SceneType::Game);
		FadeManager::GetInstance()->FadeOUT();
	}

	if (GetAsyncKeyState('M') & 0x0001)
	{
		PostQuitMessage(0);
	}
}


void ResultManager::Draw()
{
	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();

	m_ResultScore.Draw();
	m_ResultTime.Draw();

	FadeManager::GetInstance()->Draw();

	RenderManager::GetInstance()->DrawEnd();
}