#include "Scene.h"
#include "Bmpfile.h"
#include "macros.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::rayTrace(std::string filename, int width, int heigth) {
	unsigned char *buffer = new unsigned char[width * heigth * 3];

	CRTVector origin(0, 0, 0);
	CRTVector direction(.0f, .0f, 1);
	Ray ray(direction, origin);

	float fov = 90;
	float ratio = width / heigth;
	float scale = tan(fov / 2 * 3.14 / 180);

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < heigth; y++) {
			float px = (2 * (x + 0.5) / width - 1) * ratio * scale;
			float py = (1 - 2 * (y + 0.5) / heigth) * scale;
			direction = CRTVector(px, py, 1);
			direction.Normalize();
			ray.setDirection(direction);
			int meshIndex;
			float meshDistance = INFINITY;

			for (int i = 0; i < this->meshes.size(); i++) {
				float distance = this->meshes[i]->getNearestIntersectionDistance(ray);
				if (distance < meshDistance) {
					meshDistance = distance;
					meshIndex = i;
				}
			}
			
			CRTColor meshColor = CRTColor();
			CRTVector meshIntersection;
			if (meshDistance < INFINITY) {
				meshColor = this->meshes[meshIndex]->getColor();
				meshIntersection = origin + direction * meshDistance;
				
				CRTVector normal = (meshIntersection - this->meshes[meshIndex]->getPosition());
				normal.Normalize();
				CRTVector intersectionToLight = this->lights[0]->getPosition() - meshIntersection;
				intersectionToLight.Normalize();
				float test = normal.Dot(intersectionToLight);
				test = test < 0 ? 0.0f : test;
				meshColor.m_fB *= test;
				meshColor.m_fG *= test;
				meshColor.m_fR *= test;
			}

			buffer[3 * (width * y + x) + BLUE_INDEX] = (unsigned char)(255.0 * meshColor.m_fB);
			buffer[3 * (width * y + x) + GREEN_INDEX] = (unsigned char)(255.0 * meshColor.m_fG);
			buffer[3 * (width * y + x) + RED_INDEX] = (unsigned char)(255.0 * meshColor.m_fR);
		}
	}
	BMPFile::SaveBmp(filename, buffer, width, heigth);
}

void Scene::addLight(Light* light) {
	this->lights.push_back(light);
}

void Scene::addMesh(Mesh* mesh) {
	this->meshes.push_back(mesh);
}