#pragma once

#include "SceneBase.h"
#include "Enemy.h"
#include "Sky.h"
#include "GameUIScore.h"
#include "GameUITime.h"
#include "GameUIPlayerHPGage.h"
#include "GameUIPlayerGage.h"

class GameManager : public SceneBase
{
private:

	Camera				m_Camera;
	GameUIScore			m_GameUIScore;
	GameUITime			m_GameUITime;
	GameUIPlayerGage	m_GameUIPlayerGage;
	GameUIPlayerHPGage	m_GameUIPlayerHPGage;
	Player				m_Player;
	Enemy				m_Enemy;
	Sky					m_Sky;

public:

	GameManager();
	~GameManager() override;


	void Update() override;
	void Draw() override;


};

