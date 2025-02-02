
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
	m_TitleLogo.Update();

	//FadeManager::GetInstance()->Update();

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (GetKeyState(VK_SPACE) & 0x0001)
		{
			//FadeManager::GetInstance()->FadeOUT();

			//bool ia;

			//ia = FadeManager::GetInstance()->IsFading();

			//if (ia)
			{
				SceneManager::GetInstance()->SetSceneType(SceneType::Game);
			}
		}
	}
}




void TitleManager::Draw()
{

	RenderManager::GetInstance()->DrawBegin();

	m_Camera.Draw();
	m_TitleBack.Draw();
	m_TitleObject.Draw();
	m_TitleLogo.Draw();

	RenderManager::GetInstance()->DrawEnd();

}


