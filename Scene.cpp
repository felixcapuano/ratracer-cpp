#include "Scene.h"
#include "Bmpfile.h"
#include "Object.h"
#include "Light.h"
#include "Vector.h"
#include "Color.h"
#include "Ray.h"

Scene::Scene()
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

void Scene::render(std::string fileName, unsigned int width, unsigned int height)
{
	unsigned char *buffer = new unsigned char[width*height*3];
	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			unsigned int index = (y * width + x) * 3;
			buffer[index]=255; // blue
			buffer[index+1] = 0; // green
			buffer[index+2] = 0; // red
		}
	}
	BMPFile::SaveBmp(fileName, buffer, width, height);
	delete buffer;
}

Color Scene::raytrace(const Ray& ray)
{
	Color color;

	// appeler intersectionDistance pour chaque objet
	// determiner la distance la plus proche et l'objet associé
	double nearestDistance;
	Object *impactedObject = findNearestObject(ray, nearestDistance);

	// à partir de la distance, calculer le point d'impact
	Vector impact = ray.getOrigin() + ray.getDirection() * distance;

	//color = color + localIllumination(???)
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

Objet Scene::findNearestObject(const Ray &ray, double &nearestDistance)
{
	Object *nearestObject;
	for (Object *Object : objects) {

	}
	return nearestObject;
}