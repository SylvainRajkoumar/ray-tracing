#pragma once
#include "Vector3d.h"
class Ray
{
public:
	Ray(CRTVector direction, CRTVector origin);
	~Ray();
	CRTVector getDirection() const;
	CRTVector getOrigin() const;
	void setDirection(CRTVector newDirection);
protected:
	CRTVector direction;
	CRTVector origin;

};

