#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Person
{
    string fullName;
    int year;
    string sex;
    string city;
    string education;
    int numChildren;
    string placeWork;

    Person() : fullName(""), year(0), sex(""), city(""), education(""), numChildren(0), placeWork("") {}

    Person(string ful, int y, string s, string c, string e, int n, string p)
        : fullName(ful), year(y), sex(s), city(c), education(e), numChildren(n), placeWork(p) {}
};

void inputPersonInformation(vector<Person> &p)
{
    int count;
    cout << "Input counts of people: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        string ful, s, c, e, pw;
        int y, n;

        cout << "--- Person " << i + 1 << " ---" << endl;
        cout << "Full name: ";
        getline(cin, ful);
        cout << "Year of birth: ";
        cin >> y;
        cin.ignore();
        cout << "Sex (male/female): ";
        getline(cin, s);
        cout << "City: ";
        getline(cin, c);
        cout << "Education: ";
        getline(cin, e);
        cout << "Number of children: ";
        cin >> n;
        cin.ignore();
        cout << "Place of work: ";
        getline(cin, pw);

        p.push_back(Person(ful, y, s, c, e, n, pw));
    }
}

void averageAge(const vector<Person> &p)
{
    int currentYear = 2026;

    int maleSum = 0, maleCount = 0;
    int femaleSum = 0, femaleCount = 0;

    for (const auto &person : p)
    {
        if (person.sex == "male")
        {
            maleCount++;
            maleSum += (currentYear - person.year);
        }
        else
        {
            femaleCount++;
            femaleSum += (currentYear - person.year);
        }
    }
    if (maleCount > 0)
        cout << "Average of male age: " << static_cast<double>(maleSum) / maleCount << endl;
    else
        cout << "No male data." << endl;

    if (femaleCount > 0)
        cout << "Average of female age: " << static_cast<double>(femaleSum) / femaleCount << endl;
    else
        cout << "No female data." << endl;
}

void percentHighEducation(const vector<Person> &p)
{
    int countResult = count_if(p.begin(), p.end(), [](const auto &a)
                               { return a.education == "higher" });

    if (!p.empty())
    {
        cout << "Percent high education: " << static_cast<double>(countResult) / (p.size()) * 100 << "%" << endl;
    }
    else
        cout << "No data." << endl;
}

void maxPersonCity(const vector<Person> &p)
{
    map<string, int> city;

    for (const auto &c : p)
    {
        city[c.city]++;
    }

    auto resultCity = max_element(city.begin(), city.end(),
                                  [](const auto &a, const auto &b)
                                  { return a.second < b.second; });

    cout << "City: " << resultCity->first << endl;
}

void findPersonSameNameInSameCity(const vector<Person> &p)
{
    map<string, set<string>> sameSurnameInCity;

    for (const auto &el : p)
    {
        string surname = el.fullName.substr(0, el.fullName.find(' '));
        string key = surname + " " + el.city;
        sameSurnameInCity[key].insert(el.fullName);
    }

    for (const auto &pair : sameSurnameInCity)
    {
        const string &key = pair.first;
        const set<string> &names = pair.second;

        if (names.size() >= 2)
        {
            cout << key << ": ";
            for (const auto &n : names)
                cout << n << ", ";
            cout << endl;
        }
    }
}

void findBySurnameAndYear(const vector<Person> &p)
{
    string pSurname;
    int pYear;

    cout << "Input surname: ";
    getline(cin, pSurname);
    cout << "Input year of birth: ";
    cin >> pYear;
    cin.ignore();

    bool found = false;
    for (const auto &per : p)
    {
        string surname = per.fullName.substr(0, per.fullName.find(' '));
        if (surname == pSurname && per.year == pYear)
        {
            cout << per.fullName << ", " << per.year << ", "
                 << per.sex << ", " << per.city << ", "
                 << per.education << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Not found." << endl;
}