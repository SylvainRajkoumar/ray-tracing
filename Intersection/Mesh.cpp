#include "Mesh.h"



Mesh::Mesh(CRTColor color) :
	color(color)
{
}


Mesh::~Mesh()
{
}

CRTColor Mesh::getColor() const 
{
	return this->color;
}
