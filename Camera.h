class Ray;
class Vector;

struct Screen
{
    double height;
    double width;
    double distance;
};

class Camera
{
public:
    Camera();
    Camera(Ray _orientation, Screen _screen);
    ~Camera();
    Ray getRay(const int x, const int y) const;
protected:
    Ray orientation;
    Screen screen;
private:
    void _computeDownVect();
    void _computeRightVect();
    Vector downVect;
    Vector rightVect;
};
