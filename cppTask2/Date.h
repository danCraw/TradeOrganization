#pragma once
class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date() {}

    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    void SetDate(int year, int month, int day);

    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
};

