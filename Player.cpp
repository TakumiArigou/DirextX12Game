
#include "GameManager.h"

Player::Player()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	m_Model.Load("Asset\\PlayerModel.obj");
	m_Model2.Load("Asset\\PlayerModel2.obj");

	m_Position = { 0.0f, 0.0f, 5.0f };
	m_Rotation = { 0.0f, 1.57f, 0.0f };
	m_Scale = { 0.1f, 0.1f, 0.1f };
	m_Extents = { 1.0f, 1.0f, 1.0f };

	m_PlayerHP = MAX_PLAYER_HP;

	m_ShootCoolDown = 0.0f;
	m_ShootCoolDownMax = 0.1f;

	m_InvincbleTime = 0.0f;
	m_InvincbleTimeMax = 1.0f;

	m_InvincibleCoolDown = 0.0f;
	m_InvincibleCoolDownMax = 2.0f;
}

Player::~Player()
{
}


void Player::Update()
{
	GetPlayerHP();

	//弾発射のクールタイム処理
	if (m_ShootCoolDown > 0.0f) {
		m_ShootCoolDown -= 1.0f / 60.0f;
	}

	//無敵時間のクールタイム処理
	if (m_InvincibleCoolDown > 0.0f)
	{
		m_InvincibleCoolDown -= 1.0f / 60.0f;
	}

	//無敵時間の処理
	if (m_InvincbleTime > 0.0f)
	{
		m_InvincbleTime -= 1.0f / 60.0f;
	}
	else
	{
		isInvincible = false;
	}

	//弾の更新
	for (auto& Bullet : m_Bullet) {
		Bullet.Update();
	}

	//弾発射
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		Shoot();
	}

	if (GetAsyncKeyState('I') & 0x8000)
	{
		if (m_InvincibleCoolDown <= 0.0f)
		{
			Invincible();
		}
	}

	//プレイヤー横移動処理
	//入力方向に回転を加える
	if (GetAsyncKeyState('A') & 0x8000)		//左入力(Aキー)
	{
		m_Position.x -= 0.07f;
		m_Rotation.x -= 0.02f;

		if (m_Rotation.x <= -0.5f)
		{
			m_Rotation.x = -0.5f;
		}
	}
	else if (GetAsyncKeyState('D') & 0x8000)	//右入力(Dキー)
	{
		m_Position.x += 0.07f;
		m_Rotation.x += 0.02f;

		if (m_Rotation.x >= 0.5f)
		{
			m_Rotation.x = 0.5f;
		}
	}
	else if (m_Rotation.x < 0.0)	//非入力時に回転の値を0.0に戻す処理
	{
		m_Rotation.x += 0.01f;
	}
	else if (m_Rotation.x > 0.0)	//非入力時に回転の値を0.0に戻す処理
	{
		m_Rotation.x -= 0.01f;
	}

	//プレイヤー縦移送処理
	//入力方向に回転を加える
	if (GetAsyncKeyState('W') & 0x8000)		//上入力(Wキー)
	{
		m_Position.y += 0.07f;
		m_Rotation.z -= 0.02f;

		if (m_Rotation.z <= -0.3f)
		{
			m_Rotation.z = -0.3f;
		}
	}
	else if (GetAsyncKeyState('S') & 0x8000)	//下入力(Sキー)
	{
		m_Position.y -= 0.07f;
		m_Rotation.z += 0.02f;

		if (m_Rotation.z >= 0.3f)
		{
			m_Rotation.z = 0.3f;
		}
	}
	else if (m_Rotation.z < 0.0)	//非入力時に回転の値を0.0に戻す処理
	{
		m_Rotation.z += 0.01f;
	}
	else if (m_Rotation.z > 0.0)	//非入力時に回転の値を0.0に戻す処理
	{
		m_Rotation.z -= 0.01f;
	}

	//プレイヤーカメラ外処理
	if (m_Position.x >= 7.0f)
	{
		m_Position.x = 7.0f;
	}

	if (m_Position.x <= -7.0f)
	{
		m_Position.x = -7.0f;
	}

	if (m_Position.y >= 4.0f)
	{
		m_Position.y = 4.0f;
	}

	if (m_Position.y <= -4.0f)
	{
		m_Position.y = -4.0f;
	}
}


void Player::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	if (!isInvincible)
	{
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

		m_Model.Draw();
	}
	else if (isInvincible)
	{
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

		m_Model2.Draw();
	}

	for (auto& Bullet : m_Bullet) {
		Bullet.Draw();
	}
}


void Player::Shoot()
{
	if (m_ShootCoolDown <= 0.0f) {

		for (auto& bullet : m_Bullet)
		{
			if (!bullet.IsActive())
			{
				bullet.Reset(m_Position);
				bullet.SetActive(true);

				m_ShootCoolDown = m_ShootCoolDownMax;
				return;
			}
		}
	}
}


void Player::Invincible()
{
	if (m_InvincibleCoolDown <= 0.0f)
	{
		m_InvincibleCoolDown = m_InvincibleCoolDownMax;
	}

	if (m_InvincbleTime <= 0.0f)
	{
		isInvincible = true;
		m_InvincbleTime = m_InvincbleTimeMax;
	}
}


XMFLOAT3 Player::GetPlayerPosition() const 
{
	return m_Position;
}

XMFLOAT3 Player::GetPlayerScale() const
{
	return m_Scale;
}

bool Player::GetPlayerIsInvincible() const
{
	return isInvincible;
}

int Player::GetPlayerHP() const
{
	return m_PlayerHP;
}

void Player::SetPlayerHP(int damage)
{
	m_PlayerHP -= damage;
}

const std::array<PlayerBullet, 50>& Player::GetPlayerBullet() const
{
	return m_Bullet;
}

float Player::GetInvincibleTime() const
{
	return m_InvincibleCoolDown;
}

float Player::GetInvincibleTimeMax() const
{
	return m_InvincibleCoolDownMax;
}
