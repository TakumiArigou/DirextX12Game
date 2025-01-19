#pragma once

#include "Model.h"
#include "EnemyBase.h"
#include "EnemyBullet.h"

class EnemySmall2 : public EnemyBase
{
private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	XMFLOAT3		m_MovePosition = { 7.0f, 4.0f, 15.0f };

	Model			m_Model;
	Player* m_Player;

	float			m_ShootCoolDown;
	float			m_ShootCoolDownMax;
	std::vector<EnemyBullet*> m_Bullet;

	int				m_EnemyHP;
	bool			isActive;
	bool			isDead;

	float			m_MoveX;
	float			m_MoveY;

public:

	EnemySmall2(XMFLOAT3 pos, Player* player);
	~EnemySmall2();

	void Update() override;
	void Draw() override;

	bool IsActive() override;
	bool IsDead() override;

	void Shoot();
};

