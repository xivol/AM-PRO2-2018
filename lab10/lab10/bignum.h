//
// Лабораторная работа №10. Классы. Целые числа с длинной арифметикой
// bignum.h
//
#pragma once
#include <iostream>
#include <climits>
#include <string>
#include "dyn_array.h"

class bignum
{
    // Значащие цифры числа
    dyn_array digits;
    
    // Знак числа
    bool negative;
    
public:
    
    /*
      Инициализация
    */

    // Конструктор по умолчанию
    bignum();
    
    // Конструктор преобразования
    bignum(int64_t number);
    
    // Конструктор преобразования из строки
    bignum(const char *str);

    /*
      Методы доступа к полям
    */

    // Количество цифр
    size_t size() const;
    
    // Знак числа
    bool is_negative() const;

    /*
      Операции приведения
    */
    
    // Операции приведения к числу
    operator int64_t() const;
    
    // Операции приведения к маленькому числу
    explicit operator int() const;

    // Операция явного приведения к строке
    explicit operator std::string() const;
        
    /*
      Операции сравнения
    */
    
    // Сравнение на равенство
    bool operator==(const bignum &other) const;
    bool operator!=(const bignum &other) const;
    
    // Сравнение на неравенство
    bool operator>(const bignum &other) const;
    bool operator<=(const bignum &other) const;
    
    bool operator<(const bignum &other) const;
    bool operator>=(const bignum &other) const;
    
    /*
      Арифметические операции
    */

    // Операция унарный минус
    bignum operator-() const;
    
    // Операции сложения
    bignum operator+(const bignum &other) const;
    bignum &operator+=(const bignum &other);
    
    // Операции вычитания
    bignum operator-(const bignum &other) const;
    bignum &operator-=(const bignum &other);
    
    // Операции умножения
    bignum operator*(const bignum &other) const;
    bignum &operator*=(const bignum &other);
    
    // Метод возведения в степень
    bignum pow(const bignum &exp) const;
    
    // Операции деления
    bignum operator/(const bignum &other) const;
    bignum &operator/=(const bignum &other);
    
    // Операции взятия остатка от деления
    bignum operator%(const bignum &other) const;
    bignum &operator%=(const bignum &other);
    
    // Метод вычисления НОД
    bignum gcd(const bignum &other) const;
    
    // Метод проверки числа на простоту
    bool is_prime() const;
};


// Операции ввода/вывода
std::istream &operator>>(std::istream &is, bignum &b);
std::ostream &operator<<(std::ostream &os, const bignum &b);
