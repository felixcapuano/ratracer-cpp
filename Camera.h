#pragma once

#include "Vector.h"

class Ray;

struct Screen
{
    unsigned int height;
    unsigned int width;
    double distance;
};

class Camera
{
public:
    Camera(const Vector& _pos, const Vector& _target, const Vector& _up, const Screen& _screen);
    ~Camera();
    Ray getRay(const int x, const int y) const;
protected:
    Vector pos;

    Vector target;
    Vector up;
    Vector right;

    Screen screen;

    double resolution;
};