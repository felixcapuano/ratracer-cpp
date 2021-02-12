#include "Color.h"

Color::Color(double _r, double _g, double _b)
{
}

Color::~Color()
{
}

Color Color::operator + (const Color &color) const
{
	return Color(r + color.r, g + color.g, b + color.b);
}
