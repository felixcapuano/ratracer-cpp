#pragma once

class Color
{
public:
	Color(double _r=0, double _g=0, double _b=0);
	~Color();

	Color operator + (const Color &color) const;

	double getBlue() const;
	double getGreen() const;
	double getRed() const;
protected:
	double r, g, b;
};
