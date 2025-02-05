#pragma once

class POSTEFFECT_STATUS
{
public:

	static POSTEFFECT_STATUS& GetInstance()
	{
		static POSTEFFECT_STATUS Instance;
		return Instance;
	}

	bool isGrayScale = false;
	bool isSepia = false;
	bool isDistorsion = true;
	bool isChromaticAberration = true;

	float m_GrayScale[4] = { 0.0f, 0.333f, 0.666f, 1.0f };
	float m_Sepia[4] = { 0.8f, 0.4f, 0.1f, 1.0f };
	float m_Distorsion[2] = { 0.05f, 0.95f };
	float m_ChromaticAberration[4] = { 0.000f, 0.001f, 0.002f, 1.0f };
	float m_Gamma = 2.2f;

	POSTEFFECT_STATUS() {}
	POSTEFFECT_STATUS(const POSTEFFECT_STATUS&) = delete;
	POSTEFFECT_STATUS& operator = (const POSTEFFECT_STATUS&) = delete;
};

class MATERIAL_STATUS
{
public:

	static MATERIAL_STATUS& GetInstace()
	{
		static MATERIAL_STATUS Instance;
		return Instance;
	}

	float m_ClearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	float m_Metallic = 0.0f;
	float m_Roughness = 0.2f;
	float m_Specular = 1.0f;

	MATERIAL_STATUS() {}
	MATERIAL_STATUS(const MATERIAL_STATUS&) = delete;
	MATERIAL_STATUS& operator = (const MATERIAL_STATUS&) = delete;
};