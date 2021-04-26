#ifndef DRIVER_H
#define DRIVER_H

#include <bits/stdc++.h>
#include "Car.h";
using namespace std;

struct Driver
{
private:

    string name;
    string password;

    int sizeOfMarksVector;

    vector <double> marks;
    double rating;

    Car car;
    bool status;

public:

    Driver()
    {
        rating = 0;
    }

    Driver(string n, string p, Car t)
    {
        name = n;
        password = p;
        car = t;
        status = 0;
        rating = 0;
    }

    Driver(string n, string p, vector <double> m, double r, Car c, bool s)
    {
        name = n;
        password = p;

        marks = m;
        rating = r;

        car = c;
        status = s;
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

    Car getCar()
    {
        return car;
    }

    bool getStatus()
    {
        return status;
    }

    istream& operator >> (istream& is)
    {
        is >> name >> password >> sizeOfMarksVector;

        for (int i = 0; i < sizeOfMarksVector; i++)
            is >> marks[i];

        is >> rating;
        //is >> car;
        is >> status;
    }

    changeStatus(bool a)
    {
        status = a;
    }

};

#endif // DRIVER_H
