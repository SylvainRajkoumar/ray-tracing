#include "Sphere.h"
#include "macros.h"
#include <algorithm>
#include <iostream>

Sphere::Sphere(CRTVector centerPosition, float radius, CRTColor color) : 
	Mesh(color),
	centerPosition(centerPosition),
	radius(radius)
{
}

Sphere::~Sphere()
{
}

float Sphere::getNearestIntersectionDistance(const Ray& ray) {

	CRTVector vCO = ray.getOrigin() - this->centerPosition;

	float a = 1;
	float b = 2.0f * vCO.Dot(ray.getDirection());
	float c = vCO.Dot(vCO) - this->radius * this->radius;
	float delta = b * b - (4.0f * a * c);

	if (delta < 0) {
		return INFINITY;
	}

	float distance = (-b - sqrt(delta)) / (2.0f * a);
	if (distance < 0) {
		return INFINITY;
	}
	return distance;
}

CRTVector Sphere::getPosition() const{
	return this->centerPosition;
}

CRTVector Sphere::getNormal(CRTVector meshIntersection) const {
	CRTVector normal = meshIntersection - this->centerPosition;
	normal.Normalize();
	return normal;
}