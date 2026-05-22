#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct StudentWork
{
    int yearDefense;
    string workType;
    string topic;
    string studentName;
    string group;
    string supervisor;

    StudentWork() : yearDefense(0), workType(""), topic(""),
                    studentName(""), group(""), supervisor("") {}

    StudentWork(int y, string w, string t, string s, string g, string sup)
        : yearDefense(y), workType(w), topic(t), studentName(s),
          group(g), supervisor(sup) {}
};

void inputWorks(vector<StudentWork> &v)
{
    int count;
    cout << "Input counts of works: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        int y;
        string w, t, s, g, sup;

        cout << "--- Work " << i + 1 << " ---" << endl;
        cout << "Year of defense: ";
        cin >> y;
        cin.ignore();
        cout << "Type (diploma project/diploma thesis/course project/course work): ";
        getline(cin, w);
        cout << "Topic: ";
        getline(cin, t);
        cout << "Student full name: ";
        getline(cin, s);
        cout << "Group: ";
        getline(cin, g);
        cout << "Supervisor: ";
        getline(cin, sup);

        v.push_back(StudentWork(y, w, t, s, g, sup));
    }
}

void printWork(const StudentWork &w)
{
    cout << w.yearDefense << "\t" << w.workType << "\t"
         << w.topic << "\t" << w.studentName << "\t"
         << w.group << "\t" << w.supervisor << endl;
}

void diplomaByProfessor(const vector<StudentWork> &v)
{
    map<string, vector<StudentWork>> professorWorks;

    for (const auto &w : v)
    {
        if (w.workType == "diploma project" || w.workType == "diploma thesis")
        {
            professorWorks[w.supervisor].push_back(w);
        }
    }

    for (auto &entry : professorWorks)
    {
        sort(entry.second.begin(), entry.second.end(), [](const auto &a, const auto &b)
             { return a.studentName < b.studentName; });

        cout << "\n=== Supervisor: " << entry.first << " ===\n";
        for (const auto &w : entry.second)
            printWork(w);
    }
}

void worksByGroupAndYear(const vector<StudentWork> &v)
{
    string group;
    int year;
    cout << "Input group: ";
    getline(cin, group);
    cout << "Input year: ";
    cin >> year;
    cin.ignore();

    cout << "\n=== Works of " << group << " in " << year << " ===\n";
    bool found = false;
    for (const auto &w : v)
    {
        if (w.group == group && w.yearDefense == year)
        {
            printWork(w);
            found = true;
        }
    }
    if (!found)
        cout << "Not found." << endl;
}

void searchByStudent(const vector<StudentWork> &v)
{
    string name;
    cout << "Input student full name: ";
    getline(cin, name);

    bool found = false;
    for (const auto &w : v)
    {
        if (w.studentName == name)
        {
            printWork(w);
            found = true;
        }
    }
    if (!found)
        cout << "Not found." << endl;
}