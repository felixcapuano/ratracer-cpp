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
    return Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

Vector Vector::normalize()
{
	double theNorm = norm();
	if (theNorm != 0) {
		x /= theNorm;
		y /= theNorm;
		z /= theNorm;
	}
	return *this;
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

std::ostream &operator << (std::ostream &out, const Vector v){
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}


std::istream &operator >> (std::istream &in, Vector &v){
    in >> v.x >> v.y >> v.z;
    return in;
}
