#include "PointLight.h"

PointLight::PointLight(Vector _position, Color _color)
    :Light(_color),position(_position)
{
}

PointLight::~PointLight()
{
}

Vector PointLight::getDirection(const Vector target)
{
	return (target-position).normalize();
}
