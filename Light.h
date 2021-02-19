#pragma once

class Vector;
#include "Color.h"

class Light{
    protected:
        Color lightColor;
    public:
        Light(Color _lightColor);
        ~Light();
        Color getColor() const;
        virtual Vector getDirection(const Vector target) = 0;
};

