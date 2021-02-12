#pragma once

#include <string>
#include <vector>

class Object;
class Light;

class Scene
{
public:
	Scene();
	~Scene();
	void addObject(Object *object);
	void addLight(Light *light);
	void render(std::string fileName,unsigned int width,unsigned int height);
protected:
	std::vector<Object*> objects;
	std::vector<Light*> lights;
};
