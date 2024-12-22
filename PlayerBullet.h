#pragma once

#include "Model.h"

class PlayerBullet
{
private:

	XMFLOAT3		m_Position{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Rotation{ 0.0f, 0.0f, 0.0f };
	XMFLOAT3		m_Scale{ 1.0f, 1.0f, 1.0f };
	XMFLOAT3		m_Velocity{ 0.0f, 0.0f, 0.0f };
	bool isActive;

	Model			m_Model;

	float m_Time{};

public:

	PlayerBullet(XMFLOAT3 startPos);
	~PlayerBullet();

	void Update();
	void Draw();

	bool IsActive() const;
};

