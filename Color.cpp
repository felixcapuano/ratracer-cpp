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

Color Color::operator * (const float k){
    return Color(r * k, g * k, b * k);
}


Color Color::operator * (const Color c){
    return Color(r * c.r, g * c.g, b * c.b);
}

Color Color::operator + (const Color c){
    return Color(r + c.r, g + c.g, b + c.b);
}

Color Color::operator = (const Color c){
    r = c.r;
    g = c.g;
    b = c.b;
	// alpha
    //a = c.a;

    return *this;
}

Color Color::operator *= (const Color c){
    r *= c.r;
    g *= c.g;
    b *= c.b;

    return *this;
}

Color Color::operator *= (const float k){
    r *= k;
    g *= k;
    b *= k;

    return *this;
}

Color Color::operator += (const Color c){
    r += c.r;
    g += c.g;
    b += c.b;

    return *this;
}

std::ostream &operator << (std::ostream &out, const Color c){
    out << "(" << c.r << ", " << c.g << ", " << c.b << ")";
    return out;
}


std::istream &operator >> (std::istream &in, Color &c){
    in >> c.r >> c.g >> c.b;
    return in;
}

Color Color::cap(){
    if(r > 1){
        r = 1;
    }
    if(g > 1){
        g = 1;
    }
    if(b > 1){
        b = 1;
    }

    return *this;
}
