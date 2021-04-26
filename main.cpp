#include <bits/stdc++.h>
#include "Car.h";
#include "Order.h";
#include "Passenger.h";
#include "Driver.h";
#include "Admin.h";
#include "Date.h";

using namespace std;

int actDay, actMonth, actYear, actHour, actMinute, actSecond;
Date actDate;

int numberOfPassengers, numberOfDrivers;
vector <Passenger> passengerDataBase;
vector <Driver> driverDataBase;
vector <Admin> adminDatabase;
vector <pair <Order, string>> freeOrders;
vector <pair <Order, pair<pair <string, string>, pair <string, string>>>> takenOrders;

void LoadingDataBaseOfPassengers()
{
    ifstream indbP("DataBaseOfPassengers.txt");

    int num;

    while(indbP >> num)
    {
        string name; indbP >> name;
        string password; indbP >> password;

        int n; indbP >> n;
        vector <double> marks;

        for (int i = 0; i < n; i++)
        {
            double tmpMark; indbP >> tmpMark;
            marks.push_back(tmpMark);
        }

        double rating; indbP >> rating;

        int m; indbP >> m;

        vector <Order> history;

        for (int i = 0; i < m; i++)
        {
            string from, to;
            int day, month, year, hour, minute, second;
            indbP >> from >> to >> day >> month >> year >> hour >> minute >> second;

            Date tmpTime(day, month, year, hour, minute, second);
            Order tmpOrder(from, to, tmpTime);

            history.push_back(tmpOrder);
        }

        string payments; indbP >> payments;

        Passenger tmpPassanger(name, password, marks, rating, history, payments);
        passengerDataBase.push_back(tmpPassanger);
    }

    numberOfPassengers = passengerDataBase.size();
}

void LoadingDataBaseOfDrivers()
{
    ifstream indbD("DataBaseOfDrivers.txt");

    int num;

    while(indbD >> num)
    {
        string name; indbD >> name;
        string password; indbD >> password;

        int n; indbD >> n;
        vector <double> marks;

        for (int i = 0; i < n; i++)
        {
            double tmpMark; indbD >> tmpMark;
            marks.push_back(tmpMark);
        }

        double rating; indbD >> rating;

        string model; indbD >> model;
        int carType; indbD >> carType;
        int currentCoordinates; indbD >> currentCoordinates;
        string color; indbD >> color;
        string number; indbD >> number;

        Car tmpCar(model, carType, currentCoordinates, color, number);

        bool status; indbD >> status;

        Driver tmpDriver(name, password, marks, rating, tmpCar, status);
        driverDataBase.push_back(tmpDriver);
    }

    numberOfDrivers = driverDataBase.size();
}

void LoadingDataBaseOfAdmins()
{
    ifstream inA("DataBaseOfAdmins.txt");

    int num;

    while (inA >> num)
    {
        string name, password;
        inA >> name >> password;

        Admin tmpAdmin(name, password);

        adminDatabase.push_back(tmpAdmin);
    }
}

void LoadingFreeOrders()
{
    ifstream inO("freeOrdersDataBase.txt");

    int num;

    while (inO >> num)
    {

        string from, to;
        int day, month, year, hour, minute, second;
        inO >> from >> to >> day >> month >> year >> hour >> minute >> second;

        Date tmpTime(day, month, year, hour, minute, second);
        Order tmpOrder(from, to, tmpTime);

        string type; inO >> type;

        freeOrders.push_back(make_pair(tmpOrder, type));
    }
}

void LoadingTakenOrders()
{
    ifstream inT("takenOrders.txt");

    int num;

    while(inT >> num)
    {
        string from, to;
        int day, month, year, hour, minute, second;
        inT >> from >> to >> day >> month >> year >> hour >> minute >> second;

        Date tmpTime(day, month, year, hour, minute, second);
        Order tmpOrder(from, to, tmpTime);

        string loginPassenger, passwordPassenger, loginDriver, passwordDriver;
        inT >> loginPassenger >> passwordPassenger >> loginDriver >> passwordDriver;

        takenOrders.push_back((make_pair(tmpOrder, make_pair(make_pair(loginPassenger, passwordPassenger), make_pair(loginDriver, passwordDriver)))));
    }
}

