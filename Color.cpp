#include "Color.h"

Color::Color(double _r, double _g, double _b)
	:r(_r),g(_g),b(_b)
{
}

Color::~Color()
{
}

Color Color::operator + (const Color &color) const
{
	return Color(r + color.r, g + color.g, b + color.b);
}

double Color::getBlue() const
{
	return b;
}

double Color::getGreen() const
{
	return g;
}

double Color::getRed() const
{
	return r;
}

std::ostream &operator << (std::ostream &out, const Color c){
    out << "(" << c.r << ", " << c.g << ", " << c.b << ")";
    return out;
}


std::istream &operator >> (std::istream &in, Color &c){
    in >> c.r >> c.g >> c.b;
    return in;
}
