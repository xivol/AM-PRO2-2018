//
//  bignum.cpp
//  lab10
//
//  Created by Илья Лошкарёв on 02.10.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#include "bignum.h"

bignum::bignum(long number)
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
    long result = 0;
    if (digits.count() == 0)
        return result;
    
    for (int i = digits.count() - 1; i >= 0; i--)
        result = result * 10 + digits[i];
    
    return result;
}

std::istream &operator>>(std::istream &is, bignum &b)
{
    int n = 0;
    char *str = new char[n];
    b = bignum(str);
    return is;
}

std::ostream &operator<<(std::ostream &os, const bignum &b)
{
    os << (char*) b;
    return os;
}
