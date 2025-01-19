
#include "GameManager.h"
#include "OBBManager.h"

EnemyBullet::EnemyBullet(XMFLOAT3 startPos, XMFLOAT3 targetPos, Player* player)
{
	m_Model.Load("Asset\\Enemy_Attack.obj");

	m_Position = startPos;
	m_PlayerPosition = targetPos;
	m_Rotation = { 0.0f, 1.57f, 0.0f };
	m_Scale = { 0.1f, 0.1f, 0.1f };
	m_Velocity = { 0.0f, 0.0f, 0.1f };
	isActive = true;

	m_Player = player;
}

EnemyBullet::~EnemyBullet()
{
}




void EnemyBullet::Update()
{
	if (!isActive) return;  // 非アクティブな弾は更新しない

	m_Time += 1.0 / 60.0f;

	// Lerpによる線形補間で弾を目標位置に向かって移動
	m_Position.x = XMVectorGetX(XMVectorLerp(
		XMLoadFloat3(&m_Position),
		XMLoadFloat3(&m_PlayerPosition),
		0.1 * m_Time
	));

	m_Position.y = XMVectorGetY(XMVectorLerp(
		XMLoadFloat3(&m_Position),
		XMLoadFloat3(&m_PlayerPosition),
		0.1 * m_Time
	));

	m_Position.z -= m_Velocity.z * m_Time;

	if (m_Position.z <= 0.0f) {
		isActive = false;
	}

	bool isPlayerInvincible = m_Player->GetPlayerIsInvincible();
	XMFLOAT3 pos = m_Player->GetPlayerPosition();
	XMFLOAT3 sca = {5.0f, 5.0f, 5.0f};

	OBB		PlayerOBB(pos, XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 0.5, 0.5, 0.5);	//座標(X,Y,Z),X軸,Y軸,Z軸,ボックスのサイズ(X,Y,Z)
	OBB		EnemyBulletOBB(m_Position, XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 0.5, 0.5, 0.5);	//座標(X,Y,Z),X軸,Y軸,Z軸,ボックスのサイズ(X,Y,Z)

	OBBManager	OM;

	//衝突処理
	bool isHit = OM.ColOBBs(PlayerOBB, EnemyBulletOBB);

	//プレイヤーが無敵でなければ当たり判定処理に入る
	if (!isPlayerInvincible)
	{
		//当たったら非アクティブ
		if (isHit)
		{
			m_Player->SetPlayerHP(1);
			isActive = false;
		}
	}
}





void EnemyBullet::Draw()
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
}

bool EnemyBullet::IsActive() const
{
	return isActive;
}