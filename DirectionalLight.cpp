#include "DirectionalLight.h"


DirectionalLight::DirectionalLight(Vector _direction, Color _color)
	:Light(_color),direction(_direction)
{
}


DirectionalLight::~DirectionalLight()
{
}

Vector DirectionalLight::getDirection(const Vector target)
{
	return direction.normalize();
}