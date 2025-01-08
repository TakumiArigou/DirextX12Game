
#include "GameManager.h"

Enemy::Enemy()
{
	m_Model.Load("Asset\\PlayerModel.obj");

	m_Position = { 0.0f, 0.0f, 15.0f };
	m_Rotation = { 0.0f, 1.57f, 0.0f };
	m_Scale = { 0.1f, 0.1f, 0.1f };

	m_ShootCoolDown = 0.0f;
	m_ShootCoolDownMax = 0.5f;
}




void Enemy::Update()
{
	//弾発射のクールタイム処理
	if (m_ShootCoolDown > 0.0f) {
		m_ShootCoolDown -= 1.0f / 60.0f;
	}

	//弾の更新
	for (auto Bullet : m_Bullet) {
		Bullet->Update();
	}

	//非アクティブな弾を削除
	m_Bullet.erase(std::remove_if(m_Bullet.begin(), m_Bullet.end(), [](EnemyBullet* bullet)
		{
			return !bullet->IsActive();
		}), m_Bullet.end());

	if (m_ShootCoolDown <= 0.0f) {
		Shoot();
	}
}





void Enemy::Draw()
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

void Enemy::Shoot()
{
	XMFLOAT3 playerPos = m_Player->GetPlayerPosition();
	
		// 新しい弾を生成して発射
		EnemyBullet* newBullet = new EnemyBullet(m_Position, playerPos, m_Player);  // エネミーの位置から弾を発射
		m_Bullet.push_back(newBullet);

		m_ShootCoolDown = m_ShootCoolDownMax;
	
}

void Enemy::SetPlayer(Player* player)
{
	m_Player = player;
}
