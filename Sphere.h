#pragma once
#include "Object.h"

#include "Vector.h"

class Sphere :
	public Object
{
public:
	Sphere(const Vector &_center, double _radius);
	~Sphere();
	double intersectionDistance(const Ray &ray);
	Vector getNormAt(const Vector point);
protected:
	Vector center;
	double radius;
};
