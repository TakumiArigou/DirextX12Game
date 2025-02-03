
#include "FadeManager.h"
#include "SceneManager.h"

FadeManager* FadeManager::m_Instance = nullptr;

FadeManager::FadeManager()
{
    m_Instance = this;

    m_Alpha = 1.0f;
	m_isFadeIN = false;
	m_isFadeOUT = false;

    m_isSceneChange = false;
}

FadeManager::~FadeManager()
{
}

void FadeManager::FadeIN()
{
	m_isFadeIN = true;
	m_isFadeOUT = false;
    m_Alpha = 0.0f;
}

void FadeManager::FadeOUT()
{
	m_isFadeIN = false;
	m_isFadeOUT = true;
    m_Alpha = 1.0f;
}

void FadeManager::Update()
{
    if (m_isFadeIN) {
        m_isSceneChange = false;

        m_Alpha += 0.1f; // フェードインの速度
        if (m_Alpha >= 1.0f) {
            m_Alpha = 1.0f;
            m_isFadeIN = false;
        }
    }

    else if (m_isFadeOUT) {
        m_Alpha -= 0.1f; // フェードアウトの速度
        if (m_Alpha <= 0.0f) {
            m_Alpha = 0.0f;
            m_isFadeOUT = false;

            SceneManager::GetInstance()->SetSceneType(m_SceneType);

            m_isSceneChange = true;
        }
    }
}

void FadeManager::Draw()
{
    RenderManager* renderManager = RenderManager::GetInstance();

    {
        ENV_CONSTANT constant;

        constant.LightDirection.x = 0.0f;
        constant.LightDirection.y = 1.0f;
        constant.LightDirection.z = 0.0f;

        constant.LightColor.x = 5.0f;
        constant.LightColor.y = 5.0f;
        constant.LightColor.z = 5.0f;
        constant.LightColor.w = m_Alpha;

        renderManager->SetConstant(RenderManager::CONSTANT_TYPE::ENV, &constant, sizeof(constant));
    }
}

float FadeManager::GetAlpha() const
{
    return m_Alpha;
}

bool FadeManager::IsFadeOUT() const
{
    return m_isFadeOUT;
}

bool FadeManager::IsFadeIN() const
{
    return m_isFadeIN;
}

bool FadeManager::GetIsScneChange() const
{
    return m_isSceneChange;
}

void FadeManager::SetSceneType(SceneType scenetype)
{
    m_SceneType = scenetype;
}
