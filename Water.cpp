
#include "Main.h"
#include "RenderManager.h"
#include "Water.h"


Water::Water()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	m_Texture = renderManager->LoadTexture("Asset\\field004.dds");



	{
		m_VertexBuffer = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), FIELD_X * FIELD_Z);

		VERTEX_3D* vertex{};
		HRESULT hr = m_VertexBuffer->Resource->Map(0, nullptr, (void**)&vertex);
		assert(SUCCEEDED(hr));

		for (int z = 0; z < FIELD_Z; z++)
		{
			for (int x = 0; x < FIELD_X; x++)
			{
				vertex[z * FIELD_X + x].Position.x = x * 10.0f - FIELD_X * 10.0f / 2;
				vertex[z * FIELD_X + x].Position.z = -z * 10.0f + FIELD_Z * 10.0f / 2;
				vertex[z * FIELD_X + x].Position.y = -200.0f;
				vertex[z * FIELD_X + x].Color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
				vertex[z * FIELD_X + x].TexCoord = XMFLOAT2(x, z);
				vertex[z * FIELD_X + x].Normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
			}
		}

		m_VertexBuffer->Resource->Unmap(0, nullptr);
	}




	{
		m_IndexBuffer = renderManager->CreateIndexBuffer((FIELD_X * 2 + 2) * (FIELD_Z - 1) - 2);

		unsigned int* index{};
		HRESULT hr = m_IndexBuffer->Resource->Map(0, nullptr, (void**)&index);
		assert(SUCCEEDED(hr));

		unsigned int i = 0;
		for (int z = 0; z < FIELD_Z - 1; z++)
		{
			for (int x = 0; x < FIELD_X; x++)
			{
				index[i] = (z + 1) * FIELD_X + x;
				i++;
				index[i] = z * FIELD_X + x;
				i++;
			}

			if (z == FIELD_Z - 2)
				break;

			index[i] = z * FIELD_X + FIELD_X - 1;
			i++;
			index[i] = (z + 2) * FIELD_X;
			i++;
		}

		m_IndexBuffer->Resource->Unmap(0, nullptr);
	}
}




void Water::Update()
{

}





void Water::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	ImGui::Begin("Water");

	OBJECT_CONSTANT constant{};
	//定数バッファ設定
	{

		ImGui::SliderFloat("Hight", (float*)&m_WaterHieht, 1.0f, 100.0f);
		ImGui::SliderFloat("Octave", (float*)&m_WaterOctave, 1.0f, 10.0f);

		constant.Water.x = m_WaterHieht;
		constant.Water.y = m_WaterOctave;
		constant.Water.z = 0.0f;
		constant.Water.w = 0.0f;
	}

	ImGui::End();

	//マトリクス設定
	{
		XMMATRIX world = XMMatrixIdentity();
		world *= XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z);
		world *= XMMatrixRotationRollPitchYaw(m_Rotation.z, m_Rotation.x, m_Rotation.y);
		world *= XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);

		XMStoreFloat4x4(&constant.World, XMMatrixTranspose(world));

		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::OBJECT, &constant, sizeof(constant));
	}



	//頂点バッファ設定
	renderManager->SetVertexBuffer(m_VertexBuffer.get());

	//インデックスバッファ設定
	renderManager->SetIndexBuffer(m_IndexBuffer.get());

	//テクスチャ設定
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture.get());

	//トポロジ設定
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//パイプライン設定
	renderManager->SetPipelineState("Water");

	//描画
	renderManager->GetGraphicsCommandList()->DrawIndexedInstanced(((FIELD_X * 2 + 2) * (FIELD_Z - 1) - 2), 1, 0, 0, 0);


}