void SavingDataBaseOfPassengers()
{
    ofstream outdbP("DataBaseOfPassengers.txt");

    for (int i = 0; i < passengerDataBase.size(); i++)
    {
        outdbP << i << ' ' << passengerDataBase[i].getName() << ' ' << passengerDataBase[i].getPassword() << ' '
        << passengerDataBase[i].getMarks().size() << endl;

        for (int j = 0; j < passengerDataBase[i].getMarks().size(); j++)
            outdbP << passengerDataBase[i].getMarks()[j] << ' ';

        outdbP << endl;

        outdbP << passengerDataBase[i].getRating() << ' ' << passengerDataBase[i].getHistory().size() << ' ';

        for (int j = 0; j < passengerDataBase[i].getHistory().size(); j++)
        {
            outdbP << passengerDataBase[i].getHistory()[j].getFrom() << ' '
            << passengerDataBase[i].getHistory()[j].getTo() << ' '
            << passengerDataBase[i].getHistory()[j].getDate().getDay() << ' ' << passengerDataBase[i].getHistory()[j].getDate().getMonth() << ' '
            << passengerDataBase[i].getHistory()[j].getDate().getYear() << ' ' << passengerDataBase[i].getHistory()[j].getDate().getHour() << ' '
            << passengerDataBase[i].getHistory()[j].getDate().getMinute() << ' ' << passengerDataBase[i].getHistory()[j].getDate().getSecond() << endl;
        }

        outdbP << passengerDataBase[i].getPayments();
        outdbP << endl;
    }

}

void SavingDataBaseOfDrivers()
{
    ofstream outdbD("DataBaseOfDrivers.txt");

    for (int i = 0; i < driverDataBase.size(); i++)
    {
        outdbD << i << ' ' << driverDataBase[i].getName() << ' ' << driverDataBase[i].getPassword() << ' '
        << driverDataBase[i].getMarks().size() << endl;

        for (int j = 0; j < driverDataBase[i].getMarks().size(); j++)
            outdbD << driverDataBase[i].getMarks()[j] << ' ';

        outdbD << endl;

        outdbD << driverDataBase[i].getRating() << ' ';
        outdbD << driverDataBase[i].getCar().getModel() << ' ' << driverDataBase[i].getCar().getCarType() << ' '
        << driverDataBase[i].getCar().getCurrentCoordinates() << ' '
        << driverDataBase[i].getCar().getColor() << ' '
        << driverDataBase[i].getCar().getNumber();

        outdbD << driverDataBase[i].getStatus();

        outdbD << endl;
    }
}

void DavingDataBaseOfAdmins()
{
    ofstream outA("DataBaseOfAdmins.txt");

    for (int i = 0; i < adminDatabase.size(); i++)
        outA << i << ' ' << adminDatabase[i].getName() << ' ' << adminDatabase[i].getPassword() << endl;
}

void SavingFreeOrders()
{
    ofstream outO("freeOrdersDataBase.txt");

    for (int i = 0; i < freeOrders.size(); i++)
    {
        outO << i << ' ';

        outO << freeOrders[i].first.getFrom() << ' '
            << freeOrders[i].first.getTo() << ' '
            << freeOrders[i].first.getDate().getDay() << ' ' << freeOrders[i].first.getDate().getMonth() << ' '
            << freeOrders[i].first.getDate().getYear() << ' ' << freeOrders[i].first.getDate().getHour() << ' '
            << freeOrders[i].first.getDate().getMinute() << ' ' << freeOrders[i].first.getDate().getSecond() << ' ';

        outO << freeOrders[i].second << endl;
    }
}

void SavingTakenOrders()
{
    ofstream outT("takenOrders.txt");

    for (int i = 0; i < takenOrders.size(); i++)
    {
        outT << i << ' ';

        outT << takenOrders[i].first.getFrom() << ' '
            << takenOrders[i].first.getTo() << ' '
            << takenOrders[i].first.getDate().getDay() << ' ' << takenOrders[i].first.getDate().getMonth() << ' '
            << takenOrders[i].first.getDate().getYear() << ' ' << takenOrders[i].first.getDate().getHour() << ' '
            << takenOrders[i].first.getDate().getMinute() << ' ' << takenOrders[i].first.getDate().getSecond() << endl;

        outT << takenOrders[i].second.first.first << ' ' << takenOrders[i].second.first.second << endl;
        outT << takenOrders[i].second.second.first << ' ' << takenOrders[i].second.second.second << endl;
    }
}

