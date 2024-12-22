#pragma once

#include "Model.h"
#include "EnemyBullet.h"

class Enemy
{
private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	Model			m_Model;
	Player*			m_Player;

	float			m_ShootCoolDown;
	float			m_ShootCoolDownMax;
	std::vector<EnemyBullet*> m_Bullet;

public:

	Enemy();

	void Update();
	void Draw();

	void Shoot();

	void SetPlayer(Player* player);
};

