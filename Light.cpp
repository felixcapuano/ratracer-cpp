#include "Light.h"
#include "Vector.h"
#include "Color.h"

Light::Light(Color _lightColor)
    :lightColor(_lightColor)
{
}


Light::~Light()
{
}

Color Light::getColor() const
{
    return lightColor;
}