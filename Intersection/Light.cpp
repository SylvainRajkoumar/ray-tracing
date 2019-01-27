#include "Light.h"



Light::Light(CRTVector position):
	position(position)
{
}


Light::~Light()
{
}

CRTVector Light::getPosition() const {
	return this->position;
}
