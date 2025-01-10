#include "SceneBase.h"
#include "GameUITime.h"
#include "ScoreManager.h"


GameUITime::GameUITime()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	m_Texture1 = renderManager->LoadTexture("Asset\\Number.dds");
	m_Texture2 = renderManager->LoadTexture("Asset\\GameTimeColon.dds");


	m_VertexBuffer1 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);
	m_VertexBuffer2 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);
	m_VertexBuffer3 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);
	m_VertexBuffer4 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);
	m_VertexBuffer5 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);


	//頂点データの書き込み
	{
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer1->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		buffer[0].Position = { -0.95f,  2.15f,  1.4f };
		buffer[1].Position = { -1.0f,  2.4f,  1.4f };
		buffer[2].Position = { -0.95f,  2.15f, 1.0f };
		buffer[3].Position = { -1.0f,  2.4f, 1.0f };

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

		buffer[0].Position = { -0.95f,  2.15f,  1.4f };
		buffer[1].Position = { -1.0f,  2.4f,  1.4f };
		buffer[2].Position = { -0.95f,  2.15f, 1.0f };
		buffer[3].Position = { -1.0f,  2.4f, 1.0f };

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

		m_VertexBuffer2->Resource->Unmap(0, nullptr);
	}

	{
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer3->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		buffer[0].Position = { -0.95f,  2.15f,  1.4f };
		buffer[1].Position = { -1.0f,  2.4f,  1.4f };
		buffer[2].Position = { -0.95f,  2.15f, 1.0f };
		buffer[3].Position = { -1.0f,  2.4f, 1.0f };

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

		m_VertexBuffer3->Resource->Unmap(0, nullptr);
	}

	{
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer4->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		buffer[0].Position = { -0.95f,  2.15f,  1.4f };
		buffer[1].Position = { -1.0f,  2.4f,  1.4f };
		buffer[2].Position = { -0.95f,  2.15f, 1.0f };
		buffer[3].Position = { -1.0f,  2.4f, 1.0f };

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

		m_VertexBuffer4->Resource->Unmap(0, nullptr);
	}

	{
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer5->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		buffer[0].Position = { -0.95f,  2.15f,  1.4f };
		buffer[1].Position = { -1.0f,  2.4f,  1.4f };
		buffer[2].Position = { -0.95f,  2.15f, 1.0f };
		buffer[3].Position = { -1.0f,  2.4f, 1.0f };

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

		m_VertexBuffer5->Resource->Unmap(0, nullptr);
	}

	m_AddTime = 0.0f;
	for (int i = 0; i < 4; i++)
	{
		m_PlayTime[i] = 0.0f;
	}
}

