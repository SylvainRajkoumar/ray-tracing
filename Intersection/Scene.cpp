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

void Scene::computeMeshesNearestIntersectionDistance(const Ray& ray, float& meshDistance, int& meshIndex) {
	for (int i = 0; i < this->meshes.size(); i++) {
		float distance = this->meshes[i]->getNearestIntersectionDistance(ray);
		if (distance < meshDistance) {
			meshDistance = distance;
			meshIndex = i;
		}
	}
}


void Scene::rayTrace(std::string filename, int width, int heigth) {
	unsigned char *buffer = new unsigned char[width * heigth * 3];

	CRTVector origin(0, 0, 0);
	CRTVector direction(.0f, .0f, 1);
	Ray ray(direction, origin);

	float fov = 90;
	float ratio = (float)width / (float)heigth;
	float scale = (float)(fov / 2 * 3.14 / 180);

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < heigth; y++) {
			float px = (2 * (x + 0.5) / width - 1) * ratio * scale;
			float py = (1 - 2 * (y + 0.5) / heigth) * scale;
			direction = CRTVector(px, py, 1);
			direction.Normalize();
			ray.setDirection(direction);

			int meshIndex;
			float meshDistance = INFINITY;
			this->computeMeshesNearestIntersectionDistance(ray, meshDistance, meshIndex);

			CRTColor meshColor = CRTColor();
			CRTVector meshIntersection;

			if (meshDistance < INFINITY) {
				meshColor = this->meshes[meshIndex]->getColor();
				meshIntersection = origin + direction * meshDistance; // Coordonnées du point d'intersection
				
				// Calcul du vecteur normal à la surface de la sphère à l'endroit de l'intersection
				CRTVector normal = this->meshes[meshIndex]->getNormal(meshIntersection);
				float dotNormalSum = 0;
				for (int i = 0; i < this->lights.size(); i++) {
					CRTVector intersectionToLight = this->lights[i]->getLVector(meshIntersection);
					// Calcul du produit scalaire permettant de déterminé à quel point le point d'intersection est exposé à la
					// source lumineuse
					float dotNormal = normal.Dot(intersectionToLight); // N . L - Lambert
					dotNormal = dotNormal < 0 ? 0.0f : dotNormal; // Si négatif, la face n'est pas exposée à la source lumineuse
					dotNormalSum += dotNormal;

					if (dotNormal > 0) {
						int meshIndex;
						float meshDistance = INFINITY;
						Ray ray(intersectionToLight, meshIntersection + (intersectionToLight * 0.01f));
						this->computeMeshesNearestIntersectionDistance(ray, meshDistance, meshIndex);
						if (meshDistance < INFINITY) {
							meshColor *= 0.5f;
						}
					}
				}
				meshColor *= dotNormalSum;
			}
			if (meshColor.m_fB > 1.0f) meshColor.m_fB = 1.0f;
			if (meshColor.m_fG > 1.0f) meshColor.m_fG = 1.0f;
			if (meshColor.m_fR > 1.0f) meshColor.m_fR = 1.0f;
			buffer[3 * (width * y + x) + BLUE_INDEX] = (unsigned char)(255.0 * meshColor.m_fB);
			buffer[3 * (width * y + x) + GREEN_INDEX] = (unsigned char)(255.0 * meshColor.m_fG);
			buffer[3 * (width * y + x) + RED_INDEX] = (unsigned char)(255.0 * meshColor.m_fR);
		}
	}
	BMPFile::SaveBmp(filename, buffer, width, heigth);
	delete buffer;
}

void Scene::addLight(Light* light) {
	this->lights.push_back(light);
}

void Scene::addMesh(Mesh* mesh) {
	this->meshes.push_back(mesh);
}