
#include "GameManager.h"

Player::Player()
{
	RenderManager* renderManager = RenderManager::GetInstance();

	m_Model.Load("Asset\\PlayerModel.obj");
	m_Model2.Load("Asset\\PlayerModel2.obj");

	m_Position = { 0.0f, 0.0f, 5.0f };
	m_Rotation = { 0.0f, 1.57f, 0.0f };
	m_Scale = { 0.1f, 0.1f, 0.1f };
	m_Extents = { 1.0f, 1.0f, 1.0f };

	m_PlayerHP = MAX_PLAYER_HP;

	m_ShootCoolDown = 0.0f;
	m_ShootCoolDownMax = 0.1f;

	m_InvincibleCoolDown = 0.0f;
	m_InvincibleCoolDownMax = 1.0f;
}




void Player::Update()
{
	GetPlayerHP();

	//�e���˂̃N�[���^�C������
	if (m_ShootCoolDown > 0.0f) {
		m_ShootCoolDown -= 1.0f / 60.0f;
	}

	//���G���Ԃ̃N�[���^�C������
	if (m_InvincibleCoolDown > 0.0f)
	{
		m_InvincibleCoolDown -= 1.0f / 60.0f;
	}
	else
	{
		isInvincible = false;
	}

	//�e�̍X�V
	for (auto Bullet : m_Bullet) {
		Bullet->Update();
	}

	//��A�N�e�B�u�Ȓe���폜
	m_Bullet.erase(std::remove_if(m_Bullet.begin(), m_Bullet.end(), [](PlayerBullet* bullet)
		{
			return !bullet->IsActive();
		}), m_Bullet.end());

	//�e����
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		Shoot();
	}

	if (GetKeyState('I') & 0x8000)
	{
		Invincible();
	}

	//�v���C���[���ړ�����
	//���͕����ɉ�]��������
	if (GetKeyState('A') & 0x8000)		//������(A�L�[)
	{
		m_Position.x -= 0.07f;
		m_Rotation.x -= 0.02f;

		if (m_Rotation.x <= -0.5f)
		{
			m_Rotation.x = -0.5f;
		}
	}
	else if (GetKeyState('D') & 0x8000)	//�E����(D�L�[)
	{
		m_Position.x += 0.07f;
		m_Rotation.x += 0.02f;

		if (m_Rotation.x >= 0.5f)
		{
			m_Rotation.x = 0.5f;
		}
	}
	else if (m_Rotation.x < 0.0)	//����͎��ɉ�]�̒l��0.0�ɖ߂�����
	{
		m_Rotation.x += 0.01f;
	}
	else if (m_Rotation.x > 0.0)	//����͎��ɉ�]�̒l��0.0�ɖ߂�����
	{
		m_Rotation.x -= 0.01f;
	}

	//�v���C���[�c�ڑ�����
	//���͕����ɉ�]��������
	if (GetKeyState('W') & 0x8000)		//�����(W�L�[)
	{
		m_Position.y += 0.07f;
		m_Rotation.z -= 0.02f;

		if (m_Rotation.z <= -0.3f)
		{
			m_Rotation.z = -0.3f;
		}
	}
	else if (GetKeyState('S') & 0x8000)	//������(S�L�[)
	{
		m_Position.y -= 0.07f;
		m_Rotation.z += 0.02f;

		if (m_Rotation.z >= 0.3f)
		{
			m_Rotation.z = 0.3f;
		}
	}
	else if (m_Rotation.z < 0.0)	//����͎��ɉ�]�̒l��0.0�ɖ߂�����
	{
		m_Rotation.z += 0.01f;
	}
	else if (m_Rotation.z > 0.0)	//����͎��ɉ�]�̒l��0.0�ɖ߂�����
	{
		m_Rotation.z -= 0.01f;
	}

	//�v���C���[�J�����O����
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

	if (!isInvincible)
	{
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
	else if (isInvincible)
	{
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

		m_Model2.Draw();
	}

	for (auto Bullet : m_Bullet) {
		Bullet->Draw();
	}
}


void Player::Shoot()
{
	if (m_ShootCoolDown <= 0.0f) {
		// �V�����e�𐶐����Ĕ���
		PlayerBullet* newBullet = new PlayerBullet(m_Position);  // �v���C���[�̈ʒu����e�𔭎�
		m_Bullet.push_back(newBullet);

		m_ShootCoolDown = m_ShootCoolDownMax;
	}
}

void Player::Invincible()
{
	if (m_InvincibleCoolDown <= 0.0f)
	{
		isInvincible = true;
		m_InvincibleCoolDown = m_InvincibleCoolDownMax;
	}
}

XMFLOAT3 Player::GetPlayerPosition() const 
{
	return m_Position;
}

XMFLOAT3 Player::GetPlayerScale() const
{
	return m_Scale;
}

bool Player::GetPlayerIsInvincible() const
{
	return isInvincible;
}

int Player::GetPlayerHP() const
{
	return m_PlayerHP;
}

void Player::SetPlayerHP(int damage)
{
	m_PlayerHP -= damage;
}
