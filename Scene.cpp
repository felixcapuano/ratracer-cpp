#include "Scene.h"
#include "Bmpfile.h"
#include "Object.h"
#include "Light.h"
#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Camera.h"

// test
#include <iostream>
#include <cmath>


Scene::Scene(Camera* _camera)
	:camera(_camera)
{
}

Scene::~Scene()
{
	/*
	// old way
	for (unsigned int i = 0; i < objects.size(); i++) {
		delete objects[i];
	}
	*/
	// C++ 11
	delete camera;
	for (Object *object: objects) {
		delete object;
	}
	for (Light *light : lights) {
		delete light;
	}
}

void Scene::addObject(Object *object)
{
	objects.push_back(object);
}

void Scene::addLight(Light *light)
{
	lights.push_back(light);
}

void Scene::render(std::string fileName)
{
	struct Screen s = camera->getScreen();
	unsigned char *buffer = new unsigned char[s.width*s.height*3];
	for (unsigned int y = 0; y < s.height; y++) {
		for (unsigned int x = 0; x < s.width; x++) {

			Ray ray = camera->getRay(x, y);

			Color c = raytrace(ray);

			unsigned int index = (y * s.width + x) * 3;
			buffer[index] = int(255*c.getBlue()); // blue
			buffer[index+1] = int(255*c.getGreen()); // green
			buffer[index+2] = int(255*c.getRed()); // red
		}
	}
	BMPFile::SaveBmp(fileName, buffer, s.width, s.height);
	delete buffer;
}

Color Scene::raytrace(const Ray& ray)
{
	Color color(0,0,0);

	// appeler intersectionDistance pour chaque objet
	// determiner la distance la plus proche et l'objet associé
	double nearestDistance;
	Object *impactedObject = findNearestObject(ray, nearestDistance);

	// à partir de la distance, calculer le point d'impact
	if (nearestDistance > 0) {
		Vector impact = ray.getOrigin() + ray.getDirection() * nearestDistance;

		color = localIllumination(impact, impactedObject);
	}
	//reflect : color = color + raytrace(???)
	//refract : color = color + raytrace(???)

	return color;
}

Color Scene::localIllumination(Vector impact, Object * impactObject)
{
	Color color;
	color = impactObject->getColor();
	return color;
}


Object *Scene::findNearestObject(const Ray &ray, double &nearestDistance)
{
	Object *nearestObject;
	double distance;
	double min = INFINITY;
	for (Object *object : this->objects) {
		// get nearest object
		distance = object->intersectionDistance(ray);

		if (distance < min && distance > 0) {
			min = distance;
			nearestObject = object;
		}
	}
	nearestDistance = min == INFINITY ? 0 : min;

	return nearestObject;
}