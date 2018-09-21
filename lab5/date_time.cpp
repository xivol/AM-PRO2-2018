//
// Лабораторная рвбота №5. Классы. Перегрузка операций
// date_time.cpp
//
#include <cassert>
#include "date_time.h"

const uint16_t date_time::days_per_month[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

bool date_time::is_leap_year(uint16_t year)
{
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

uint16_t date_time::days_since_new_year(uint16_t day, uint8_t month, uint16_t year)
{
    uint16_t extra_day = (month > 2 ? is_leap_year(year) : 0);
    return day - 1 + days_per_month[month - 1] + extra_day;
}

uint64_t date_time::days_since_unix_epoch(uint16_t year)
{
    assert(year > 1969);
    year -= offset_year;
    uint32_t leap_days = ((year - 1) / 4);

    return  365 * year + leap_days - days_since_offset_year;
}

date_time::date_time() : unix_time(0)
{
}

uint64_t date_time::get_unix_time() const
{
    return unix_time;
}
