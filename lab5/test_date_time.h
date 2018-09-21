//
// Лабораторная рвбота №5. Классы. Перегрузка операций
// tset_date_time.h
//
#pragma once
class test_date_time
{
    test_date_time();
    ~test_date_time();

    bool is_leap_year();
    bool days_since_unix_epoch();
    bool days_since_new_year();
public:  
    static bool run();
};

