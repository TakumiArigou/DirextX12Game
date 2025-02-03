#pragma once

#include "EnemyBullet.h";

class GameUIPlayerGage
{
private:

	XMFLOAT3		m_Position{ 0.0f, -0.7f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.1f, -1.57f, -1.57f };
	XMFLOAT3		m_Scale{ 0.8f, 1.0f, 0.5f };

	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer1;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer2;
	std::unique_ptr<TEXTURE>		m_Texture1;
	std::unique_ptr<TEXTURE>		m_Texture2;

	Player*		m_Player;

	float m_InvincibleTime;
	float m_InvincibleTimeMax;

	float m_GageMax;
	float m_GageMin;

	float scaleValue;

	XMVECTOR V1;
	XMVECTOR V2;

public:

	GameUIPlayerGage();

	void Update();
	void Draw();

	void PlayerDraw1();
	void PlayerDraw2();

	void SetPlayer(Player* player);
};