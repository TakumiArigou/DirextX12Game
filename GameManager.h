#pragma once

#include "SceneBase.h"
#include "Sky.h"


class GameManager : public SceneBase
{
private:

	Camera			m_Camera;
	//Polygon2D		m_Polygon2D;
	Player			m_Player;
	Sky				m_Sky;

public:

	GameManager();
	~GameManager() override;


	void Update() override;
	void Draw() override;


};

