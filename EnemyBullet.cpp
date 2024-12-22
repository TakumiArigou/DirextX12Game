
#include "GameManager.h"


EnemyBullet::EnemyBullet(XMFLOAT3 startPos, XMFLOAT3 targetPos)
{
	m_Model.Load("Asset\\Enemy_Attack.obj");

	m_Position = startPos;
	m_PlayerPosition = targetPos;
	m_Rotation = { 0.0f, 1.57f, 0.0f };
	m_Scale = { 0.1f, 0.1f, 0.1f };
	m_Velocity = { 0.0f, 0.0f, 0.2f };
	isActive = true;
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
