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
	bool isDistorsion = false;
	bool isChromaticAberration = false;

	float m_GrayScale[4] = { 0.0f, 0.333f, 0.666f, 1.0f };
	float m_Sepia[4] = { 0.8f, 0.4f, 0.1f, 1.0f };
	float m_Distorsion[2] = { 0.0f,0.75f };
	float m_ChromaticAberration[4] = { 0.000f, 0.003f, 0.006f, 1.0f };
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

class Json
{

public:

	Json();

	void LoadJson(const std::string& loadFilePath);
	void SaveJson(const std::string& saveFilePath);

private:


	std::string FilePathJson;

	POSTEFFECT_STATUS& postEffect = POSTEFFECT_STATUS::GetInstance();
	MATERIAL_STATUS& materialStatus = MATERIAL_STATUS::GetInstace();
};