#pragma once
class Vector
{
public:
	Vector(double _x=0, double _y=0, double _z=0);
	~Vector();

	Vector operator + (const Vector &v) const;
	Vector operator - (const Vector &v) const;
	Vector operator * (double factor) const;
	double dot(const Vector &v) const;
	double norm() const;
	Vector cross(const Vector &v) const;
	void normalize();
	double getX() const;
	double getY() const;
	double getZ() const;
protected:
	double x, y, z;
};
