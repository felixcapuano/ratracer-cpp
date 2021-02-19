#pragma once

#include "Color.h"
#include "Ray.h"
#include "Vector.h"

class Object
{
public:
	Object();
	~Object();

	void setColor(const Color &_color);
	const Color &getColor() const;

	virtual double intersectionDistance(const Ray &ray) { return 0;};
	virtual Vector getNormAt(const Vector point) = 0;
protected:
	Color color;
};
