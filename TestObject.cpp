
#include "Main.h"
#include "RenderManager.h"
#include "TestObject.h"


TestObject::TestObject()
{
	m_Model.Load("Asset\\Drill_01_4k.obj");

	m_Position = { 0.0f, 0.0f, 0.0f };
	m_Rotation = { 0.0f, 0.0f, 0.0f };
	m_Scale = { 10.0f, 10.0f, 10.0f };

}




void TestObject::Update()
{
	m_Rotation.y += 0.01f;
}





void TestObject::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();

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