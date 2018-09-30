//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// test_point.cpp
//
#include <cassert>
#include <iostream>
#include "point.h"
#include "test_point.h"

test_point::test_point()
{
    std::cerr << "Tests for point:" << std::endl;
}

bool test_point::distance_to()
{
    std::cerr << "test point distance_to: ";

    point p1(0, 0);
    point p2(0, 1);
    double result = 1;
    assert(abs(p1.distance_to(p2) - result) < precision);
    p2.x = 0, p2.y = 0;
    result = 0;
    assert(abs(p1.distance_to(p2) - result) < precision);
    p1.x = 2, p1.y = 4;
    p2.x = 3, p2.y = 5;
    result = sqrt(2);
    assert(abs(p1.distance_to(p2) - result) < precision);
    p1.x = 0, p1.y = 3;
    p2.x = 4, p2.y = 2;
    result = sqrt(17);
    assert(abs(p1.distance_to(p2) - result) < precision);

    std::cerr << "OK" << std::endl;
    return true;
}

test_point::~test_point()
{
    std::cerr << "All tests for point have been passed!" << std::endl;
}

bool test_point::run()
{
    test_point test;
    return test.distance_to();
}
