#include <cmath>
#include <exception>
#include <iostream>
#include "point.h"

using namespace std;

point::point() : x(0.0), y(0.0)
{
    //cout << "Создана точка (0,0)" << endl;
}

point::point(double x, double y)
{
    this->x = x;
    this->y = y;
    //cout << "Создана точка ( " << x << " , " << y << " )" << endl;
}

double point::distance_to(const point &target) const
{
    return sqrt((x - target.x)*(x - target.x) + (y - target.y)*(y - target.y));
}

double point::get_x() const
{
    return x;
}

double point::get_y() const
{
    return y;
}

point get_point()
{
    double x, y;
    std::cin >> x >> y;
    if (!std::cin)
        throw std::domain_error("Некорректные координаты точки");
    return point(x, y);
}

void print(const point & p)
{
    std::cout << "(" << p.get_x() << ", " << p.get_y() << ")";
}

std::ostream &operator<<(std::ostream &os, const point &p)
{
    os << "( " << p.get_x() << ", " << p.get_y() << " )";
    return os;
}

std::istream &operator>>(std::istream &is, point &p)
{
    is >> p.x >> p.y;
    return is;
}
