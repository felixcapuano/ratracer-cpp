#include "Sphere.h"
#include "math.h"

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

	double a = origin.dot(origin);
	double b = 2 * origin.dot(center.dot(direction));
	double c = (direction-center).dot(direction-center) - radius*radius;

	double det = b*b - 4*a*c; //caclule du determinant

    double r = 0.0;

    if(det == 0) { //il y a 1 solution
        r = (-1*b) / (2*a);
    } else if(det > 0){ //il y a 2 solutions
        double r1 = ((-1*b) + sqrt(det)) / (2*a);
        double r2 = ((-1*b) - sqrt(det)) / (2*a);

        //on prend la plus petite des deux solutions
		r  = r1 < r2 ? r1 : r2;
    } else { //il n'y a pas de solution dans le domaine reel
        r = 0.0;
    }

    return r;
}
