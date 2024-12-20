#pragma once

#include "SceneBase.h"


class ResultManager : public SceneBase
{
private:

	Camera			m_Camera;
	Polygon2D		m_Polygon2D;
	Player			m_Plyaer;

public:
	ResultManager();
	~ResultManager() override;



	void Update() override;
	void Draw() override;


};

