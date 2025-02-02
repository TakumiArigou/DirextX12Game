#pragma once

#include "SceneBase.h"
#include "TitleObject.h"
#include "TitleBack.h"
#include "TitleLogo.h"

class TitleManager : public SceneBase
{
private:

	Camera			m_Camera;
	TitleObject		m_TitleObject;
	TitleBack		m_TitleBack;
	TitleLogo		m_TitleLogo;

public:

	TitleManager();
	~TitleManager() override;



	void Update() override;
	void Draw() override;


};

