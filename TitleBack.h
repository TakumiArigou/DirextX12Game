#pragma once



class TitleBack
{

private:

	XMFLOAT3		m_Position{ -10.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, -1.57f, -1.57f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };


	std::unique_ptr<VERTEX_BUFFER>	m_VertexBuffer;
	std::unique_ptr<TEXTURE>		m_Texture;

public:

	TitleBack();

	void Update();
	void Draw();
};

