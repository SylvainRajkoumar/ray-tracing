#pragma once

#include "Ray.h"
#include "Color.h"

class Mesh
{
public:
	Mesh(CRTColor color);
	~Mesh();
	virtual float getNearestIntersectionDistance(const Ray& ray) = 0;
	CRTColor getColor() const;
	virtual CRTVector getPosition() const = 0;
	virtual CRTVector getNormal(CRTVector meshIntersection) const = 0;
protected:
	CRTColor color;
	//float reflexion;
	//float refractiveIndex;

};

