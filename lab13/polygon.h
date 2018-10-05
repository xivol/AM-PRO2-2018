﻿//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// polygon.h
//
#pragma once
#include "point.h"

class test_polygon;

class polygon
{
protected:
    // масив точек
    point *points;
    // длина массива
    size_t size;

    // Вспомогательная функция копирования массива точек
    void copy(const point *from, point *to, const size_t size);

    // Закрытый конструктор без параметров
    // может быть использован в дружественных классах и функциях
    polygon();
public:
    // Конструктор от массива точек
    polygon(const point *points, const size_t size);

    // Деструктор
    ~polygon();   

    friend class test_polygon;
};