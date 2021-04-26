#ifndef ADMIN_H
#define ADMIN_H

#include <bits/stdc++.h>
using namespace std;

class Admin
{
private:

    string name;
    string password;

public:

    Admin()
    {

    }

    Admin(string n, string p)
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
};

#endif // ADMIN_H
