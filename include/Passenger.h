#ifndef PASSENGER_H
#define PASSENGER_H

#include <bits/stdc++.h>
using namespace std;

struct Passenger
{
private:

    string name;
    string password;

    vector <double> marks;
    double rating;

    vector <Order> history;

    string payments;

public:

    Passenger(string n, string p, vector <double> m, double r, vector <Order> h, string pmt)
    {
        name = n;
        password = p;

        marks = m;
        rating = r;

        history = h;
        payments = pmt;
    }

    Passenger(string n, string p)
    {
        name = n;
        password = p;
    }

    string getName()
    {
        return name;
    }

    string getPassword()
    {
        return password;
    }

    vector <double> getMarks()
    {
        return marks;
    }

    double getRating()
    {
        return rating;
    }

    vector <Order> getHistory()
    {
        return history;
    }

    string getPayments()
    {
        return payments;
    }

    void pushOrder(Order a)
    {
        history.push_back(a);
    }

    void editPayment(string p)
    {
        payments = p;
    }

};

#endif // PASSENGER_H
