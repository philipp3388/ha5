#ifndef CAR_H
#define CAR_H

#include <bits/stdc++.h>
using namespace std;

struct Car
{
private:

    string model;
    string carType;
    int currentCoordinates;
    string color;
    string number;

public:

    Car()
    {

    }

    Car(string type)
    {
        carType = type;
    }

    Car(string m, int cT, int cC, string c, string n)
    {
        model = m;
        carType = cT;
        currentCoordinates = cC;
        color = c;
        number = n;
    }

    string getModel()
    {
        return model;
    }

    string getCarType()
    {
        return carType;
    }

    int getCurrentCoordinates()
    {
        return currentCoordinates;
    }

    string getColor()
    {
        return color;
    }

    string getNumber()
    {
        return number;
    }

};


#endif // CAR_H
