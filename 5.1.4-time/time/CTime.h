#pragma once
#include <stdexcept>
#include <iostream>

const std::string OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: out of range";
const char OUTPUT_STREAM_SEPARATOR = ':';

const int SECONDS_IN_A_DAY = 86399;
const int SECONDS_IN_A_MINUTE = 60;
const int SECONDS_IN_AN_HOUR = 3600;

//ћоделирует врем€ суток, задаваемое количеством часов (0-23), минут (0-59) и секунд (0-59)
class CTime
{
    public:
        //»нициализирует врем€ заданным количеством часов, минут и секунд
        CTime(unsigned inputHours, unsigned inputMinutes, unsigned inputSeconds = 0);
    
        //»нициализирует врем€ количеством секунд после полуночи
        CTime(unsigned inputTimeStamp = 0);
    
        //¬озвращает количество часов
        unsigned GetHours()const;
    
        //¬озвращает количество минут
        unsigned GetMinutes()const;
    
        //¬озвращает количество секунд
        unsigned GetSeconds()const;

        // астомные операторы
        CTime& operator++();
        CTime& operator--();

        CTime operator++(int);
        CTime operator--(int);

        CTime operator+(const CTime& time);
        CTime operator-(const CTime& time);

        CTime& operator+=(const CTime& time);
        CTime& operator-=(const CTime& time);

        CTime operator*(const int& number);
        friend CTime operator*(const int& number, const CTime& time);

        int operator/(const CTime& time);
        CTime operator/(const int& number);

        CTime& operator*=(const int& time);
        CTime& operator/=(const int& time);

        friend std::ostream& operator<<(std::ostream& outputStream, const CTime& time);
        friend std::istream& operator>>(std::istream& inputStream, CTime& time);

        bool operator==(const CTime& time) const;
        bool operator!=(const CTime& time) const;

        bool operator>(const CTime& time) const;
        bool operator<(const CTime& time) const;

        bool operator>=(const CTime& time) const;
        bool operator<=(const CTime& time) const;

    private:
        // оличество секунд в дне - от 0 до 86399
        int seconds = 0;

        //ѕровер€ет, верное ли врем€ сейчас хранитс€ в классе
        bool IsTimeValid();

        //ѕровер€ет, верное ли врем€ в передающемс€ объекте класса
        bool IsTimeValid(int time);
};

