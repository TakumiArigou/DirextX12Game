#pragma once

#include "Model.h"

class EnemyBullet
{
private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_PlayerPosition{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };
	XMFLOAT3		m_Velocity{ 0.0f, 0.0f, 0.0f };
	bool isActive;

	Model			m_Model;
	Player*			m_Player;

	float m_Time{};

public:

	EnemyBullet(XMFLOAT3 startPos, XMFLOAT3 targetPos, Player* player);
	~EnemyBullet();

	void Update();
	void Draw();

	bool IsActive() const;
};