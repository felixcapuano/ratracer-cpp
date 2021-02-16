#include "Camera.h"

#include "Ray.h"
#include "Vector.h"


Camera::Camera()
{
}

Camera::Camera(Ray _orientation, Screen _screen)
    :orientation(_orientation), screen(_screen)
{
    _computeRightVect();
    _computeDownVect();
}

Camera::~Camera()
{
}

Ray Camera::getRay(const int x, const int y) const
{
    Vector dir;
    double xRate = x / screen.width - 0.5;
    double yRate = y / screen.height - 0.5;

    Vector dist = orientation.getDirection().norm();

    dir = dist*screen.distance + downVect*yRate + rightVect*xRate;

    return Ray(orientation.getOrigin(), dir);

}

void Camera::_computeDownVect()
{
    downVect = rightVect.cross(orientation.getOrigin()) * -1;
    downVect.normalize();
}

void Camera::_computeRightVect()
{
    Vector d = orientation.getDirection();
    Vector o = orientation.getOrigin();


    if(d.getY() != o.getY())
    {
        float a = (o.getX() - d.getX())/(d.getY() - o.getY());
        rightVect = Vector(1, a, 0);
    } else if(d.getX() != o.getX()){
        float a = (d.getY() - o.getY())/(o.getX() - d.getX());
        rightVect = Vector(a, 1, 0);
    }
    /// Probleme here
    rightVect.normalize();
}