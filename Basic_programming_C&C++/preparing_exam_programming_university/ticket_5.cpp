#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Subscriber
{
    int index;
    string namePublication;
    int periodMonths;
    string lastName;
    string address;
    double cost;
    string postOfficeNumber;

    Subscriber() : index(0), namePublication(""), periodMonths(0), lastName(""), address(""), cost(0.0), postOfficeNumber("") {}

    Subscriber(int i, string n, int p, string l, string add, double c, string pn)
        : index(i), namePublication(n), periodMonths(p), lastName(l), address(add), cost(c), postOfficeNumber(pn) {}
};

void inputInformationOfSubscriber(vector<Subscriber> &s)
{
    cout << "Input numbers of subscribers: ";
    int count;
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        int in;
        cout << "Input index of publication: ";
        cin >> in;
        cin.ignore();
        string n;
        cout << "Input name of publication: ";
        getline(cin, n);
        int p;
        cout << "Input period of subscrib(months): ";
        cin >> p;
        cin.ignore();
        string l;
        cout << "Input last name of subscriber: ";
        getline(cin, l);
        string add;
        cout << "Input address of subscriber: ";
        getline(cin, add);
        double c;
        cout << "Input cost of monthly subscription: ";
        cin >> c;
        cin.ignore();
        string pn;
        cout << "Input post office number: ";
        getline(cin, pn);
        s.push_back(Subscriber(in, n, p, l, add, c, pn));
    }
}

void printListOfSubscriber(const Subscriber &s)
{
    cout << s.index << "\t" << s.namePublication << "\t" << s.periodMonths << "\t" << s.lastName
         << "\t" << s.address << "\t" << s.cost << "\t" << s.postOfficeNumber << endl;
}

void findSubscribersByPostOfficeNumber(const vector<Subscriber> &sub)
{
    string postNumber;
    cout << "Input a single post office number: ";
    getline(cin, postNumber);

    cout << "Post office " << postNumber << ": " << endl;

    bool found = false;
    for (const auto &s : sub)
    {
        if (s.postOfficeNumber == postNumber)
        {
            printListOfSubscriber(s);
            found = true;
        }
    }
    if (!found)
        cout << "Not found subscriber" << endl;
}

void findBySubscriber(const vector<Subscriber> &sub)
{
    string subscriber;
    cout << "Input last name of subscriber: ";
    getline(cin, subscriber);

    double totalCost;

    bool found = false;
    for (const auto &s : sub)
    {
        if (s.lastName == subscriber)
        {
            cout << s.namePublication << ": ";
            cout << s.periodMonths * s.cost << endl;
            totalCost += s.periodMonths * s.cost;
            found = true;
        }
    }
    if (!found)
        cout << "Not found subscriber" << endl;
    else
        cout << "Total Cost: " << totalCost << endl;
}

void mostPopularPublication(const vector<Subscriber> &sub)
{
    map<string, int> m;
    bool found = false;
    for (const auto &s : sub)
    {
        m[s.namePublication]++;
    }

    auto result = max_element(m.begin(), m.end(), [](const auto &a, const auto &b)
                              { return a.second < b.second; });

    cout << "Most popular publication: " << result->first << endl;
}