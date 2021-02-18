#include "Camera.h"

#include "Vector.h"
#include "Ray.h"


Camera::Camera(const Vector& _p, const Vector& _t, const Vector& _u, const Screen& _s)
    :pos(_p), screen(_s), target(_t), up(_u)
{
    Vector r = target.cross(up);
    Vector u = target.cross(r);

    target.normalize();
    u.normalize();
    r.normalize();

    up = u;
    right = r;
}

Camera::~Camera()
{
}

#include <iostream>
Ray Camera::getRay(const int x, const int y) const
{
    Vector dir;
    double xRate = (x / double(screen.width)) - 0.5;
    double yRate = (y / double(screen.height)) - 0.5;

    double aspecRatio = double(screen.width) / double(screen.height);

    dir = (target - up*yRate + right*xRate*aspecRatio)*screen.distance;

    return Ray(pos, dir);
}