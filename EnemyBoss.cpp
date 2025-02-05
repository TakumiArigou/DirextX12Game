
#include "GameManager.h"
#include "OBBManager.h"
#include "ScoreManager.h"

EnemyBoss::EnemyBoss()
{
	m_Model.Load("Asset\\Enemy3.obj");

	m_Position = { 10.0f, 10.0f, 19.0f };
	m_Rotation = { 0.0f, -1.57f, 0.0f };
	m_Scale = { 3.0f, 3.0f, 3.0f };

	m_ShootCoolDown = 0.0f;
	m_ShootCoolDownMax = 1.0f;

	m_EnemyHP = 300;
	m_EnemyCount = 0;
	isActive = true;
	isDead = true;

	m_MoveX = 0.02f;
	m_MoveY = 0.01f;
}

EnemyBoss::EnemyBoss(XMFLOAT3 pos, Player* player)
{
	m_Model.Load("Asset\\Enemy3.obj");

	m_Position = pos;
	m_Rotation = { 0.0f, -1.57f, 0.0f };
	m_Scale = { 3.0f, 3.0f, 3.0f };

	m_ShootCoolDown = 0.0f;
	m_ShootCoolDownMax = 1.0f;

	m_EnemyHP = 300;
	m_EnemyCount = 0;
	isActive = true;
	isDead = true;

	m_MoveX = 0.02f;
	m_MoveY = 0.01f;

	m_Player = player;
}

EnemyBoss::EnemyBoss(EnemyBoss&& other) noexcept
{
	m_Model.Load("Asset\\Enemy3.obj");

	m_Position = { 10.0f, 10.0f, 19.0f };
	m_Rotation = { 0.0f, -1.57f, 0.0f };
	m_Scale = { 3.0f, 3.0f, 3.0f };

	m_ShootCoolDown = 0.0f;
	m_ShootCoolDownMax = 1.0f;

	m_EnemyHP = 300;
	m_EnemyCount = 0;
	isActive = true;
	isDead = true;

	m_MoveX = 0.02f;
	m_MoveY = 0.01f;

	m_Player = other.m_Player;
	other.m_Player = nullptr;
}


EnemyBoss& EnemyBoss::operator=(EnemyBoss&& other) noexcept
{
	if (this != &other) {
		m_Player = other.m_Player;
		other.m_Player = nullptr;  // ムーブ元のポインタを無効化
	}
	return *this;
}

EnemyBoss::~EnemyBoss()
{
}


void EnemyBoss::Update()
{
	ScoreManager* scoreManager = ScoreManager::GetInstance();

	if (!isActive) return;

	if (isDead)
	{
		if (scoreManager->GetEnemyCount() >= 20)
		{
			isDead = false;
		}
	}
	else if (!isDead)
	{
		//弾発射のクールタイム処理
		if (m_ShootCoolDown > 0.0f) {
			m_ShootCoolDown -= 1.0f / 60.0f;
		}

		//弾の更新
		for (auto& Bullet : m_Bullet) {
			Bullet.Update();
		}

		// Lerpによる線形補間で弾を目標位置に向かって移動
		m_Position.x = XMVectorGetX(XMVectorLerp(
			XMLoadFloat3(&m_Position),
			XMLoadFloat3(&m_MovePosition),
			(m_MoveX * 0.5)
		));

		m_Position.y = XMVectorGetY(XMVectorLerp(
			XMLoadFloat3(&m_Position),
			XMLoadFloat3(&m_MovePosition),
			(m_MoveY * 0.5)
		));

		if (m_Position.x >= 6.5)
		{
			m_MovePosition.x = -7;
		}
		else if (m_Position.x <= -6.5)
		{
			m_MovePosition.x = 7;
		}

		if (m_Position.y >= 3.7)
		{
			m_MovePosition.y = -4;
		}
		else if (m_Position.y <= -3.7)
		{
			m_MovePosition.y = 4;
		}

		const auto& playerBullet = m_Player->GetPlayerBullet();
		for (const auto& pBullet : playerBullet)
		{

			OBB		EnemyOBB(m_Position, XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 1.7, 1.7, 1.7);	//座標(X,Y,Z),X軸,Y軸,Z軸,ボックスのサイズ(X,Y,Z)
			OBB		PlayerBulletOBB(pBullet.GetPlayerBulletPosition(), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 0.5, 0.5, 0.5);	//座標(X,Y,Z),X軸,Y軸,Z軸,ボックスのサイズ(X,Y,Z)

			OBBManager	OM;

			//衝突処理
			bool isHit = OM.ColOBBs(EnemyOBB, PlayerBulletOBB);

			if (isHit)
			{
				m_EnemyHP -= 1;
				scoreManager->AddScore(10);
			}
		}

		if (m_ShootCoolDown <= 0.0f) {
			Shoot();
		}

		if (m_EnemyHP <= 0)
		{
			isDead = true;
			isActive = false;

			scoreManager->SetEnemyCount(0);
			m_EnemyHP = 0;
		}
	}
}


void EnemyBoss::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	//定数バッファ設定
	{
		ENV_CONSTANT constant;

		constant.LightDirection.x = 0.0f;
		constant.LightDirection.y = 1.0f;
		constant.LightDirection.z = 0.0f;

		constant.LightColor.x = 5.0f;
		constant.LightColor.y = 5.0f;
		constant.LightColor.z = 5.0f;

		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::ENV, &constant, sizeof(constant));
	}

	//マトリクス設定
	{
		XMMATRIX world = XMMatrixIdentity();
		world *= XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z);
		world *= XMMatrixRotationRollPitchYaw(m_Rotation.x, m_Rotation.y, m_Rotation.z);
		world *= XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);

		OBJECT_CONSTANT constant{};
		XMStoreFloat4x4(&constant.World, XMMatrixTranspose(world));

		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::OBJECT, &constant, sizeof(constant));
	}

	if (isActive)
	{

		m_Model.Draw();

		for (auto& Bullet : m_Bullet) {
			Bullet.Draw();
		}
	}
}

void EnemyBoss::Shoot()
{
	XMFLOAT3 playerPos = m_Player->GetPlayerPosition();

	for (auto& bullet : m_Bullet)
	{
		if (!bullet.IsActive())
		{
			bullet.SetPlayer(m_Player);
			bullet.Reset(m_Position, m_Player->GetPlayerPosition(), EnemyBulletType::STRAIGHT);
			bullet.SetScale(XMFLOAT3(1.0f, 1.0f, 1.0f));
			bullet.SetActive(true);

			m_ShootCoolDown = m_ShootCoolDownMax;
			return;
		}
	}
}

void EnemyBoss::SetPlayer(Player* player)
{
	m_Player = player;
}

void EnemyBoss::SetIsActive(bool isactive)
{
	isActive = isactive;
}

void EnemyBoss::SetEnemySmallPosition(XMFLOAT3 pos)
{
	m_Position = pos;
}

void EnemyBoss::SetAddCount(float count)
{
	m_AddCount = count;
}

std::array<EnemyBullet, 10>& EnemyBoss::GetEnemyBullet()
{
	return m_Bullet;
}

bool EnemyBoss::IsActive()
{
	return isActive;
}

bool EnemyBoss::IsDead()
{
	return isDead;
}