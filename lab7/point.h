//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// point.h
//
#pragma once
#include <cassert>
#include <iostream>
#include <fstream>

const double precision = 1E-10;

class test_point;

class point
{
private:
    double x, y;
public:
    point();
    point(double x, double y);

    double get_x() const;
    double get_y() const;

    double distance_to(const point &target) const;

    friend class test_point;
    friend std::istream &operator>>(std::istream &is, point &p);
};

point get_point();
void print(const point &p);
std::ostream &operator<<(std::ostream &os, const point &p);

