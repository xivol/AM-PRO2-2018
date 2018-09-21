//
// Лабораторная рвбота №5. Классы. Перегрузка операций
// date_time.h
//
#pragma once
#include <cstdint>

class test_date_time;


// дата и время в секундах с начала эпохи Unix
class date_time
{
    // количество секунд с начала эпохи
    uint64_t unix_time;

    // количество секунд в дне
    static const uint64_t seconds_per_day = 86400;
        
    // количество дней с начала года
    static const uint16_t days_per_month[];
    /* 
      Статические массивы не могли быть инициализированы в классе до С++17

      Начиная с C++17 можно писать:
        inline constexpr static
        https://stackoverflow.com/questions/38043442/how-do-inline-variables-work
    */

    // смещение для подсчёта высокосных лет
    static const uint16_t offset_year = 1900;

    // количество дней после смещения
    static const uint32_t days_since_offset_year = 70*365 + 17;

    // проверка высокосного года
    static bool is_leap_year(uint16_t year);

    // количество дней с начала года
    static uint16_t days_since_new_year(uint16_t day, uint8_t month, uint16_t year);

    // количество дней до начала года с начала эпохи
    static uint64_t days_since_unix_epoch(uint16_t year);

public:
    // перечисление месяцев
    enum month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

    // конструктор от начала эпохи: 1.1.1970 @ 00:00:00
    date_time();

    // доступ к закрытому полю
    uint64_t get_unix_time() const;
    
    // тестирующий класс
    friend class test_date_time;
};