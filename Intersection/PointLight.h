#pragma once

#include "Light.h"

class PointLight : public Light
{
public:
	PointLight(CRTVector position);
	~PointLight();

protected:
};

