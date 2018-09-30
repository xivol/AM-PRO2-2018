//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// test_polygon.cpp
//
#include "polygon.h"
#include "test_polygon.h"

test_polygon::test_polygon()
{
    std::cerr << "Tests for polygon:" << std::endl;
}

test_polygon::~test_polygon()
{
    std::cerr << "All tests for polygon have been passed!" << std::endl;
}

point * test_polygon::get_points(const size_t length)
{
    point *points = new point[length];
    for (int i = 0; i < length; ++i) {
        points[i] = point(rand(), rand());
    }
    return points;
}

bool test_polygon::copy()
{
    std::cerr << "copy: ";
    size_t n = 15;
    point *points = get_points(n);
    point *result = new point[n];
    
    polygon t;
    t.copy(points, result, n);

    for (int i = 0; i < n; ++i) {
        assert(points[i] == result[i]);
    }

    delete [] points;
    delete [] result;

    std::cerr << "OK" << std::endl;
    return true;
}

bool test_polygon::points_ctor()
{
    std::cerr << "constructor: ";

    size_t n = 16;
    point *points = get_points(n);

    polygon t(points, n);

    assert(t.size == n);
    for (int i = 0; i < n; i++) {
        assert(t.points[i] == points[i]);
    }

    std::cerr << "OK" << std::endl;
    return true;
}

bool test_polygon::run()
{
#ifdef _DEBUG
    test_polygon test;
    return test.copy() && test.points_ctor();
#elif
    return true;
#endif
}
