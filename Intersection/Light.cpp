#include "Light.h"



Light::Light(CRTVector position):
	position(position)
{
}


Light::~Light()
{
}

CRTVector Light::getPosition() const 
{
	return this->position;
}

CRTVector Light::getLVector(CRTVector meshIntersection) const 
{
	CRTVector intersectionToLight = this->position - meshIntersection;
	intersectionToLight.Normalize();
	return intersectionToLight;
}