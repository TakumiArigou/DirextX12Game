#pragma once

class GameUIScore
{
private:
	
	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, -1.57f, -1.57f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer1;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer2;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer3;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer4;
	std::unique_ptr<TEXTURE>		m_Texture;

	int a;

public:

	GameUIScore();

	void Update();
	void Draw();

	void ScoreDraw1();
	void ScoreDraw2();
	void ScoreDraw3();
	void ScoreDraw4();
};