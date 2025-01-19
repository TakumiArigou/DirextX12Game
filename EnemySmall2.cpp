
#include "GameManager.h"

EnemySmall2::EnemySmall2(XMFLOAT3 pos, Player* player)
{
	m_Model.Load("Asset\\PlayerModel.obj");

	//m_Position = { 10.0f, 10.0f, 15.0f };
	m_Position = pos;
	m_Rotation = { 0.0f, 1.57f, 0.0f };
	m_Scale = { 0.1f, 0.1f, 0.1f };

	m_ShootCoolDown = 0.0f;
	m_ShootCoolDownMax = 0.5f;

	m_EnemyHP = 2;
	isActive = true;
	isDead = false;

	m_MoveX = 0.02f;
	m_MoveY = 0.01f;

	m_Player = player;
}

EnemySmall2::~EnemySmall2()
{
}


void EnemySmall2::Update()
{
	//弾発射のクールタイム処理
	if (m_ShootCoolDown > 0.0f) {
		m_ShootCoolDown -= 1.0f / 60.0f;
	}

	//弾の更新
	for (auto Bullet : m_Bullet) {
		Bullet->Update();
	}


	// Lerpによる線形補間で弾を目標位置に向かって移動
	m_Position.x = XMVectorGetX(XMVectorLerp(
		XMLoadFloat3(&m_Position),
		XMLoadFloat3(&m_MovePosition),
		m_MoveX
	));

	m_Position.y = XMVectorGetY(XMVectorLerp(
		XMLoadFloat3(&m_Position),
		XMLoadFloat3(&m_MovePosition),
		m_MoveY
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

	//非アクティブな弾を削除
	m_Bullet.erase(std::remove_if(m_Bullet.begin(), m_Bullet.end(), [](EnemyBullet* bullet)
		{
			return !bullet->IsActive();
		}), m_Bullet.end());

	if (m_ShootCoolDown <= 0.0f) {
		Shoot();
	}

	if (m_EnemyHP <= 0)
	{
		isDead = false;
	}
}





void EnemySmall2::Draw()
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

	m_Model.Draw();

	for (auto Bullet : m_Bullet) {
		Bullet->Draw();
	}
}

void EnemySmall2::Shoot()
{
	XMFLOAT3 playerPos = m_Player->GetPlayerPosition();

	// 新しい弾を生成して発射
	EnemyBullet* newBullet = new EnemyBullet(m_Position, playerPos, m_Player);  // エネミーの位置から弾を発射
	m_Bullet.push_back(newBullet);

	m_ShootCoolDown = m_ShootCoolDownMax;

}

bool EnemySmall2::IsActive()
{
	return isActive;
}

bool EnemySmall2::IsDead()
{
	return isDead;
}
