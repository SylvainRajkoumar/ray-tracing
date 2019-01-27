#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "Mesh.h"
#include "Light.h"
#include "Vector3d.h"


class Scene
{
public:
	Scene();
	~Scene();
	void rayTrace(std::string filename, int width, int heigth);
	void addLight(Light* light);
	void addMesh(Mesh* mesh);

protected:
	std::vector<Light*> lights;
	std::vector<Mesh*> meshes;
};

