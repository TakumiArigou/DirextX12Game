#pragma once

#include "SceneBase.h"
#include "EnemyManager.h"
#include "Sky.h"
#include "Water.h"
#include "GameField.h"
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
	EnemyManager		m_EnemyManager;
	Sky					m_Sky;
	Water				m_Water;
	GameField			m_GameField;

public:

	GameManager();
	~GameManager() override;

	void Update() override;
	void Draw() override;
};