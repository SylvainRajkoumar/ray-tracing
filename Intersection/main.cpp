#include <iostream>
#include "Sphere.h"
#include "Ray.h"
#include "Vector3d.h"
#include "Scene.h"
#include "PointLight.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>


int main() 
{
	srand(time(NULL));
	// at² + bt + c = 0 
	// Delta = b² - 4ac
	// Solutions = (-b +- sqrt(Delta))/2*a

	// (X - Xc)² + (Y - Yc)²  = R² (cercle)
	// x = t*dirx + xo
	// y = t*dirx + xo

	Scene scene;
	scene.addMesh(new Sphere(CRTVector(0, 0, 300), 50, CRTColor(.0f, .0f, 1.f)));
	scene.addMesh(new Sphere(CRTVector(40, 40, 250), 10, CRTColor(0.5f, 0.5f, 0.5f)));
	scene.addMesh(new Sphere(CRTVector(-50, 20, 250), 10, CRTColor(0.5f, 0.5f, 0.5f)));
	//scene.addMesh(new Sphere(CRTVector(0, 0, 500), 100, CRTColor(1.f, 1.f, .0f)));
	//scene.addMesh(new Sphere(CRTVector(-175, -175, 600), 100, CRTColor(1.f, .0f, .0f)));

	scene.addLight(new PointLight(CRTVector(100, 150, 200)));
	scene.addLight(new PointLight(CRTVector(-100, 150, 200)));

	clock_t begin = clock();

	scene.rayTrace("result.bmp", 900, 900);

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
	system("PAUSE");
	return 0;
}