
#include "FadeManager.h"

FadeManager* FadeManager::m_Instance = nullptr;

FadeManager::FadeManager()
{
    m_Instance = this;

	m_alpha = 0.0f;
	m_isFadeIN = false;
	m_isFadeOUT = false;
}

FadeManager::~FadeManager()
{
}

void FadeManager::FadeIN()
{
	m_isFadeIN = true;
	m_isFadeOUT = false;
	m_alpha = 0.0f;
}

void FadeManager::FadeOUT()
{
	m_isFadeIN = false;
	m_isFadeOUT = true;
	m_alpha = 1.0f;
}

void FadeManager::Update()
{
    if (m_isFadeIN) {
        m_alpha += 0.1f; // フェードインの速度
        if (m_alpha >= 1.0f) {
            m_alpha = 1.0f;
            m_isFadeIN = false;
        }
    }

    else if (m_isFadeOUT) {
        m_alpha -= 0.1f; // フェードアウトの速度
        if (m_alpha <= 0.0f) {
            m_alpha = 0.0f;
            m_isFadeOUT = false;
        }
    }
}

float FadeManager::GetAlpha() const
{
    return m_alpha;
}

bool FadeManager::IsFading() const
{
    return m_isFadeIN || m_isFadeOUT;
}