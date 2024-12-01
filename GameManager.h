#pragma once


#include "RenderManager.h"
#include "Camera.h"
#include "Polygon2D.h"
#include "Field.h"
#include "TestObject.h"

class GameManager
{
private:

	static GameManager* m_Instance;

	RenderManager	m_RenderManger;
	Camera			m_Camera;
	Polygon2D		m_Polygon2D;
	Field			m_Field;
	TestObject		m_TestObject;

public:
	static GameManager* GetInstance() { return m_Instance; }

	GameManager();
	~GameManager();



	void Update();
	void Draw();


};

