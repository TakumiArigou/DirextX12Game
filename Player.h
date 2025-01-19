#pragma once

#include "Model.h"
#include "PlayerBullet.h"

class Player
{
private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };
	XMFLOAT3		m_Extents{ 0.0f, 0.0f, 0.0f };

	Model			m_Model;
	Model			m_Model2;

	int				m_PlayerHP;

	float			m_InvincibleCoolDown;
	float			m_InvincibleCoolDownMax;
	bool			isInvincible;

	float			m_ShootCoolDown;
	float			m_ShootCoolDownMax;
	std::vector<PlayerBullet*> m_Bullet;


public:

	Player();

	void Update();
	void Draw();

	void Shoot();
	void Invincible();

	XMFLOAT3 GetPlayerPosition() const;
	XMFLOAT3 GetPlayerScale() const;
	bool GetPlayerIsInvincible() const;
	int GetPlayerHP() const;
	void SetPlayerHP(int damage);
};