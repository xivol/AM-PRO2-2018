#pragma once
#include "point.h"
#include "polygon.h"

class star : public polygon
{
public:
    star(size_t points_count, double inradius, double outradius, const point &center);

    double incircle() const;
    double outcircle() const;
};