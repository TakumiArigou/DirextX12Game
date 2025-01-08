#include "SceneBase.h"
#include "GameUIScore.h"
#include "ScoreManager.h"


GameUIScore::GameUIScore()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	m_Texture = renderManager->LoadTexture("Asset\\Number.dds");


	m_VertexBuffer1 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);
	m_VertexBuffer2 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);
	m_VertexBuffer3 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);
	m_VertexBuffer4 = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);

	//頂点データの書き込み
	{
		VERTEX_3D* buffer{};
		HRESULT hr = m_VertexBuffer1->Resource->Map(0, nullptr, (void**)&buffer);
		assert(SUCCEEDED(hr));

		buffer[0].Position = { -1.0f,  -2.4f,  1.4f };
		buffer[1].Position = { -0.95f,  -2.15f,  1.4f };
		buffer[2].Position = { -1.0f,  -2.4f, 1.0f };
		buffer[3].Position = { -0.95f,  -2.15f, 1.0f };

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

		buffer[0].Position = { -1.0f,  -2.4f,  1.4f };
		buffer[1].Position = { -0.95f,  -2.15f,  1.4f };
		buffer[2].Position = { -1.0f,  -2.4f, 1.0f };
		buffer[3].Position = { -0.95f,  -2.15f, 1.0f };

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

		buffer[0].Position = { -1.0f,  -2.4f,  1.4f };
		buffer[1].Position = { -0.95f,  -2.15f,  1.4f };
		buffer[2].Position = { -1.0f,  -2.4f, 1.0f };
		buffer[3].Position = { -0.95f,  -2.15f, 1.0f };

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

		buffer[0].Position = { -1.0f,  -2.4f,  1.4f };
		buffer[1].Position = { -0.95f,  -2.15f,  1.4f };
		buffer[2].Position = { -1.0f,  -2.4f, 1.0f };
		buffer[3].Position = { -0.95f,  -2.15f, 1.0f };

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

	a = 1000;
}

void GameUIScore::Update()
{
	ScoreManager* scoreManager = ScoreManager::GetInstance();

	//a = scoreManager->GetScore();

	std::string scoreBase = std::to_string(a);
	float texX;
	float texY = 0.0f;         // スプライトシートのY座標


	int digit; // 最下位の数字を取得

	{
		digit = scoreBase[0];
		digit += 2;

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
		digit = scoreBase[1];
		digit += 2;

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
		digit = scoreBase[2];
		digit += 2;

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
		digit = scoreBase[3];
		digit += 2;

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
		a += 1;
	}
}


void GameUIScore::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();
	renderManager->SetPipelineState("Unlit");

	ScoreDraw1();
	ScoreDraw2();
	ScoreDraw3();
	ScoreDraw4();
}


void GameUIScore::ScoreDraw1()
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
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);

}


void GameUIScore::ScoreDraw2()
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
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);

}


void GameUIScore::ScoreDraw3()
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
	renderManager->SetVertexBuffer(m_VertexBuffer3.get());

	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);

}


void GameUIScore::ScoreDraw4()
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
	renderManager->SetVertexBuffer(m_VertexBuffer4.get());

	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);
}