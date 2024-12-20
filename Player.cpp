
#include "GameManager.h"

Player::Player()
{
	m_Model.Load("Asset\\PlayerModel.obj");

	m_Position = { 0.0f, 0.0f, 5.0f };
	m_Rotation = { 0.0f, 1.57f, 0.0f };
	m_Scale = { 0.1f, 0.1f, 0.1f };

}




void Player::Update()
{


		//プレイヤー横移動処理
		//入力方向に回転を加える
		if (GetKeyState('A') & 0x8000)		//左入力(Aキー)
		{
			m_Position.x -= 0.07f;
			m_Rotation.x -= 0.02f;

			if (m_Rotation.x <= -0.5f)
			{
				m_Rotation.x = -0.5f;
			}
		}
		else if (GetKeyState('D') & 0x8000)	//右入力(Dキー)
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
		if (GetKeyState('W') & 0x8000)		//上入力(Wキー)
		{
			m_Position.y += 0.07f;
			m_Rotation.z -= 0.02f;

			if (m_Rotation.z <= -0.3f)
			{
				m_Rotation.z = -0.3f;
			}
		}
		else if (GetKeyState('S') & 0x8000)	//下入力(Sキー)
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

	//renderManager->SetPipelineState("Geometry");

	m_Model.Draw();
}