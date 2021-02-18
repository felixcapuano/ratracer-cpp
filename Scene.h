#pragma once

#include <string>
#include <vector>

#include "Camera.h"

class Object;
class Light;
class Camera;
class Color;
class Vector;
class Ray;

class Scene
{
public:
	Scene();
	~Scene();
	void addObject(Object *object);
	void addLight(Light *light);
	void render(std::string fileName);
	Color localIllumination(Vector impact, Object * impactObject);
	Object* findNearestObject(const Ray &ray, double &nearestDistance);
	Color raytrace(const Ray& ray);
protected:
	std::vector<Object*> objects;
	std::vector<Light*> lights;
	Camera* camera;
	struct Screen s;
};
