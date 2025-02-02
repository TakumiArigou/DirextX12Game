#pragma once

#include "SceneBase.h"
#include "ResultScore.h"
#include "ResultTime.h"


class ResultManager : public SceneBase
{
private:

	Camera			m_Camera;
	Player			m_Plyaer;
	ResultScore		m_ResultScore;
	ResultTime		m_ResultTime;

public:
	ResultManager();
	~ResultManager() override;



	void Update() override;
	void Draw() override;


};

