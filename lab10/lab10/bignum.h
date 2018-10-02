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
    bool positive;
    
    // Заполнение значащих цифр и знака
    fill_digits_and_sign(long source);
    
public:
    bignum();
    bignum(int i);
    bignum(long l);
    
    bool is_positive();
    
    int operator int() const;
    long operator long() const;
    
    friend std::istream &operator>>(std::istream &is, bignum &b);
    friend std::ostream &operator<<(std::ostream &os, const bignum &b);
    
    bignum operator+(const bignum &other) const;
    bignum &operator+=(const bignum &other);
    
    bignum operator-(const bignum &other) const;
    bignum &operator-=(const bignum &other);
    
    bignum operator*(const bignum &other) const;
    bignum &operator*=(const bignum &other);
    
    bignum operator/(const bignum &other) const;
    bignum &operator/=(const bignum &other);
    
    bignum operator%(const bignum &other) const;
    bignum &operator%=(const bignum &other);
    
    bignum pow(const bignum &exp) const;
    bignum &pow(const bignum &exp);
    
    bignum gcd(const bignum &other) const;
    
    bool is_prime() const;
};
