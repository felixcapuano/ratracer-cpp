#pragma once

#include "Light.h"
#include "Vector.h"
#include "Color.h"

class DirectionalLight :
	public Light
{
public:
	DirectionalLight(Vector _direction, Color _color);
	~DirectionalLight();
	Vector getDirection(const Vector target);
protected:
	Vector direction;
};