void passengerGateway()
{
    string login, password;

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < passengerDataBase.size(); i++)
        if (passengerDataBase[i].getName() == login && passengerDataBase[i].getPassword() == password)
        {
            cout << "Logged in successfully" << endl;

            while(true)
            {
                cout << "OrderTaxi / CheckHistory / Logout / CheckPayments / OrderStatus" << endl;
                string command; cin >> command;

                if (command == "OrderTaxi")
                {
                    cout << "Enter adress from and to: " << endl;
                    string adressFrom, adressTo;
                    cin >> adressFrom >> adressTo;

                    Order tmp(adressFrom, adressTo, actDate);

                    cout << "Choose car type: (Economy, Comfort, ComfortPlus, Business)" << endl;

                    string type; cin >> type;

                    cout << "Make the order? Y / N" << endl;

                    string ans; cin >> ans;

                    if (ans == "Y")
                    {
                        freeOrders.push_back(make_pair(tmp, type));
                        cout << "Order was made" << endl;
                        passengerDataBase[i].pushOrder(tmp);
                    }
                }

                if (command == "CheckHistory")
                {
                    for (int i = 0; i < passengerDataBase.size(); i++)
                    {
                        if (passengerDataBase[i].getName() == login && passengerDataBase[i].getPassword() == password)
                        {
                            for (int j = 0; j < passengerDataBase[i].getHistory().size(); j++)
                            {
                                cout << j + 1 << ": ";
                                cout << "From " << passengerDataBase[i].getHistory()[j].getFrom() << ' '
                                << "To " << passengerDataBase[i].getHistory()[j].getTo() << ' '
                                << passengerDataBase[i].getHistory()[j].getDate().getDay() << ' ' << passengerDataBase[i].getHistory()[j].getDate().getMonth() << ' '
                                << passengerDataBase[i].getHistory()[j].getDate().getYear() << ' ' << passengerDataBase[i].getHistory()[j].getDate().getHour() << ':'
                                << passengerDataBase[i].getHistory()[j].getDate().getMinute() << ':' << passengerDataBase[i].getHistory()[j].getDate().getSecond() << endl;
                            }
                        }
                    }
                }

                if (command == "Logout") break;

                if (command == "CheckPayments")
                {
                    cout << passengerDataBase[i].getPayments() << endl;
                    cout << "Edit payments? Y / N" << endl;
                    string tmpCommand; cin >> tmpCommand;

                    if (tmpCommand == "Y")
                    {
                        cout << "Enter new payments: ";
                        string newPayment; cin >> newPayment;
                        passengerDataBase[i].editPayment(newPayment);
                    }
                }

                if (command == "OrderStatus")
                {
                    bool check = 0;

                    Order act = passengerDataBase[i].getHistory()[passengerDataBase[i].getHistory().size() - 1];

                    for (int i = 0; i < freeOrders.size(); i++)
                        if (freeOrders[i].first == act)
                        {
                            cout << "Your order was not taken" << endl;
                            check = 1;
                            break;
                        }
                        else
                        {
                            for (int i = 0; i < takenOrders.size(); i++)
                                if (takenOrders[i].first == act)
                                {
                                    cout << "Your order was taken by " << takenOrders[i].second.first.first << endl;
                                    check = 1;
                                    break;
                                }
                        }
                        if (check == 0)
                            cout << "You have not active orders" << endl;
                }
            }
        }

    cout << "account does not exist" << endl;
}

