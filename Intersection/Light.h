#pragma once

#include <stdint.h>
#include "Vector3d.h"

class Light
{
public:
	Light(CRTVector position);
	~Light();
	CRTVector getPosition() const;
	CRTVector getLVector(CRTVector meshIntersection) const;
protected:
	uint8_t luminance;
	CRTVector position;
};

