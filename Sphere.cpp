#include "Sphere.h"

Sphere::Sphere(const Vector &_center,double _radius)
	:Object(),center(_center),radius(_radius)
{
}

Sphere::~Sphere()
{
}

double Sphere::intersectionDistance(const Ray &ray) 
{
	// TODO
	return 0;
}
