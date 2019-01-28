#include <iostream>
#include "Sphere.h"
#include "Ray.h"
#include "Vector3d.h"
#include "Scene.h"
#include "PointLight.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>


int main() {
	srand(time(NULL));
	// at² + bt + c = 0 
	// Delta = b² - 4ac
	// Solutions = (-b +- sqrt(Delta))/2*a

	// (X - Xc)² + (Y - Yc)²  = R² (cercle)
	// x = t*dirx + xo
	// y = t*dirx + xo

	Scene scene;
	scene.addMesh(new Sphere(CRTVector(175, 0, 300), 150, CRTColor(.0f, .0f, 1.f)));
	scene.addMesh(new Sphere(CRTVector(0, 175, 400), 150, CRTColor(.0f, 1.f, .0f)));
	scene.addMesh(new Sphere(CRTVector(0, 0, 500), 150, CRTColor(1.f, 1.f, .0f)));
	scene.addMesh(new Sphere(CRTVector(-175, -175, 600), 150, CRTColor(1.f, .0f, .0f)));

	scene.addLight(new PointLight(CRTVector(300, 300, 0)));
	scene.addLight(new PointLight(CRTVector(-300, -300, 0)));

	clock_t begin = clock();

	scene.rayTrace("result.bmp", 900, 900);

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
	system("PAUSE");
	return 0;
}