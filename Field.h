#pragma once



class Field
{

private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };


	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer;
	std::unique_ptr<TEXTURE>		m_Texture;

public:

	Field();

	void Update();
	void Draw();
};

