// Picture.h

#pragma once

#include "MovingGameObject.h"

class Picture : public GameObject{
public:
	Picture();
	~Picture();

	bool Update();

	bool GetType(){};
private:
	float m_duration;
};