#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct ScheduleRoomComputer
{
    int month;
    int day;
    string nameTeach;
    string nameSoftware;
    string nameGroup;
    int timeInRoom;

    ScheduleRoomComputer(int m, int d, string nameT, string nameS, string nameG, int t)
        : month(m), day(d), nameTeach(nameT), nameSoftware(nameS), nameGroup(nameG), timeInRoom(t) {}

    ScheduleRoomComputer() : month(0), day(0), nameTeach(""), nameSoftware(""), nameGroup(""), timeInRoom(0) {}
};

void inputDataToStruct(vector<ScheduleRoomComputer> &v)
{
    int m = 0;
    int d = 0;
    string nameT = "";
    string nameSoft = "";
    string nameG = "";
    int time = 0;

    int count;
    cout << "Input counts of data: ";
    cin >> count;
    do
    {
        cout << "Input month: ";
        cin >> m;
        cout << "Input day: ";
        cin >> d;
        cin.ignore();
        cout << "Input name of professor: ";
        getline(cin, nameT);
        cout << "Input name of software product: ";
        getline(cin, nameSoft);
        cout << "Input name of group: ";
        getline(cin, nameG);
        cout << "Input time which group in computer room: ";
        cin >> time;
        ScheduleRoomComputer s(m, d, nameT, nameSoft, nameG, time);
        v.push_back(s);
        count--;
    } while (count);
}

void printSchedule(const vector<ScheduleRoomComputer> &v)
{
    for (const auto &s : v)
    {
        cout << s.month << "." << s.day << "\t";
        cout << s.nameTeach << "\t";
        cout << s.nameSoftware << "\t";
        cout << s.nameGroup << "\t";
        cout << s.timeInRoom << endl;
    }
}

void maxTimeGroup(const vector<ScheduleRoomComputer> &v)
{
    map<string, int> groupCount;
    for (const auto &s : v)
    {
        groupCount[s.nameGroup]++;
    }

    auto mostFrequent = max_element(groupCount.begin(), groupCount.end(),
                                    [](const auto &a, const auto &b)
                                    { return a.second < b.second; });

    cout << "Group: " << mostFrequent->first << " Counts: " << mostFrequent->second;
}

template <typename T>
void minTimeProfessor(const T &container)
{
    map<string, int> professorCount;
    for (const auto &p : container)
    {
        professorCount[p.nameTeach]++;
    }

    auto minProfessor = min_element(professorCount.begin(), professorCount.end(),
                                    [](const auto &a, const auto &b)
                                    { return a.second < b.second; });
    cout << "Professor: " << minProfessor->first << endl;
}

void printGroupSameProfessor(const vector<ScheduleRoomComputer> &v)
{
    string professor;
    cout << "Input professor name: ";
    getline(cin, professor);

    map<string, set<string>> group;
    for (const auto &g : v)
    {
        group[g.nameTeach].insert(g.nameGroup);
    }

    if (group.count(professor))
    {
        cout << "Professor " << professor << " teaches groups: ";
        for (const auto &g : group[professor])
        {
            cout << g << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Professor not found." << endl;
    }
}

void printScheduleByDate(const vector<ScheduleRoomComputer> &v)
{
    int fromMonth, fromDay, toMonth, toDay;
    cout << "From (month day): ";
    cin >> fromMonth >> fromDay;
    cout << "To (month day): ";
    cin >> toMonth >> toDay;
    cin.ignore();

    cout << "\n=== Schedule from " << fromMonth << "." << fromDay
         << " to " << toMonth << "." << toDay << " ===\n";

    bool found = false;
    for (const auto &s : v)
    {
        if ((s.month > fromMonth || (s.month == fromMonth && s.day >= fromDay)) &&
            (s.month < toMonth || (s.month == toMonth && s.day <= toDay)))
        {
            cout << s.month << "." << s.day << "\t" << s.nameTeach << "\t"
                 << s.nameGroup << "\t" << s.timeInRoom << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No period." << endl;
}

void timeGroupInWeek(const vector<ScheduleRoomComputer> &v)
{
    string groupName;
    cout << "Input group name: ";
    getline(cin, groupName);

    int totalCount = 0;
    for (const auto &s : v)
    {
        if (s.nameGroup == groupName)
        {
            totalCount++;
        }
    }

    cout << "Group " << groupName << " had "
         << totalCount << endl;
}

void printCase()
{
    cout << endl;
    cout << "=== Choice Selection ===" << endl;
    cout << "1. Input data" << endl;
    cout << "2. Print data" << endl;
    cout << "3. Find group which max time in computer room" << endl;
    cout << "4. Find professor which min time in computer room" << endl;
    cout << "5. print groups of same professor" << endl;
    cout << "6. Print schedule by date" << endl;
    cout << "7. Time of group in week" << endl;
    cout << "0. Exit" << endl;
}

int main()
{
    vector<ScheduleRoomComputer> schedule;

    int choice = 0;
    do
    {
        printCase();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            inputDataToStruct(schedule);
            break;
        case 2:
            printSchedule(schedule);
            break;
        case 3:
            maxTimeGroup(schedule);
            break;
        case 4:
            minTimeProfessor(schedule);
            break;
        case 5:
            printGroupSameProfessor(schedule);
            break;
        case 6:
            printScheduleByDate(schedule);
            break;
        case 7:
            timeGroupInWeek(schedule);
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}