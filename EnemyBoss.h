#pragma once

#include "Model.h"
#include "EnemyBase.h"
#include "EnemyBullet.h"

class EnemyBoss : public EnemyBase
{
private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	XMFLOAT3		m_MovePosition = { 7.0f, 4.0f, 15.0f };

	Model			m_Model;
	Player*			m_Player;

	float			m_AddCount;
	float			m_ShootCoolDown;
	float			m_ShootCoolDownMax;
	std::array<EnemyBullet, 10> m_Bullet;

	PlayerBullet	m_PlayerBullet;

	int				m_EnemyHP;
	int				m_EnemyCount;
	bool			isActive;
	bool			isDead;

	float			m_MoveX;
	float			m_MoveY;

	float time = 0;

public:

	EnemyBoss();
	EnemyBoss(XMFLOAT3 pos, Player* player);

	//ムーブメントコンストラクタ
	EnemyBoss(EnemyBoss&& other) noexcept;

	//ムーブ代入演算子
	EnemyBoss& operator=(EnemyBoss&& other) noexcept;

	~EnemyBoss();

	void Update() override;
	void Draw() override;

	bool IsActive() override;
	bool IsDead() override;

	void Shoot();

	void SetPlayer(Player* player);
	void SetIsActive(bool isactive);
	void SetEnemySmallPosition(XMFLOAT3 pos);
	void SetAddCount(float count);

	std::array<EnemyBullet, 10>& GetEnemyBullet();
};

