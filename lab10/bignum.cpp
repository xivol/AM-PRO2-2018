//
// Лабораторная работа №10. Классы. Целые числа с длинной арифметикой
// bignum.cpp
//
#include "bignum.h"
#include <exception>
#include <climits>
#include <cmath>
#include <cctype>
#include <string>

bignum::bignum() : digits(), negative(false)
{}

bignum::bignum(int64_t number) : digits()
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

bignum::operator int64_t() const
{
    if (digits.count() > (int)ceil(log10(INT64_MAX)))
        throw std::length_error("Bignum is too big for int64!");
    
    int64_t result = 0;
    if (digits.count() == 0)
        return result;
    
    int64_t mul = (int64_t)::pow(10, digits.count()-1);
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
    
    return digits == other.digits;
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
//        str += is.get();
//    }
//    b = bignum(str.c_str());
//    return is;
//}

//std::ostream &operator<<(std::ostream &os, const bignum &b)
//{
//    os << (string)b;
//    return os;
//}
