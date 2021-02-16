#include "Scene.h"
#include "Bmpfile.h"
#include "Object.h"
#include "Light.h"
#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Camera.h"

Scene::Scene()
{
	struct Screen screen = {768, 1024, 1};
	Ray dir = Ray(Vector(0,0,0), Vector(1,0,0));
	camera = Camera(dir, screen);
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

			Ray ray = camera.getRay(x, y);

			unsigned int index = (y * width + x) * 3;
			buffer[index]=255; // blue
			buffer[index+1] = 0; // green
			buffer[index+2] = 0; // red
		}
	}
	BMPFile::SaveBmp(fileName, buffer, width, height);
	delete buffer;
}

//Color Scene::raytrace(const Ray& ray)
//{
//	Color color;
//
//	// appeler intersectionDistance pour chaque objet
//	// determiner la distance la plus proche et l'objet associé
//	double nearestDistance;
//	Object *impactedObject = findNearestObject(ray, nearestDistance);
//
//	// à partir de la distance, calculer le point d'impact
//	Vector impact = ray.getOrigin() + ray.getDirection() * nearestDistance;
//
//	//color = color + localIllumination(???)
//	//reflect : color = color + raytrace(???)
//	//refract : color = color + raytrace(???)
//
//	return color;
//}
//
//Color Scene::localIllumination(Vector impact, Object * impactObject)
//{
//	Color color;
//	color = impactObject->getColor();
//	return color;
//}
//
//Object Scene::findNearestObject(const Ray &ray, double &nearestDistance)
//{
//	Object *nearestObject;
//	for (Object *object : this->objects) {
//		// get nearest object
//
//	}
//
//	return nearestObject;
//}