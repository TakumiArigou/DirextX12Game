#pragma once

class ResultScore
{
private:

	XMFLOAT3		m_Position{ 2.07f, -0.95f, -1.75f };
	XMFLOAT3		m_Rotation{ 0.0f, -1.5f, -1.5f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer1;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer2;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer3;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer4;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBufferScore;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBufferTime;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBufferResultMenu;
	std::unique_ptr<TEXTURE>		m_Texture;
	std::unique_ptr<TEXTURE>		m_Texture2;
	std::unique_ptr<TEXTURE>		m_Texture3;
	std::unique_ptr<TEXTURE>		m_Texture4;

	int m_ResultScore;

public:

	ResultScore();

	void Update();
	void Draw();

	void ScoreDraw1();
	void ScoreDraw2();
	void ScoreDraw3();
	void ScoreDraw4();
	void ScoreDraw5();
	void TimeDraw();
	void ResultMenu();
};