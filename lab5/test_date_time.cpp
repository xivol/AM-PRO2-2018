//
// Лабораторная рвбота №5. Классы. Перегрузка операций
// test_date_time.cpp
//
#include <cassert>
#include <iostream>
#include "date_time.h"
#include "test_date_time.h"

test_date_time::test_date_time()
{
    std::cerr << "Begining tests for date_time:" << std::endl;
}

bool test_date_time::is_leap_year()
{
    std::cerr << "test is_leap_year: ";

    int leap_years[] = { 1972, 1976,1980,1984,1988,1992,1996,2000,2004,2008,2012,2016,2020,2024,
        2028,2032,2036,2040,2044,2048,2052,2056,2060,2064,2068,2072,2076,2080,2084,2088,2092,2096
    };  
  
    for (int i = 1970; i < leap_years[31]; ++i) {
        bool is_leap = std::find(&leap_years[0], leap_years + sizeof(leap_years), i) != leap_years + sizeof(leap_years);
        assert(date_time::is_leap_year(i) == is_leap);
    }

    std::cerr << "OK" << std::endl;
    return true;
}

bool test_date_time::days_since_unix_epoch()
{
    std::cerr << "test days_since_unix_epoch: ";
    
    assert(date_time::days_since_unix_epoch(1970) == 0);

    assert(date_time::days_since_unix_epoch(1971) == 365);

    assert(date_time::days_since_unix_epoch(1973) == 365*3+1);

    assert(date_time::days_since_unix_epoch(2000) == 10957);

    assert(date_time::days_since_unix_epoch(2004) == 12418);

    std::cerr << "OK" << std::endl;
    return true;
}

bool test_date_time::days_since_new_year()
{
    std::cerr << "test days_since_new_year: ";

    for (int m = 0; m < 12; ++m)
        for (int d = 0; d < 30; ++d) {
            assert(date_time::days_since_new_year(d+1, m+1, 1970) == (date_time::days_per_month[m] + d));
            assert(date_time::days_since_new_year(d+1, m+1, 2000) == (date_time::days_per_month[m] + d + (m>1)));
        }
    
    std::cerr << "OK" << std::endl;
    return true;
}

bool test_date_time::run()
{
    test_date_time t;
    return t.is_leap_year()&&
        t.days_since_new_year() &&
        t.days_since_unix_epoch();
}


test_date_time::~test_date_time()
{
    std::cerr << "All tests for date_time have been passed!" << std::endl;
}
