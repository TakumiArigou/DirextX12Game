#pragma once

class TitleLogo
{
private:

	XMFLOAT3		m_Position{ 19.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ -1.57f, -1.57f, -1.57f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer1;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer2;
	std::unique_ptr<TEXTURE>		m_Texture;
	std::unique_ptr<TEXTURE>		m_Texture2;

	float m_Alpha;
	float m_AddAlpha;

public:

	TitleLogo();

	void Update();
	void Draw();

	void ScoreDraw1();
	void ScoreDraw2();
};