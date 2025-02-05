
#include "SceneBase.h"
#include "SceneManager.h"

Camera::Camera()
{
	
}


void Camera::Update()
{
	m_Time += 1.0f / 60.0f;
}


void Camera::Draw()
{	
	RenderManager* renderManager = RenderManager::GetInstance();

	if (SceneManager::GetInstance()->GetIsImGui())
	{
		{
			ImGui::Begin("PostEffect");

			ImGui::Checkbox("GrayScale", &postEffect.isGrayScale);
			if (ImGui::TreeNode("GrayScale Parameter"))
			{
				ImGui::SliderFloat("GrayScale_R", &postEffect.m_GrayScale[0], 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat("GrayScale_G", &postEffect.m_GrayScale[1], 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat("GrayScale_B", &postEffect.m_GrayScale[2], 0.0f, 1.0f, "%.2f");

				ImGui::TreePop();
			}

			ImGui::LabelText("", "");

			ImGui::Checkbox("Sepia", &postEffect.isSepia);
			if (ImGui::TreeNode("Sepia Parameter"))
			{
				ImGui::SliderFloat("Sepia_R", &postEffect.m_Sepia[0], 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat("Sepia_G", &postEffect.m_Sepia[1], 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat("Sepia_B", &postEffect.m_Sepia[2], 0.0f, 1.0f, "%.2f");

				ImGui::TreePop();
			}

			ImGui::LabelText("", "");

			ImGui::Checkbox("Distorsion", &postEffect.isDistorsion);
			if (ImGui::TreeNode("Distorsion Parameter"))
			{
				ImGui::SliderFloat("Distorsion_Parameter", &postEffect.m_Distorsion[0], -1.0f, 1.0f, "%.2f");
				ImGui::SliderFloat("Distorsion_Camera", &postEffect.m_Distorsion[1], 1.2f, 0.5f, "%.2f");

				ImGui::TreePop();
			}

			ImGui::LabelText("", "");

			ImGui::Checkbox("ChromaticAberration", &postEffect.isChromaticAberration);
			if (ImGui::TreeNode("ChromaticAberration Parameter"))
			{
				ImGui::SliderFloat("ChromaticAberration_R", &postEffect.m_ChromaticAberration[0], 0.01f, 0.0f, "%.4f");
				ImGui::SliderFloat("ChromaticAberration_G", &postEffect.m_ChromaticAberration[1], 0.01f, 0.0f, "%.4f");
				ImGui::SliderFloat("ChromaticAberration_B", &postEffect.m_ChromaticAberration[2], 0.01f, 0.0f, "%.4f");

				ImGui::TreePop();
			}

			ImGui::LabelText("", "");
			ImGui::LabelText("", "Gamma");

			ImGui::SliderFloat("Gamma_Parameter", &postEffect.m_Gamma, 0.0f, 5.0f, "%.2f");

			ImGui::End();
		}

		//Material
		ImGui::Begin("Material");

		if (ImGui::TreeNode("GGX"))
		{
			ImGui::SliderFloat("Metallic", &materialStatus.m_Metallic, 0.0f, 1.0f, "%.2f");
			ImGui::SliderFloat("Roughness", &materialStatus.m_Roughness, 0.0f, 1.0f, "%.2f");
			ImGui::SliderFloat("Specular", &materialStatus.m_Specular, 0.0f, 2.0f, "%.2f");


			ImGui::TreePop();
		}

		if (ImGui::TreeNode("ClearColor"))
		{
			ImGui::SliderFloat("ClearColor_R", &materialStatus.m_ClearColor[0], 0.0f, 1.0f, "%.2f");
			ImGui::SliderFloat("ClearColor_G", &materialStatus.m_ClearColor[1], 0.0f, 1.0f, "%.2f");
			ImGui::SliderFloat("ClearColor_B", &materialStatus.m_ClearColor[2], 0.0f, 1.0f, "%.2f");

			ImGui::TreePop();
		}

		ImGui::End();
	}

	//マテリアル設定
	{
		MATERIAL material{};
		material.BaseColor = XMFLOAT4{ 1.0f, 1.0f, 1.0f, 1.0f };
		material.Metallic = materialStatus.m_Metallic;
		material.Roughness = materialStatus.m_Roughness;
		material.Specular = materialStatus.m_Specular;

		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::SUBSET, &material, sizeof(material));
	}

	//マトリクス設定
	{
		XMMATRIX view;
		XMFLOAT3 up{ 0.0f, 1.0f, 0.0f };
		view = XMMatrixLookAtLH(XMLoadFloat3(&m_Position),
								XMLoadFloat3(&m_Target),
								XMLoadFloat3(&up));

		XMMATRIX projection;
		float aspect = (float)renderManager->GetBackBufferWidth() / renderManager->GetBackBufferHeight();
		projection = XMMatrixPerspectiveFovLH(1.0f, aspect, 0.1f, 10000.0f);

		CAMERA_CONSTANT constant{};
		XMStoreFloat4x4(&constant.View, XMMatrixTranspose(view));
		XMStoreFloat4x4(&constant.Projection, XMMatrixTranspose(projection));
		constant.Position = { m_Position.x, m_Position.y, m_Position.z, 0.0f };

		constant.GrayScale = XMFLOAT4{ postEffect.m_GrayScale[0], postEffect.m_GrayScale[1], postEffect.m_GrayScale[2], postEffect.m_GrayScale[3] };
		constant.Sepia = XMFLOAT4{ postEffect.m_Sepia[0], postEffect.m_Sepia[1] , postEffect.m_Sepia[2] , postEffect.m_Sepia[3] };
		constant.ChromaticAberration = XMFLOAT4{ postEffect.m_ChromaticAberration[0],postEffect.m_ChromaticAberration[1] ,postEffect.m_ChromaticAberration[2] ,postEffect.m_ChromaticAberration[3] };
		constant.Distorsion = XMFLOAT2{ postEffect.m_Distorsion[0], postEffect.m_Distorsion[1]};
		constant.Gamma = postEffect.m_Gamma;

		constant.Time = m_Time;

		constant.isGrayScale = postEffect.isGrayScale;
		constant.isSepia = postEffect.isSepia;
		constant.isDistorsion = postEffect.isDistorsion;
		constant.isChromaticAberration = postEffect.isChromaticAberration;

		renderManager->SetConstant(RenderManager::CONSTANT_TYPE::CAMERA, &constant, sizeof(constant));	
	}

	renderManager->SetPipelineState("Geometry");
}


void Camera::SetCameraPosition(XMFLOAT3 cameraPosition)
{
	m_Position = cameraPosition;
}