
#include "GameManager.h"
#include "TitleObject.h"

TitleObject::TitleObject()
{
	m_Model.Load("Asset\\PlayerModel.obj");

	m_Position = { 0.0f, 0.0f, 0.0f };
	m_Rotation = { 0.5f, 0.0f, 0.0f };
	m_Scale = { 1.0f, 1.0f, 1.0f };

}




void TitleObject::Update()
{
	m_Rotation.y += 0.01f;
}





void TitleObject::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	//�萔�o�b�t�@�ݒ�
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

	//�}�g���N�X�ݒ�
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