// Raytracer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Scene.h"
#include "Sphere.h"
#include "Camera.h"

int main()
{
	struct Screen screen = {1000, 1000, 1};
	Vector pos(6,0,0);
	Vector target(-1,0,0);
	Vector upv(0,0,1);
	Camera * camera = new Camera(pos, target, upv, screen);

	Scene scene(camera);

	Sphere *sphere = new Sphere(Vector(0,0.2,0),0.2);
	sphere->setColor(Color(1,0,0));
	scene.addObject(sphere);

	Sphere *sphere2 = new Sphere(Vector(0,-0.2,0),0.2);
	sphere2->setColor(Color(0,1,0));
	scene.addObject(sphere2);

	//scene.render("test.bmp",1024,768);
	scene.render("test.bmp");

	return 0;
}
