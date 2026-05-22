#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Telephone
{
    string surname;
    string fullName;
    string numberPhone;
    string address;

    Telephone() : surname(""), fullName(""), numberPhone(""), address("") {}

    Telephone(string sur, string ful, string num, string add)
        : surname(sur), fullName(ful), numberPhone(num), address(add) {}
};

void inputUsers(vector<Telephone> &t)
{
    int count = 0;
    cout << "Input counts of users: ";
    cin >> count;
    cin.ignore();

    string sur = "";
    string full = "";
    string number = "";
    string address = "";

    for (int i = 0; i < count; i++)
    {
        cout << "--- User " << i + 1 << " ---" << endl;
        cout << "Input surname of user: ";
        getline(cin, sur);
        cout << "Input full name of user: ";
        getline(cin, full);
        cout << "Input phone number of user: ";
        getline(cin, number);
        cout << "Input address of user: ";
        getline(cin, address);

        Telephone tel(sur, full, number, address);
        t.push_back(tel);
    }
}

void printUser(Telephone t)
{
    cout << t.surname << "\t" << t.fullName << "\t"
         << t.numberPhone << "\t" << t.address << endl;
}

void telephoneBySurname(vector<Telephone> &t)
{
    string findingSurname = "";
    cout << "Input surname of user who you find: ";
    getline(cin, findingSurname);

    bool found = false;

    for (const auto &user : t)
    {
        if (user.surname == findingSurname)
        {
            printUser(user);
            found = true;
        }
    }

    if (!found)
        cout << "Not found user!" << endl;
}

void findUserByLetter(vector<Telephone> &t)
{
    char fletter;
    cout << "Input first letter of user surname: ";
    cin >> fletter;
    cin.ignore();

    bool found = false;

    for (const auto &user : t)
    {
        if (user.surname[0] == fletter)
        {
            printUser(user);
            found = true;
        }
    }

    if (!found)
        cout << "Not found user!" << endl;
}

void findUserSameTwoDigits(vector<Telephone> &t)
{
    string twoDigits = "";
    cout << "Input two digits of number: ";
    getline(cin, twoDigits);

    bool found = false;

    for (const auto &user : t)
    {
        if (user.numberPhone.substr(0, 2) == twoDigits)
        {
            printUser(user);
            found = true;
        }
    }

    if (!found)
        cout << "Not found user!" << endl;
}

void findUserByNumber(vector<Telephone> &t)
{
    string num = "";
    cout << "Input Telephone number of user: ";
    getline(cin, num);

    bool found = false;

    for (const auto &user : t)
    {
        if (user.numberPhone == num)
        {
            printUser(user);
            found = true;
        }
    }

    if (!found)
        cout << "Not found user!" << endl;
}

void findNumberMaxUsers(vector<Telephone> &t)
{
    map<string, int> num;
    for (const auto &u : t)
    {
        num[u.numberPhone.substr(0, 2)]++;
    }
    auto findNum = max_element(num.begin(), num.end(),
                               [](const auto &a, const auto &b)
                               { return a.second < b.second; });

    for (const auto &user : t)
    {
        if (user.numberPhone.substr(0, 2) == findNum->first)
        {
            printUser(user);
        }
    }
}