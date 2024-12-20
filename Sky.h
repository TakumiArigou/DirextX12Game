#pragma once

#include "Model.h"

class Sky
{
private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };

	Model			m_Model;

public:

	Sky();

	void Update();
	void Draw();

	void SetPosition(XMFLOAT3 Position) { m_Position = Position; }

};

