#pragma once
#include "point.h"
#include "polygon.h"

class regular_polygon : public polygon
{
public:
    regular_polygon(size_t points_count, double side_length, const point &center);

    double incircle() const;
    double outcircle() const;
};