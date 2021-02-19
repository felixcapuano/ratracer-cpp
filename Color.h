#pragma once

#include <iostream>

class Color
{
public:
	Color(double _r=0, double _g=0, double _b=0);
	~Color();

	Color operator + (const Color &color) const;

	double getBlue() const;
	double getGreen() const;
	double getRed() const;
	friend std::ostream &operator<<(std::ostream &out, const Color c);
	friend std::istream &operator>>(std::istream &in, Color &c);
protected:
	double r, g, b;
};