void GameUITime::Update()
{
	ScoreManager* scoreManager = ScoreManager::GetInstance();

	//a = scoreManager->GetScore();
	m_AddTime = 1 / 60.0f;

	m_PlayTime[0] += m_AddTime;

	if (m_PlayTime[0] >= 10)
	{
		m_PlayTime[1] += 1;
		m_PlayTime[0] = 0;
	}
	if (m_PlayTime[1] >= 6)
	{
		m_PlayTime[2] += 1;
		m_PlayTime[1] = 0;
	}
	if (m_PlayTime[2] >= 10)
	{
		m_PlayTime[3] += 1;
		m_PlayTime[2] = 0;
	}


	std::string scoreBase = std::to_string(0);
	float texX;
	float texY = 0.0f;         // スプライトシートのY座標


	int digit; // 最下位の数字を取得

	{
		digit = m_PlayTime[0];
		//digit += 2;

		// テクスチャ座標の設定
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer1->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		texX = digit * 0.1f; // スプライトシートのX座標（10分の1）

		// 頂点座標とテクスチャ座標を調整
		buffer[0].TexCoord = { texX, texY };
		buffer[1].TexCoord = { texX + 0.1f, texY };
		buffer[2].TexCoord = { texX, texY + 1.0f };
		buffer[3].TexCoord = { texX + 0.1f, texY + 1.0f };

		m_VertexBuffer1->Resource->Unmap(0, nullptr);

	}

	{
		digit = m_PlayTime[1];
		//digit += 2;

		// テクスチャ座標の設定
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer2->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		texX = digit * 0.1f; // スプライトシートのX座標（10分の1）

		// 頂点座標とテクスチャ座標を調整
		buffer[0].TexCoord = { texX, texY };
		buffer[1].TexCoord = { texX + 0.1f, texY };
		buffer[2].TexCoord = { texX, texY + 1.0f };
		buffer[3].TexCoord = { texX + 0.1f, texY + 1.0f };

		m_VertexBuffer2->Resource->Unmap(0, nullptr);
	}

	{
		digit = m_PlayTime[2];
		//digit += 2;

		// テクスチャ座標の設定
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer3->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		texX = digit * 0.1f; // スプライトシートのX座標（10分の1）

		// 頂点座標とテクスチャ座標を調整
		buffer[0].TexCoord = { texX, texY };
		buffer[1].TexCoord = { texX + 0.1f, texY };
		buffer[2].TexCoord = { texX, texY + 1.0f };
		buffer[3].TexCoord = { texX + 0.1f, texY + 1.0f };

		m_VertexBuffer3->Resource->Unmap(0, nullptr);
	}

	{
		digit = m_PlayTime[3];
		//digit += 2;

		// テクスチャ座標の設定
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer4->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		texX = digit * 0.1f; // スプライトシートのX座標（10分の1）

		// 頂点座標とテクスチャ座標を調整
		buffer[0].TexCoord = { texX, texY };
		buffer[1].TexCoord = { texX + 0.1f, texY };
		buffer[2].TexCoord = { texX, texY + 1.0f };
		buffer[3].TexCoord = { texX + 0.1f, texY + 1.0f };

		m_VertexBuffer4->Resource->Unmap(0, nullptr);
	}



	if (GetKeyState('K') & 0x8000)
	{
		//a += 1;
	}
}


void GameUITime::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();
	renderManager->SetPipelineState("Unlit");

	TimeDraw1();
	TimeDraw2();
	TimeDraw3();
	TimeDraw4();
	TimeDraw5();
}


void GameUITime::TimeDraw1()
{
	RenderManager* renderManager = RenderManager::GetInstance();
	//renderManager->SetPipelineState("Unlit");
	//マトリクス設定
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


void GameUITime::TimeDraw2()
{
	RenderManager* renderManager = RenderManager::GetInstance();
	//マトリクス設定
	{
		XMMATRIX world = XMMatrixIdentity();
		world *= XMMatrixScaling(m_Scale.x - 0.05, m_Scale.y - 0.07, m_Scale.z);
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
	renderManager->SetVertexBuffer(m_VertexBuffer2.get());

	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture1.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);

}


void GameUITime::TimeDraw3()
{
	RenderManager* renderManager = RenderManager::GetInstance();
	//マトリクス設定
	{
		XMMATRIX world = XMMatrixIdentity();
		world *= XMMatrixScaling(m_Scale.x - 0.15, m_Scale.y - 0.21, m_Scale.z);
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
	renderManager->SetVertexBuffer(m_VertexBuffer3.get());

	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture1.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);

}


void GameUITime::TimeDraw4()
{
	RenderManager* renderManager = RenderManager::GetInstance();
	//マトリクス設定
	{
		XMMATRIX world = XMMatrixIdentity();
		world *= XMMatrixScaling(m_Scale.x - 0.2, m_Scale.y - 0.28, m_Scale.z);
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
	renderManager->SetVertexBuffer(m_VertexBuffer4.get());

	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture1.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);
}

void GameUITime::TimeDraw5()
{
	RenderManager* renderManager = RenderManager::GetInstance();
	//マトリクス設定
	{
		XMMATRIX world = XMMatrixIdentity();
		world *= XMMatrixScaling(m_Scale.x - 0.1, m_Scale.y - 0.14, m_Scale.z);
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
	renderManager->SetVertexBuffer(m_VertexBuffer5.get());

	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture2.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);
}
