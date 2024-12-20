#include "Main.h"
#include "RenderManager.h"
#include "Sky.h"


Sky::Sky()
{
	m_Model.Load("Asset\\sky.obj");

	m_Position = { 0.0f, 0.0f, 0.0f };
	m_Rotation = { 0.0f, 0.0f, 0.0f };
	m_Scale = { 2000.0f, 2000.0f, 2000.0f };

}




void Sky::Update()
{

}





void Sky::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();


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

	//パイプライン設定
	renderManager->SetPipelineState("Sky");

	m_Model.Draw();

}
