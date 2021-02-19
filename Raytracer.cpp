// Raytracer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Scene.h"
#include "Sphere.h"
#include "Camera.h"
#include "DirectionalLight.h"
#include "PointLight.h"

int main()
{
	// CAMERA => TODO improve up vector
	struct Screen screen = {500, 500, 1};
	Vector pos(0,0,10);
	Vector target(0,0,-1);
	Vector upv(1,0,0);
	Camera * camera = new Camera(pos, target, upv, screen);

	// SCENE
	Scene scene(camera);

	// OBJECT
	Sphere *sphereRed = new Sphere(Vector(0,0,0),0.1);
	sphereRed->setColor(Color(1,0,0));
	scene.addObject(sphereRed);

	Sphere *sphereGreen = new Sphere(Vector(-0.15,0,0),0.1);
	sphereGreen->setColor(Color(0,1,0));
	scene.addObject(sphereGreen);

	Sphere *sphereBlue = new Sphere(Vector(-0.075,0.15,0),0.1);
	sphereBlue->setColor(Color(0,0,1));
	scene.addObject(sphereBlue);

	// LIGHTING
	DirectionalLight *dirLight = new DirectionalLight(Vector(1,-1,0), Color(1,1,1));
	scene.addLight(dirLight);

	PointLight *pointLight1 = new PointLight(Vector(2,0,0.5), Color(1,1,1));
	scene.addLight(pointLight1);

	PointLight *pointLight2 = new PointLight(Vector(0,-2,0.5), Color(1,1,1));
	scene.addLight(pointLight2);

	scene.render("test.bmp");

	return 0;
}
