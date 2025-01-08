

#include "TitleManager.h"





TitleBack::TitleBack()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	m_Texture = renderManager->LoadTexture("Asset\\Number.dds");


	m_VertexBuffer = renderManager->CreateVertexBuffer(sizeof(VERTEX_3D), 4);



	//���_�f�[�^�̏�������
	VERTEX_3D* buffer{};
	HRESULT hr = m_VertexBuffer->Resource->Map(0, nullptr, (void**)&buffer);
	assert(SUCCEEDED(hr));

	buffer[0].Position = { -1.0f,  7.5f,  1.4f };
	buffer[1].Position = { -0.95f,  8.0f,  1.4f };
	buffer[2].Position = { -1.0f,  7.5f, 1.0f };
	buffer[3].Position = { -0.95f,  8.0f, 1.0f };

	//buffer[0].Position = { -50.0f,  0.0f,  50.0f };
	//buffer[1].Position = { 50.0f,  0.0f,  50.0f };
	//buffer[2].Position = { -50.0f,  0.0f, -50.0f };
	//buffer[3].Position = { 50.0f,  0.0f, -50.0f };

	buffer[0].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
	buffer[1].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
	buffer[2].Color = { 1.0f,  1.0f,  1.0f, 1.0f };
	buffer[3].Color = { 1.0f,  1.0f,  1.0f, 1.0f };

	buffer[0].Normal = { 0.0f, 1.0f, 0.0f };
	buffer[1].Normal = { 0.0f, 1.0f, 0.0f };
	buffer[2].Normal = { 0.0f, 1.0f, 0.0f };
	buffer[3].Normal = { 0.0f, 1.0f, 0.0f };

	buffer[0].TexCoord = {  0.0f,  0.0f };
	buffer[1].TexCoord = {  1.0f,  0.0f };
	buffer[2].TexCoord = {  0.0f,  1.0f };
	buffer[3].TexCoord = {  1.0f,  1.0f };

	m_VertexBuffer->Resource->Unmap(0, nullptr);
}




void TitleBack::Update()
{
	int score = 3;
	int digit = score % 10; // �ŉ��ʂ̐������擾
	score /= 10; // ���̌��ɐi��

	// �e�N�X�`�����W�̐ݒ�
	VERTEX_3D* buffer{};
	HRESULT hr = m_VertexBuffer->Resource->Map(0, nullptr, (void**)&buffer);
	assert(SUCCEEDED(hr));

	float texX = digit * 0.1f; // �X�v���C�g�V�[�g��X���W�i10����1�j
	float texY = 0.0f;         // �X�v���C�g�V�[�g��Y���W

	// ���_���W�ƃe�N�X�`�����W�𒲐�
	buffer[0].TexCoord = { texX, texY };
	buffer[1].TexCoord = { texX + 0.1f, texY };
	buffer[2].TexCoord = { texX, texY + 1.0f };
	buffer[3].TexCoord = { texX + 0.1f, texY + 1.0f };

	//for (int j = 0; j < 4; ++j)
	{
		//buffer[0].Position.x += offsetX + 1 * digitWidth; // �����̈ʒu�𒲐�
	}

	m_VertexBuffer->Resource->Unmap(0, nullptr);
}





void TitleBack::Draw()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	renderManager->SetPipelineState("Unlit");

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
		world *= XMMatrixRotationRollPitchYaw(m_Rotation.z, m_Rotation.x, m_Rotation.y);
		world *= XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);

		OBJECT_CONSTANT constant{};
		XMStoreFloat4x4(&constant.World, XMMatrixTranspose(world));

		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::OBJECT, &constant, sizeof(constant));
	}



	//�}�e���A���ݒ�
	{
		MATERIAL material{};
		material.BaseColor = XMFLOAT4{ 1.0f, 1.0f, 1.0f, 1.0f };
		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::SUBSET, &material, sizeof(material));
	}



	//���_�o�b�t�@�ݒ�
	renderManager->SetVertexBuffer(m_VertexBuffer.get());


	//�e�N�X�`���ݒ�
	renderManager->SetTexture(RenderManager::TEXTURE_TYPE::BASE_COLOR, m_Texture.get());


	//�g�|���W�ݒ�
	renderManager->GetGraphicsCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//�`��
	renderManager->GetGraphicsCommandList()->DrawInstanced(4, 1, 0, 0);


}
