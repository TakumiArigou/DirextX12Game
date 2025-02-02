#pragma once

class ResultTime
{
private:

	XMFLOAT3		m_Position{ -1.8f, -1.3f, -1.4f };
	XMFLOAT3		m_Rotation{ 0.0f, -1.5f, -1.5f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer1;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer2;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer3;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer4;
	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer5;
	std::unique_ptr<TEXTURE>		m_Texture1;
	std::unique_ptr<TEXTURE>		m_Texture2;

	float m_AddTime;
	std::array<float, 4> m_ResultTime;

public:

	ResultTime();

	void Update();
	void Draw();

	void TimeDraw1();
	void TimeDraw2();
	void TimeDraw3();
	void TimeDraw4();
	void TimeDraw5();

	const std::array<float, 4>& GetPlayTime() const;
};