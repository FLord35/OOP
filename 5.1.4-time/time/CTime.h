#pragma once
#include <stdexcept>
#include <iostream>

const std::string OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: out of range";
const char OUTPUT_STREAM_SEPARATOR = ':';

const int SECONDS_IN_A_DAY = 86399;
const int SECONDS_IN_A_MINUTE = 60;
const int SECONDS_IN_AN_HOUR = 3600;

//���������� ����� �����, ���������� ����������� ����� (0-23), ����� (0-59) � ������ (0-59)
class CTime
{
    public:
        //�������������� ����� �������� ����������� �����, ����� � ������
        CTime(unsigned inputHours, unsigned inputMinutes, unsigned inputSeconds = 0);
    
        //�������������� ����� ����������� ������ ����� ��������
        CTime(unsigned inputTimeStamp = 0);
    
        //���������� ���������� �����
        unsigned GetHours()const;
    
        //���������� ���������� �����
        unsigned GetMinutes()const;
    
        //���������� ���������� ������
        unsigned GetSeconds()const;

        //��������� ���������
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
        //���������� ������ � ��� - �� 0 �� 86399
        int seconds = 0;

        //���������, ������ �� ����� ������ �������� � ������
        bool IsTimeValid();

        //���������, ������ �� ����� � ������������ ������� ������
        bool IsTimeValid(int time);
};

