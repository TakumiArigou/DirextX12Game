#pragma once

#include "SceneBase.h"


class GameManager : public SceneBase
{
private:

	//static GameManager* m_Instance;

	//RenderManager	m_RenderManger;
	Camera			m_Camera;
	//Polygon2D		m_Polygon2D;
	Field			m_Field;
	TestObject		m_TestObject;

	//SceneManager m_SceneManager;

public:

	GameManager();
	~GameManager() override;


	void Update() override;
	void Draw() override;


};

