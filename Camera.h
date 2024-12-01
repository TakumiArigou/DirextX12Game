#pragma once

#include "Json.h"

class Camera
{
public:

	Camera();

	void Update();
	void Draw();

private:

	XMFLOAT3 m_Position{ 0.0f, 1.0f, -3.5f };
	XMFLOAT3 m_Target{ 0.0f, 0.0f, 0.0f };
	
	POSTEFFECT_STATUS& postEffect = POSTEFFECT_STATUS::GetInstance();
};

