#pragma once

#include "SceneBase.h"
#include "Enemy.h"
#include "Sky.h"
#include "GameUIScore.h"


class GameManager : public SceneBase
{
private:

	Camera			m_Camera;
	GameUIScore		m_GameUIScore;
	Player			m_Player;
	Enemy			m_Enemy;
	Sky				m_Sky;

public:

	GameManager();
	~GameManager() override;


	void Update() override;
	void Draw() override;


};

