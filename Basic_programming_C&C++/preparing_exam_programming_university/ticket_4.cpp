#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct Traffic
{
    string make;
    int yearMaking;
    string colorCar;
    string numCar;
    int year;
    string surnameUser;
    int dataTex;

    Traffic() : make(""), yearMaking(0), colorCar(""), numCar(""), year(0), surnameUser(""), dataTex(0) {}

    Traffic(string m, int y, string col, string num, int ye, string sur, int d)
        : make(m), yearMaking(y), colorCar(col), numCar(num), year(ye), surnameUser(sur), dataTex(d) {}
};

void inputData(vector<Traffic> &t)
{
    int count;
    cout << "Input counts of data: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        string m;
        cout << "Input make of Car: ";
        getline(cin, m);
        int y;
        cout << "Input year which made car: ";
        cin >> y;
        cin.ignore();
        string col;
        cout << "Input color of Car: ";
        getline(cin, col);
        string num;
        cout << "Input number of Car: ";
        getline(cin, num);
        int ye;
        cout << "Input year: ";
        cin >> ye;
        cin.ignore();
        string sur;
        cout << "Input surname of user: ";
        getline(cin, sur);
        int d;
        cout << "Input data of tech: ";
        cin >> d;
        cin.ignore();

        t.push_back(Traffic(m, y, col, num, ye, sur, d));
    }
}

void printCarDate(const Traffic &t)
{
    cout << t.make << "\t" << t.yearMaking << "\t" << t.colorCar << "\t"
         << t.numCar << "\t" << t.surnameUser << "\t" << t.year << "\t" << t.dataTex << endl;
}

void findDataByYear(const vector<Traffic> &t)
{
    int yearTask = 0;
    cout << "Input year: ";
    cin >> yearTask;
    cin.ignore();

    bool found = false;
    for (const auto &c : t)
    {
        if (c.year >= yearTask)
        {
            printCarDate(c);
            found = true;
        }
    }
    if (!found)
        cout << "Not found Car" << endl;
}

void findDateByDataTex(const vector<Traffic> &t)
{
    int currentYear = 0;
    cout << "Input current year: ";
    cin >> currentYear;

    bool found = false;
    for (const auto &c : t)
    {
        if (currentYear - c.dataTex > 1)
        {
            cout << c.surnameUser << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Not found user" << endl;
}

void findCarMostOld(const vector<Traffic> &t)
{
    auto mostOldCar = min_element(t.begin(), t.end(), [](const auto &a, const auto &b)
                                  { return a.yearMaking < b.yearMaking; });

    cout << mostOldCar->surnameUser << " (" << mostOldCar->make << ", "
         << mostOldCar->yearMaking << ")" << endl;
}

void findCarByMake(const vector<Traffic> &t)
{
    map<string, int> m;

    for (const auto &c : t)
    {
        m[c.make]++;
    }

    auto mostMake = max_element(m.begin(), m.end(), [](const auto &a, const auto &b)
                                { return a.second < b.second; });

    for (const auto &c : t)
    {
        if (c.make == mostMake->first)
        {
            cout << c.surnameUser << endl;
        }
    }
}

void findUserByColorCar(const vector<Traffic> &t)
{
    string color;
    cout << "Input color of Car: ";
    getline(cin, color);

    bool found = false;
    for (const auto &c : t)
    {
        if (c.colorCar == color)
        {
            cout << c.surnameUser << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Not found user" << endl;
}

void findUserByMake(const vector<Traffic> &t)
{
    string make;
    cout << "Input make of Car: ";
    getline(cin, make);

    bool found = false;
    for (const auto &c : t)
    {
        if (c.make == make)
        {
            cout << c.surnameUser << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Not found user" << endl;
}

void findUserByFirstLetterOfNumber(const vector<Traffic> &t)
{
    char letter;
    cout << "Input two digits number of Car: ";
    cin >> letter;
    cin.ignore();

    bool found = false;
    for (const auto &c : t)
    {
        if (c.numCar[0] == letter)
        {
            cout << c.surnameUser << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Not found user" << endl;
}