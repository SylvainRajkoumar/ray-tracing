#pragma once

#include <stdint.h>
#include "Vector3d.h"

class Light
{
public:
	Light(CRTVector position);
	~Light();
	CRTVector getPosition() const;
protected:
	uint8_t luminance;
	CRTVector position;
};

