#include "Ray.h"

Ray::Ray(CRTVector direction, CRTVector origin):
	direction(direction),
	origin(origin)
{
}

Ray::~Ray()
{
}


CRTVector Ray::getDirection() const 
{
	return this->direction;
}

CRTVector Ray::getOrigin() const 
{
	return this->origin;
}

void Ray::setDirection(CRTVector newDirection) 
{
	this->direction = newDirection;
}