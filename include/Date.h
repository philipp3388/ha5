#ifndef DATE_H
#define DATE_H

#include <bits/stdc++.h>
using namespace std;

class Date
{
private:

    int day, month, year;
    int hour, minute, second;

public:

    Date()
    {
        day = 0, month = 0, year = 0;
        hour = 0, minute = 0, second = 0;
    }

    Date(int d, int mth, int y, int h, int mnt, int s)
    {
        day = d, month = mth, year = y;
        hour = h, minute = mnt, second = s;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    int getHour()
    {
        return hour;
    }

    int getMinute()
    {
        return minute;
    }

    int getSecond()
    {
        return second;
    }

};

#endif // DATE_H
