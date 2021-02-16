#include "Vector.h"
#include <math.h>

Vector::Vector(double _x,double _y,double _z)
	:x(_x),y(_y),z(_z)
{
}

Vector::~Vector()
{
}

Vector Vector::operator + (const Vector &v) const
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator - (const Vector &v) const
{
	return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator * (double factor) const
{
	return Vector(x * factor, y * factor, z * factor);
}

double Vector::dot(const Vector &v) const
{
	return x * v.x + y * v.y + z * v.z;
}

double Vector::norm() const
{
	return sqrt(x*x+y*y+z*z);
}

Vector Vector::cross(const Vector &v) const
{
	double x = y*v.getZ() - z*v.getY();
	double y = z*v.getX() - x*v.getZ();
	double z = x*v.getY() - y*v.getX();
	return Vector(x, y, z);
}

void Vector::normalize()
{
	double theNorm = norm();
	if (theNorm != 0) {
		x /= theNorm;
		y /= theNorm;
		z /= theNorm;
	}
}

double Vector::getX() const
{
	return x;
}

double Vector::getY() const
{
	return y;
}

double Vector::getZ() const
{
	return z;
}