#include "Main.h"
#include "Camera.h"
#include "RenderManager.h"
#include "Json.h"
#include "json.hpp"


Json::Json()
{
	
}


void Json::LoadJson(const std::string& loadFilePath)
{
	using json = nlohmann::json;

	//JSONファイルを読み込む
	std::ifstream OpenFile(loadFilePath);
	if (OpenFile.is_open()) {
		json Data;
		try {
			OpenFile >> Data;
		}
		catch (json::parse_error& e) {
			std::cerr << "JSON parse error: " << e.what() << std::endl;
		}

		materialStatus.m_ClearColor[0] = Data["Material_ClearColorStatus"]["r"].get<float>();
		materialStatus.m_ClearColor[1] = Data["Material_ClearColorStatus"]["g"].get<float>();
		materialStatus.m_ClearColor[2] = Data["Material_ClearColorStatus"]["b"].get<float>();

		materialStatus.m_Metallic = Data["Material_MetallicStatus"].get<float>();
		materialStatus.m_Roughness = Data["Material_RoughnessStatus"].get<float>();
		materialStatus.m_Specular = Data["Material_SpecularStatus"].get<float>();

		postEffect.isGrayScale = Data["PostEffect_GrayScaleFlag"].get<bool>();
		postEffect.isSepia = Data["PostEffect_SepiaFlag"].get<bool>();
		postEffect.isDistorsion = Data["PostEffect_DistortionFlag"].get<bool>();
		postEffect.isChromaticAberration = Data["PostEffect_ChromaticAberrationFlag"].get<bool>();

		postEffect.m_GrayScale[0] = Data["PostEffect_GrayScaleStatus"]["r"].get<float>();
		postEffect.m_GrayScale[1] = Data["PostEffect_GrayScaleStatus"]["g"].get<float>();
		postEffect.m_GrayScale[2] = Data["PostEffect_GrayScaleStatus"]["b"].get<float>();

		postEffect.m_Sepia[0] = Data["PostEffect_SepiaStatus"]["r"].get<float>();
		postEffect.m_Sepia[1] = Data["PostEffect_SepiaStatus"]["g"].get<float>();
		postEffect.m_Sepia[2] = Data["PostEffect_SepiaStatus"]["b"].get<float>();

		postEffect.m_Distorsion[0] = Data["PostEffect_DistortionStatus"]["Parameter"].get<float>();
		postEffect.m_Distorsion[1] = Data["PostEffect_DistortionStatus"]["Camera"].get<float>();

		postEffect.m_ChromaticAberration[0] = Data["PostEffect_ChromaticAberrationStatus"]["r"].get<float>();
		postEffect.m_ChromaticAberration[1] = Data["PostEffect_ChromaticAberrationStatus"]["g"].get<float>();
		postEffect.m_ChromaticAberration[2] = Data["PostEffect_ChromaticAberrationStatus"]["b"].get<float>();
		
		postEffect.m_Gamma = Data["Gamma_Parameter"].get<float>();

		OpenFile.close();
	}
	else {
		std::cerr << "Failed to open file for reading." << std::endl;
	}
}


void Json::SaveJson(const std::string& saveFilePath)
{
	using json = nlohmann::json;

	// JSONデータの作成
	json Data;

	json ClearColorStatus;
	ClearColorStatus["r"] = materialStatus.m_ClearColor[0];
	ClearColorStatus["g"] = materialStatus.m_ClearColor[1];
	ClearColorStatus["b"] = materialStatus.m_ClearColor[2];
	Data["Material_ClearColorStatus"] = ClearColorStatus;

	Data["Material_MetallicStatus"] = materialStatus.m_Metallic;
	Data["Material_RoughnessStatus"] = materialStatus.m_Roughness;
	Data["Material_SpecularStatus"] = materialStatus.m_Specular;

	Data["PostEffect_GrayScaleFlag"] = postEffect.isGrayScale;
	Data["PostEffect_SepiaFlag"] = postEffect.isSepia;
	Data["PostEffect_DistortionFlag"] = postEffect.isDistorsion;
	Data["PostEffect_ChromaticAberrationFlag"] = postEffect.isChromaticAberration;

	json GrayScaleStatus;
	GrayScaleStatus["r"] = postEffect.m_GrayScale[0];
	GrayScaleStatus["g"] = postEffect.m_GrayScale[1];
	GrayScaleStatus["b"] = postEffect.m_GrayScale[2];
	Data["PostEffect_GrayScaleStatus"] = GrayScaleStatus;

	json SepiaStatus;
	SepiaStatus["r"] = postEffect.m_Sepia[0];
	SepiaStatus["g"] = postEffect.m_Sepia[1];
	SepiaStatus["b"] = postEffect.m_Sepia[2];
	Data["PostEffect_SepiaStatus"] = SepiaStatus;

	json DistortionStatus;
	DistortionStatus["Parameter"] = postEffect.m_Distorsion[0];
	DistortionStatus["Camera"] = postEffect.m_Distorsion[1];
	Data["PostEffect_DistortionStatus"] = DistortionStatus;

	json ChromaticAberrationStatus;
	ChromaticAberrationStatus["r"] = postEffect.m_ChromaticAberration[0];
	ChromaticAberrationStatus["g"] = postEffect.m_ChromaticAberration[1];
	ChromaticAberrationStatus["b"] = postEffect.m_ChromaticAberration[2];
	Data["PostEffect_ChromaticAberrationStatus"] = ChromaticAberrationStatus;

	Data["Gamma_Parameter"] = postEffect.m_Gamma;

	//JSONファイルに保存
	std::ofstream SaveFile(saveFilePath);
	if (SaveFile.is_open()) {
		SaveFile << std::setw(4) << Data << std::endl;
		SaveFile.close();
	}
	else {
		std::cerr << "Failed to open file for writing." << std::endl;
	}
}