#pragma once

#include "Model.h"
#include "Player.h"

enum EnemyBulletType
{
	HOMING,
	STRAIGHT,
};

class EnemyBullet
{
private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_PlayerPosition{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };
	XMFLOAT3		m_Velocity{ 0.0f, 0.0f, 0.0f };
	bool isActive;

	bool isSmall;
	bool isSmall2;

	Model			m_Model;
	Player*			m_Player;

	float m_Time{};

	EnemyBulletType m_EnemyBulletType;

public:
	EnemyBullet();

	EnemyBullet(Player* player);

	//ムーブメントコンストラクタ
	EnemyBullet(EnemyBullet&& other) noexcept;

	//ムーブ代入演算子
	EnemyBullet& operator=(EnemyBullet&& other) noexcept;

	~EnemyBullet();

	void Update();
	void Draw();

	void Reset(XMFLOAT3 start_position, XMFLOAT3 target_position, EnemyBulletType type);

	bool IsActive() const;
	void SetActive(bool isactive);
	void SetScale(XMFLOAT3 scale);

	void SetPlayer(Player* player);
	Player* GetPlayer();
};