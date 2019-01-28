#pragma once

#include "Mesh.h"
#include "Ray.h"
#include "Vector3d.h"
#include "Color.h"
#include <stdint.h>

class Sphere : public Mesh
{
public:
	Sphere(CRTVector centerPosition, float radius, CRTColor color);

	~Sphere();
	virtual float getNearestIntersectionDistance(const Ray& ray);
	virtual CRTVector getPosition() const;
	virtual CRTVector getNormal(CRTVector meshIntersection) const;
protected:
	CRTVector centerPosition;
	float radius;
};

