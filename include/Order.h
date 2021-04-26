#ifndef ORDER_H
#define ORDER_H

#include <bits/stdc++.h>
#include "Date.h";

using namespace std;

struct Order
{
private:

    string adressFrom;
    string adressTo;
    Date date;

public:

    Order(string from, string to, Date t)
    {
        adressFrom = from;
        adressTo = to;
        date = t;
    }

    string getFrom()
    {
        return adressFrom;
    }

    string getTo()
    {
        return adressTo;
    }

    Date getDate()
    {
        return date;
    }

    bool operator == (const Order &a) const
    {
        return adressFrom == a.adressFrom;
    }

};

#endif // ORDER_H
