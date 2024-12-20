

#include "TitleManager.h"





TitleBack::TitleBack()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	m_Texture = renderManager->LoadTexture("Asset\\Drill_01_diff_4k.dds");


	m_VertexBuffer = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);



	//頂点データの書き込み
	VERTEX_3D* buffer{};
	HRESULT hr = m_VertexBuffer->Resource->Map(0, nullptr, (void**)&buffer);
	assert(SUCCEEDED(hr));

	buffer[0].Position = { -50.0f,  0.0f,  50.0f };
	buffer[1].Position = {  50.0f,  0.0f,  50.0f };
	buffer[2].Position = { -50.0f,  0.0f, -50.0f };
	buffer[3].Position = {  50.0f,  0.0f, -50.0f };

	buffer[0].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
	buffer[1].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
	buffer[2].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
	buffer[3].Color = { 1.0f,  1.0f,  1.0f, 1.0f };

	buffer[0].Normal = { 0.0f, 1.0f, 0.0f };
	buffer[1].Normal = { 0.0f, 1.0f, 0.0f };
	buffer[2].Normal = { 0.0f, 1.0f, 0.0f };
	buffer[3].Normal = { 0.0f, 1.0f, 0.0f };

	buffer[0].TexCoord = {  0.0f,  0.0f };
	buffer[1].TexCoord = {  10.0f,  0.0f };
	buffer[2].TexCoord = {  0.0f,  10.0f };
	buffer[3].TexCoord = {  10.0f,  10.0f };

	m_VertexBuffer->Resource->Unmap(0, nullptr);
}




void TitleBack::Update()
{
}





void TitleBack::Draw()
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
	renderManager->SetVertexBuffer(m_VertexBuffer.get());


	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture.get());


	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//描画
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);


}
