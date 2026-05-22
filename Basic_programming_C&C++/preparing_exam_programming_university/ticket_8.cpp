#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;

    Date() : year(0), month(0), day(0) {}

    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    friend ostream &operator<<(ostream &os, const Date &d)
    {
        os << d.year << "." << d.month << "." << d.day;
        return os;
    }
};

struct Children
{
    string firstName;
    string lastName;
    Date birth;
    string parentFullName;
    int numChildren;
    double height;
    double weight;
    string group;

    Children() : firstName(""), lastName(""), birth(), parentFullName(""), numChildren(0),
                 height(0.0), weight(0.0), group("") {}

    Children(string f, string l, Date b, string p, int n, double h, double w, string g)
        : firstName(f), lastName(l), birth(b), parentFullName(p), numChildren(n), height(h), weight(w), group(g) {}
};

void inputChildren(vector<Children> &c)
{
    int count;
    cout << "Input counts of children: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        string f, l, p, g;
        int y, m, d, n;
        double h, w;

        cout << "--- Child " << i + 1 << " ---" << endl;
        cout << "First name: ";
        getline(cin, f);
        cout << "Last name: ";
        getline(cin, l);
        cout << "Date of birth (year month day): ";
        cin >> y >> m >> d;
        cin.ignore();
        cout << "Parent full name: ";
        getline(cin, p);
        cout << "Number of children in family: ";
        cin >> n;
        cout << "Height (cm): ";
        cin >> h;
        cout << "Weight (kg): ";
        cin >> w;
        cin.ignore();
        cout << "Group: ";
        getline(cin, g);

        c.push_back(Children(f, l, Date(y, m, d), p, n, h, w, g));
    }
}

void printChild(const Children &c)
{
    cout << c.firstName << " " << c.lastName << "\t"
         << c.birth << "\t"
         << c.parentFullName << "\t"
         << c.numChildren << "\t"
         << c.height << " см\t"
         << c.weight << " кг\t"
         << c.group << endl;
}

void determineInGroup(const vector<Children> &child)
{
    string g;
    cout << "Input group name: ";
    getline(cin, g);

    double totalWeight = 0.0;
    double totalHeight = 0.0;
    int countChild = 0;

    map<string, int> m;

    bool found = false;
    for (const auto &c : child)
    {
        if (c.group == g)
        {
            found = true;
            m[c.firstName]++;
            countChild++;
            totalHeight += c.height;
            totalWeight += c.weight;
        }
    }

    if (!found)
    {
        cout << "Not found group!";
        return;
    }

    auto mostPopular = max_element(m.begin(), m.end(), [](const auto &a, const auto &b)
                                   { return a.second < b.second; });

    cout << "In " << g << ": " << mostPopular->first << endl;
    cout << "Average height: " << (totalHeight / countChild) << endl;
    cout << "Average weight: " << (totalWeight / countChild) << endl;
}

void futureBasketballPlayers(const vector<Children> &child)
{
    if (child.empty())
    {
        cout << "No data." << endl;
        return;
    }

    double totalHeight = 0.0;
    for (const auto &c : child)
        totalHeight += c.height;
    double avgHeight = totalHeight / child.size();

    cout << "\n=== Average height: " << avgHeight << " cm ===\n";
    cout << "=== Future basketball players (above average height) ===\n";

    bool found = false;
    for (const auto &c : child)
    {
        if (c.height > avgHeight)
        {
            cout << c.firstName << " " << c.lastName << " (" << c.height << " cm, group " << c.group << ")" << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No children above average height." << endl;
}

void childrenInSameMonth(const vector<Children> &child)
{
    map<int, set<string>> monthChildren;

    for (const auto &c : child)
    {
        string full = c.firstName + " " + c.lastName;
        monthChildren[c.birth.month].insert(full);
    }

    cout << "\n=== Children born in the same month ===\n";

    bool found = false;
    for (const auto &entry : monthChildren)
    {
        if (entry.second.size() >= 2)
        {
            cout << "Month " << entry.first << ": ";
            for (const auto &name : entry.second)
                cout << name << ", ";
            cout << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No children born in the same month." << endl;
}