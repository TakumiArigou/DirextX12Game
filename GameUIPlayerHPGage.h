#pragma once

class GameUIPlayerHPGage
{
private:

	XMFLOAT3		m_Position{ 0.0f, -0.7f, 0.0f };
	XMFLOAT3		m_Rotation{ -0.1f, -1.57f, -1.57f };
	XMFLOAT3		m_Scale{ 0.8f, 1.0f, 0.5f };

	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer1;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer2;
	std::unique_ptr<TEXTURE>		m_Texture1;
	std::unique_ptr<TEXTURE>		m_Texture2;

	int a;

public:

	GameUIPlayerHPGage();

	void Update();
	void Draw();

	void PlayerHPDraw1();
	void PlayerHPDraw2();
};