#pragma once

#include "SceneBase.h"


class ResultManager : public SceneBase
{
private:

	Camera			m_Camera;
	Polygon2D		m_Polygon2D;
	TestObject		m_TestObject;

	//SceneManager m_SceneManager;

public:
	ResultManager();
	~ResultManager() override;



	void Update() override;
	void Draw() override;


};

