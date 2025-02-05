
#include "TitleManager.h"
#include "SceneManager.h"
#include "FadeManager.h"

TitleManager::TitleManager()
{
}


TitleManager::~TitleManager()
{
	RenderManager::GetInstance()->WaitGPU();
}


void TitleManager::Update()
{
	if (FadeManager::GetInstance()->GetIsScneChange())
	{
		FadeManager::GetInstance()->FadeIN();
	}

	m_Camera.Update();
	m_TitleBack.Update();
	m_TitleObject.Update();
	m_TitleLogo.Update();

	FadeManager::GetInstance()->Update();

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		FadeManager::GetInstance()->SetSceneType(SceneType::Game);
		FadeManager::GetInstance()->FadeOUT();
	}
}


void TitleManager::Draw()
{
	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();
	m_TitleBack.Draw();
	m_TitleObject.Draw();
	m_TitleLogo.Draw();

	FadeManager::GetInstance()->Draw();

	RenderManager::GetInstance()->DrawEnd();
}