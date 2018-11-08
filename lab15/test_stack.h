//
// Лабораторная работа №15. Абстрактные типы данных. Стек
// test_stack.h
//
#pragma once
#include "stack.h"
#include <initializer_list>

class test_d_stack
{
    // Тесты методов стека
    bool is_empty();
    bool push();
    bool pop();
    bool top();
public:
    // Запуск теста
    static bool run();
};


class test_l_stack
{
    typedef l_stack::node* array_list;
    
    // Генерация тестового списка
    array_list get_array_list(const std::initializer_list<stack::datatype>& data);
    
    // Проверка списков на равенство
    bool is_equal(l_stack::node *list1, l_stack::node *list2);
    
    // Тесты конструкторов
    bool copy_ctor();
    bool assign();

    // Тесты методов стека
    bool is_empty();
    bool push();
    bool pop();
    bool top();
public:
    // Запуск теста
    static bool run();
};
