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
	// at² + bt + c = 0

	CRTVector vCO = ray.getOrigin() - this->centerPosition;
	//float a = ray.getDirection().Dot(ray.getDirection());
	float a = 1;
	float b = 2.0f * vCO.Dot(ray.getDirection());
	
	float c = vCO.Dot(vCO) - this->radius * this->radius;
	float delta = b * b - (4.0f * a * c);

	 /*std::cout << "B: " << b << 
		" C: " << c << 
		" delta: " << delta << 
		" ray Direction x " << ray.getDirection().x << " y " << ray.getDirection().y << " z " << ray.getDirection().z <<
		" vCO x " << vCO.x << " y " << vCO.y << " z " << vCO.z <<
		std::endl;*/

	if (delta < 0) {
		return INFINITY;
	}

	float distance = (-b - sqrt(delta)) / (2.0f * a);
	//std::cout << "Distance " << distance << std::endl;
	return distance;
	//return distance < EPSILON ? INFINITE : distance;
}

CRTVector Sphere::getPosition() const{
	return this->centerPosition;
}