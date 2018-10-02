//
//  bignum.h
//  lab10
//
//  Created by Илья Лошкарёв on 02.10.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//
#pragma once
#include <iostream>
#include <climits>
#include "dyn_array.h"

class bignum
{
    // Значащие цифры числа
    dyn_array digits;
    
    // Знак числа
    bool negative;
    
    // Заполнение значащих цифр и знака
    void fill_digits_and_sign(long source);
    
public:
    // Конструктор по умолчанию
    bignum();
    
    // Конструкторы преобразования
    bignum(long number);
    operator long() const;
    
    // Конструктор от строки
    explicit bignum(char* str);
    
    // Знак числа
    bool is_negative();
    
    // Операции приведения к маленькому числу
    explicit operator int() const;

    // Операция явного приведения к строке
    explicit operator char*() const;
    
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
    bignum &pow(const bignum &exp);
    
    // Операции деления
    bignum operator/(const bignum &other) const;
    bignum &operator/=(const bignum &other);
    
    // Операции взятия остатка от деления
    bignum operator%(const bignum &other) const;
    bignum &operator%=(const bignum &other);
    
    // Метод вычисления НОД
    bignum gcd(const bignum &other) const;
    
    // Проверка числа на простоту
    bool is_prime() const;
};


// Операции ввода/вывода
std::istream &operator>>(std::istream &is, bignum &b);
std::ostream &operator<<(std::ostream &os, const bignum &b);
