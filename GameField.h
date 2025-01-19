#pragma once



class GameField
{

private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	XMFLOAT3		m_LightRotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT4		m_FiledParameter{ 9.0f,150.0f,0.001f,0.0f };



	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer;
	std::unique_ptr<INDEX_BUFFER>	m_IndexBuffer;
	std::unique_ptr<TEXTURE>		m_Texture;

	static const int FIELD_X = 512;
	static const int FIELD_Z = 512;

	float	m_Time{};

public:

	GameField();

	void Update();
	void Draw();
};

