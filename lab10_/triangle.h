#pragma once
#include "point.h"
#include "polygon.h"

class triangle : public polygon
{
public:
    triangle(const point &a, const point &b, const point &c);

    double incircle() const;
    double outcircle() const;
};
