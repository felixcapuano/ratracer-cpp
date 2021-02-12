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
	// a = ray.origin**2
	// b = 2 * ( ray.origin * (ray.direction * center ))
	// c = ((ray.direction - center)**2) - radius**2
	// TODO
	return 0;
}
