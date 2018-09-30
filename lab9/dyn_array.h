//
// Лабораторная работа №9. Классы. Конструктор перемещения
// dyn_array.h
//
#pragma once
#include <iostream>

// Класс динамический массив
class dyn_array
{
public:
    // Тип данных, хранящийся в массиве
    typedef double datatype;

private:
    // Указатель на массив
    datatype *data;

    // Количество элементов в массиве
    int size;

    // Функция копирования значений из массива в массив
    void copy(const datatype *from, datatype* to, int size);

    // Функция подстановки значений из другого динамического массива
    void swap(dyn_array &other) noexcept;

public:

    /*
    Инициализация
    */

    // Конструктор по умолчанию
    dyn_array();

    // Конструктор от размера
    dyn_array(int size);

    // Деструктор
    ~dyn_array();

    // Конструктор копирования
    dyn_array(const dyn_array& d);

    // Конструктор перемещения
    dyn_array(dyn_array&& d);

    /*
    Операции
    */

    // Операция присваивания через перемещение
    dyn_array &operator=(dyn_array d);

    // Операция доступа к элементам
    datatype &operator[](int index);

    // Операция доступа к элементам для чтения
    datatype operator[](int index) const;

    // Операция сравнения массивов на равенство
    bool operator==(const dyn_array &other) const;

    // Операция сравнения массивов на неравенство
    bool operator!=(const dyn_array &other) const;

    /*
    Методы
    */

    // Количество элементов в массиве
    int count() const;

    // Изменение размера массива
    void resize(int new_size);

    // Добавление элемента в конец массива
    // с увеличением размера массива
    void append(const datatype &x);

    // Вставка элемента по заданному индексу
    void insert(int index, const datatype &x);

    // Удаление элемента по заджанному индексу
    void remove(int index);

    // Поиск заданного элемента
    int find(const datatype &x) const;


    // Сортировка значений в массиве по убыванию
    void sort();

    // Удаление повторяющихся значений в массиве
    void unique();

    // Добавление всех значений в конец массива
    void append(const dyn_array &d);
};

// Операция вывода
std::ostream &operator<<(std::ostream &os, const dyn_array &d);

// Операция ввода
std::istream &operator>>(std::istream &is, dyn_array &d);