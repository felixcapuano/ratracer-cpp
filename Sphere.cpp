#include "Sphere.h"
#include "math.h"
#include <iostream>

Sphere::Sphere(const Vector &_center,double _radius)
	:Object(),center(_center),radius(_radius)
{
}

Sphere::~Sphere()
{
}

double Sphere::intersectionDistance(const Ray &ray) 
{
	Vector origin = ray.getOrigin();
	Vector direction = ray.getDirection();

    Vector pxl_to_center = direction - center;

	double a = origin.dot(origin);
	double b = 2 * origin.dot(pxl_to_center);
	double c = pxl_to_center.dot(pxl_to_center) - radius*radius;

	double det = b*b - 4*a*c; //caclule du determinant

    double r = 0.0;

    if(det == 0) { //il y a 1 solution
        r = (-1*b) / (2*a);
    } else if(det > 0){ //il y a 2 solutions
        double r1 = (- b + sqrt(det)) / (2 * a);
        double r2 = (- b - sqrt(det)) / (2 * a);

        //on prend la plus petite des deux solutions
		r  = r1 < r2 ? r1 : r2;
    } else { //il n'y a pas de solution dans le domaine reel
        r = 0.0;
    }

    return r;
}

Vector Sphere::getNormAt(const Vector point)
{
    return (point - center).normalize();
}