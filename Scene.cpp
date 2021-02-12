#include "Scene.h"
#include "Bmpfile.h"
#include "Object.h"
#include "Light.h"

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
