#pragma once

#include "Json.h"

class Camera
{
public:

	Camera();

	void Update();
	void Draw();
	void SetCameraPosition(XMFLOAT3 cameraPosition);

	float			m_Time{};

private:

	XMFLOAT3 m_Position{ 20.0f, 0.0f, 0.0f };
	XMFLOAT3 m_Target{ 0.0f, 0.0f, 0.0f };
	
	POSTEFFECT_STATUS& postEffect = POSTEFFECT_STATUS::GetInstance();
};

