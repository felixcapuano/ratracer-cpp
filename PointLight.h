#pragma once

#include "Light.h"
#include "Vector.h"
#include "Color.h"

class PointLight :
    public Light
{
public:
    PointLight(Vector _position, Color _color);
    ~PointLight();

    Vector getDirection(const Vector target);
protected:
    Vector position;
};
