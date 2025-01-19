#pragma once

class Water
{

private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	XMFLOAT3		m_LightRotation{ 0.0f, 0.0f, 0.0f };



	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer;
	std::unique_ptr<INDEX_BUFFER>	m_IndexBuffer;
	std::unique_ptr<TEXTURE>		m_Texture;

	static const int FIELD_X = 256;
	static const int FIELD_Z = 256;

	float m_WaterHieht = 5.0f; //îgÇÃçÇÇ≥
	float m_WaterOctave = 1; //îgÇÃÉeÉNÉXÉ`ÉÉÇÃëeÇ≥

public:

	Water();

	void Update();
	void Draw();
};

