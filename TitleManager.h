#pragma once


#include "RenderManager.h"
#include "Camera.h"
#include "Polygon2D.h"
#include "TestObject.h"

class TitleManager
{
private:

	static TitleManager* m_Instance;

	RenderManager	m_RenderManger;
	Camera			m_Camera;
	Polygon2D		m_Polygon2D;
	TestObject		m_TestObject;

public:
	static TitleManager* GetInstance() { return m_Instance; }

	TitleManager();
	~TitleManager();



	void Update();
	void Draw();


};

