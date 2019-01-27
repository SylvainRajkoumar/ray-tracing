#include <iostream>
#include "Sphere.h"
#include "Ray.h"
#include "Vector3d.h"
#include "Scene.h"
#include "PointLight.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main() {
	srand(time(NULL));
	// at² + bt + c = 0 
	// Delta = b² - 4ac
	// Solutions = (-b +- sqrt(Delta))/2*a

	// (X - Xc)² + (Y - Yc)²  = R² (cercle)
	// x = t*dirx + xo
	// y = t*dirx + xo

	Scene scene;
	scene.addMesh(new Sphere(CRTVector(100, 100, 200), 50, CRTColor(.0f, .0f, 1.f)));
	scene.addMesh(new Sphere(CRTVector(100, 100, 300), 50, CRTColor(.0f, 1.f, .0f)));
	scene.addMesh(new Sphere(CRTVector(100, 100, 400), 50, CRTColor(1.f, 1.f, .0f)));
	scene.addMesh(new Sphere(CRTVector(100, 100, 500), 50, CRTColor(1.f, .0f, .0f)));

	scene.addMesh(new Sphere(CRTVector(-100, -100, 200), 50, CRTColor(.0f, .0f, 1.f)));
	scene.addMesh(new Sphere(CRTVector(-100, -100, 300), 50, CRTColor(.0f, 1.f, .0f)));
	scene.addMesh(new Sphere(CRTVector(-100, -100, 400), 50, CRTColor(1.f, 1.f, .0f)));
	scene.addMesh(new Sphere(CRTVector(-100, -100, 500), 50, CRTColor(1.f, .0f, .0f)));


	scene.addLight(new PointLight(CRTVector(100, 200, 100)));
	scene.rayTrace("result.bmp", 800, 800);
	system("PAUSE");
	return 0;
}