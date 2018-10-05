//
//  bignum.cpp
//  lab10
//
//  Created by Илья Лошкарёв on 02.10.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#include "bignum.h"
#include <exception>
#include <climits>
#include <cmath>
#include <cctype>
#include <string>

bignum::bignum() : digits(), negative(false)
{}

bignum::bignum(long number) : digits()
{
    if (number < 0) {
        number = -number;
        negative = true;
    }
    else
        negative = false;
    while (number > 0) {
        digits.append(number % 10);
        number = number / 10;
    }
}

bignum::operator long() const
{
    if (digits.count() > (int)ceil(log10(LONG_MAX)))
        throw std::length_error("Bignum is too big for long!");
    
    long result = 0;
    if (digits.count() == 0)
        return result;
    
    long mul = (long)::pow(10, digits.count()-1);
    for (int i = digits.count() - 1; i >= 0; --i)
    {
        result = result + mul * digits[i];
        mul /= 10;
    }
    
    if (negative)
        result *= -1;
        
    return result;
}

bool bignum::operator==(const bignum &other) const
{
    if (negative != other.negative ||
        digits.count() != other.digits.count())
        return false;
    
    for (int i = digits.count() - 1; i >= 0; --i)
        if (digits[i] != other.digits[i])
            return false;
    
    return true;
}

bool bignum::operator!=(const bignum &other) const
{
    return !(*this == other);
}

//std::istream &operator>>(std::istream &is, bignum &b)
//{
//    std::string str;
//    while (is.peek() == '-' || isdigit(is.peek()))
//    {
//        str.insert(str.begin(), is.get());
//    }
//    b = bignum(str.c_str());
//    return is;
//}

//std::ostream &operator<<(std::ostream &os, const bignum &b)
//{
//    os << (string)b;
//    return os;
//}
