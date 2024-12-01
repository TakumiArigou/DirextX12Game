

#include "Main.h"
#include "TitleManager.h"




TitleManager* TitleManager::m_Instance = nullptr;





TitleManager::TitleManager()
{
	m_Instance = this;


}




TitleManager::~TitleManager()
{
	m_RenderManger.WaitGPU();
}





void TitleManager::Update()
{
	m_Camera.Update();
	m_TestObject.Update();
	m_Polygon2D.Update();

}




void TitleManager::Draw()
{

	m_RenderManger.DrawBegin();

	m_Camera.Draw();
	m_TestObject.Draw();

	m_RenderManger.DrawEnd();

}


