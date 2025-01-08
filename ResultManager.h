#pragma once

#include "SceneBase.h"


class ResultManager : public SceneBase
{
private:

	Camera			m_Camera;
	Player			m_Plyaer;

public:
	ResultManager();
	~ResultManager() override;



	void Update() override;
	void Draw() override;


};