void driverGateway()
{
    string login, password;

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < driverDataBase.size(); i++)
        if (driverDataBase[i].getName() == login && driverDataBase[i].getPassword() == password)
        {
            cout << "Logged in successfully" << endl;

            while(true)
            {
                cout << "TakeTheOrder / CheckHistory / Logout" << endl;
                string command; cin >> command;

                if (command == "TakeTheOrder")
                {
                    cout << "Choose order from this list:" << endl;
                    for (int i = 0; i < freeOrders.size(); i++)
                    {
                        cout << i + 1 << ' ' << freeOrders[i].first.getFrom() << ' ' << freeOrders[i].first.getFrom() << ' ' << freeOrders[i].second << endl;
                    }

                    cout << "Enter the number of order or '0' for cancel: ";
                    int ans; cin >> ans;
                    int tmp = 0;
                    cout << freeOrders[ans - 1].second << ' ' << driverDataBase[i].getCar().getCarType() << endl;

                    if (ans > 0)
                    {
                        if (freeOrders[ans - 1].second == driverDataBase[i].getCar().getCarType())
                        {
                            for (int a = 0; a < passengerDataBase.size(); a++)
                            {
                                for (int b = 0; b < passengerDataBase[a].getHistory().size(); b++)
                                    if (passengerDataBase[a].getHistory()[b] == freeOrders[ans - 1].first)
                                        tmp = a;
                            }

                            takenOrders.push_back(make_pair(freeOrders[ans - 1].first, make_pair(make_pair(driverDataBase[i].getName(), driverDataBase[i].getPassword()), make_pair(passengerDataBase[tmp].getName(), passengerDataBase[tmp].getPassword()))));
                            driverDataBase[i].changeStatus(1);
                        }
                        else cout << "Type of car is not suitable" << endl;
                    }
                }
            }
        }

    cout << "account does not exist" << endl;
}

void adminGateway()
{
    string login, password;

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < adminDatabase.size(); i++)
        if (adminDatabase[i].getName() == login && adminDatabase[i].getPassword() == password)
        {
            while (true)
            {
                cout << "ApproveCar / Drivers / Passengers / Logout" << endl;
                    string command; cin >> command;

                if (command == "Logout") break;

                if (command == "Drivers")
                {
                    for (int i = 0; i < driverDataBase.size(); i++)
                        cout << i + 1 << ' ' << driverDataBase[i].getName() << ' ' << driverDataBase[i].getPassword() << endl;

                    cout << "Ban someone? Type either number or '0' for cancel" << endl;
                    {
                        int ans; cin >> ans;
                        if (ans > 0) driverDataBase.erase(driverDataBase.begin() + ans - 1);
                    }
                }

                if (command == "Passengers")
                {
                    for (int i = 0; i < passengerDataBase.size(); i++)
                        cout << i + 1 << ' ' << passengerDataBase[i].getName() << ' ' << passengerDataBase[i].getPassword() << endl;

                    cout << "Ban someone? Type either number or '0' for cancel" << endl;
                    {
                        int ans; cin >> ans;
                        if (ans > 0) passengerDataBase.erase(passengerDataBase.begin() + ans - 1);
                    }
                }
            }
        }

    cout << "account does not exist" << endl;
}

void Login()
{
    cout << "Login as who? (as a Passenger, Driver or Admin)" << endl;

    string answer; cin >> answer;

    if (answer == "Passenger") passengerGateway();
    if (answer == "Driver") driverGateway();
    if (answer == "Admin") adminGateway();
}

void RegisterPassenger()
{
    string login, password;

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;

    Passenger tmpPassenger(login, password);

    passengerDataBase.push_back(tmpPassenger);
}

void RegisterDriver()
{
    string login, password, typeofcar;

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;
    cout << "Type Of Car: ";
    cin >> typeofcar;

    Car tmpCar(typeofcar);
    Driver tmpDriver(login, password, tmpCar);

    driverDataBase.push_back(tmpDriver);
}

void Register()
{
    cout << "Register as who? (as a Passenger or Driver)" << endl;

    string answer; cin >> answer;

    if (answer == "Passenger") RegisterPassenger();
    if (answer == "Driver") RegisterDriver();
}

void Gateway()
{
    cout << "Login or Register?" << endl;

    string answer; cin >> answer;

    if (answer == "Login") Login();
    if (answer == "Register") Register();
}

int main()
{
    cout << "Loading of data base, Please wait." << endl;

    actYear = 2021, actMonth = 4, actDay = 27,
    actHour = 22, actMinute = 28, actSecond = 20;
    Date aaa(actDay, actMonth, actYear, actHour, actMinute, actSecond);
    actDate = aaa;

    LoadingDataBaseOfPassengers();
    LoadingDataBaseOfDrivers();
    LoadingDataBaseOfAdmins();
    LoadingFreeOrders();
    LoadingTakenOrders();

    Gateway();

    cout << "Saving of data" << endl;

    SavingDataBaseOfPassengers();
    SavingDataBaseOfDrivers();
    SavingFreeOrders();
    SavingTakenOrders();
    DavingDataBaseOfAdmins();

    return 0;
}
