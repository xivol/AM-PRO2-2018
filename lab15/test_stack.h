//
// Лабораторная работа №15. Абстрактные типы данных. Стек
// test_stack.h
//
#pragma once
#include "stack.h"

class test_stack
{
    // Тестируемый стек
    stack &st;

    // Очистка тестируемого стека
    void cleanup();
    
    // Тесты методов стека
    bool is_empty();
    bool push();
    bool pop();
    bool top();
public:
    
    // Конструктор теста
    test_stack(stack &st);
    
    // Запуск теста
    bool run();
};

class test_d_stack {
public:
    static bool run();
};


class test_l_stack {
public:
    static bool run();
};
