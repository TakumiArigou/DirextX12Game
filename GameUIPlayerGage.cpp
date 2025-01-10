#include "SceneBase.h"
#include "GameUIPlayerGage.h"
#include "ScoreManager.h"


GameUIPlayerGage::GameUIPlayerGage()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	m_Texture1 = renderManager->LoadTexture("Asset\\PlayerHPGage1.dds");
	m_Texture2 = renderManager->LoadTexture("Asset\\PlayerHPGage2.dds");


	m_VertexBuffer1 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);
	m_VertexBuffer2 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);

	//頂点データの書き込み
	{
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer1->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		buffer[0].Position = { -0.91f,  0.99f,  -0.99f };
		buffer[1].Position = { -0.91f,  2.41f,  -0.99f };
		buffer[2].Position = { -0.91f,  0.99f, -1.2f };
		buffer[3].Position = { -0.91f,  2.41f, -1.2f };

		buffer[0].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
		buffer[1].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
		buffer[2].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
		buffer[3].Color = { 1.0f,  1.0f,  1.0f, 1.0f };

		buffer[0].Normal = { 0.0f, 1.0f, 0.0f };
		buffer[1].Normal = { 0.0f, 1.0f, 0.0f };
		buffer[2].Normal = { 0.0f, 1.0f, 0.0f };
		buffer[3].Normal = { 0.0f, 1.0f, 0.0f };

		buffer[0].TexCoord = { 0.0f,  0.0f };
		buffer[1].TexCoord = { 1.0f,  0.0f };
		buffer[2].TexCoord = { 0.0f,  1.0f };
		buffer[3].TexCoord = { 1.0f,  1.0f };

		m_VertexBuffer1->Resource->Unmap(0, nullptr);
	}

	{
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer2->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		buffer[0].Position = { -0.9f,  1.0f,  -1.0f };
		buffer[1].Position = { -0.9f,  2.4f,  -1.0f };
		buffer[2].Position = { -0.9f,  1.0f, -1.2f };
		buffer[3].Position = { -0.9f,  2.4f, -1.2f };

		buffer[0].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
		buffer[1].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
		buffer[2].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
		buffer[3].Color = { 1.0f,  1.0f,  1.0f, 1.0f };

		buffer[0].Normal = { 0.0f, 1.0f, 0.0f };
		buffer[1].Normal = { 0.0f, 1.0f, 0.0f };
		buffer[2].Normal = { 0.0f, 1.0f, 0.0f };
		buffer[3].Normal = { 0.0f, 1.0f, 0.0f };

		buffer[0].TexCoord = { 0.0f,  0.0f };
		buffer[1].TexCoord = { 10.0f,  0.0f };
		buffer[2].TexCoord = { 0.0f,  0.5f };
		buffer[3].TexCoord = { 10.0f,  0.5f };

		m_VertexBuffer2->Resource->Unmap(0, nullptr);
	}

	a = 0;
}

void GameUIPlayerGage::Update()
{

	if (GetKeyState('L') & 0x8000)
	{
		a -= 1;
	}
	else if (a <= 0)
	{
		a = 0;
	}

	if (GetKeyState('O') & 0x8000)
	{
		a += 1;
	}
	else if (a >= 10)
	{
		a = 10;
	}
}


void GameUIPlayerGage::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();
	renderManager->SetPipelineState("Unlit");

	PlayerDraw2();
	PlayerDraw1();
}

void GameUIPlayerGage::PlayerDraw1()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	{
		XMMATRIX world = XMMatrixIdentity();
		world *= XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z);
		world *= XMMatrixRotationRollPitchYaw(m_Rotation.z, m_Rotation.x, m_Rotation.y);
		world *= XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);

		OBJECT_CONSTANT constant{};
		XMStoreFloat4x4(&constant.World, XMMatrixTranspose(world));

		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::OBJECT, &constant, sizeof(constant));
	}

	//マテリアル設定
	{
		MATERIAL material{};
		material.BaseColor = XMFLOAT4{ 1.0f, 1.0f, 1.0f, 1.0f };
		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::SUBSET, &material, sizeof(material));
	}

	//頂点バッファ設定
	renderManager->SetVertexBuffer(m_VertexBuffer1.get());

	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture1.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);
}

void GameUIPlayerGage::PlayerDraw2()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	float texX;
	float texY;         // スプライトシートのY座標

	{
		texY = 0.0f;

		// テクスチャ座標の設定
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer2->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		texX = 0.14f; // スプライトシートのX座標（10分の1）

		buffer[0].Position = { -0.9f,  1.0f + (texX * a), -1.0f };
		buffer[1].Position = { -0.9f,  2.4f, -1.0f };
		buffer[2].Position = { -0.9f,  1.0f + (texX * a), -1.2f };
		buffer[3].Position = { -0.9f,  2.4f, -1.2f };

		buffer[0].TexCoord = { 0.0, texY };
		buffer[1].TexCoord = { 1.0, texY };
		buffer[2].TexCoord = { 0.0, texY + 0.5f };
		buffer[3].TexCoord = { 1.0, texY + 0.5f };

		m_VertexBuffer2->Resource->Unmap(0, nullptr);
	}


	{
		XMMATRIX world = XMMatrixIdentity();
		world *= XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z);
		world *= XMMatrixRotationRollPitchYaw(m_Rotation.z, m_Rotation.x, m_Rotation.y);
		world *= XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);

		OBJECT_CONSTANT constant{};
		XMStoreFloat4x4(&constant.World, XMMatrixTranspose(world));

		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::OBJECT, &constant, sizeof(constant));
	}

	//マテリアル設定
	{
		MATERIAL material{};

		if (a > 0)
		{
			material.BaseColor = XMFLOAT4{ 0.0f, 1.0f, 1.0f, 1.0f };
		}
		else
		{
			material.BaseColor = XMFLOAT4{ 0.0f, 0.0f, 1.0f, 1.0f };
		}

		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::SUBSET, &material, sizeof(material));
	}

	//頂点バッファ設定
	renderManager->SetVertexBuffer(m_VertexBuffer2.get());

	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture2.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);

}
