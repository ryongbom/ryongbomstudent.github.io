#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;

    Date() : year(0), month(0), day(0) {}

    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    bool operator<(const Date &other) const // const => it is important!
    {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }

    friend ostream &operator<<(ostream &os, const Date &d)
    {
        os << d.year << "." << d.month << "." << d.day;
        return os;
    }
};

struct Document
{
    string attribute;
    string type;
    string departmentNameFrom;
    string departmentNameTo;
    Date arrivalDate;

    Document() : attribute(""), type(""), departmentNameFrom(""),
                 departmentNameTo(""), arrivalDate() {}

    Document(string attr, string t, string from, string to, Date d)
        : attribute(attr), type(t), departmentNameFrom(from),
          departmentNameTo(to), arrivalDate(d) {}
};

void inputDocuments(vector<Document> &docs)
{
    int count;
    cout << "Input counts of documents: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        string attr, type, from, to;
        int y, m, d;

        cout << "--- Document " << i + 1 << " ---" << endl;
        cout << "Attribute (include/out): ";
        getline(cin, attr);
        cout << "Type: ";
        getline(cin, type);
        cout << "Department (from): ";
        getline(cin, from);
        cout << "Department (to): ";
        getline(cin, to);
        cout << "Date of arrival (year month day): ";
        cin >> y >> m >> d;
        cin.ignore();

        docs.push_back(Document(attr, type, from, to, Date(y, m, d)));
    }
}

void printDocument(const Document &d)
{
    cout << d.attribute << "\t" << d.type << "\t"
         << d.departmentNameFrom << " -> " << d.departmentNameTo << "\t"
         << d.arrivalDate << endl;
}

void documentsLastTwoDays(const vector<Document> &docs)
{
    int y, m, d;
    cout << "Input current date (year month day): ";
    cin >> y >> m >> d;
    cin.ignore();
    Date current(y, m, d);

    Date twoDaysAgo = current;
    twoDaysAgo.day -= 2;

    cout << "\n=== Document from " << twoDaysAgo << " to " << current << " ===\n";

    bool found = false;
    for (const auto &doc : docs)
    {
        if (!(doc.arrivalDate < twoDaysAgo) && !(current < doc.arrivalDate))
        {
            printDocument(doc);
            found = true;
        }
    }
    if (!found)
        cout << "Нет документов." << endl;
}

void findDocumentByType(const vector<Document> &docs)
{
    string type;
    cout << "Input type: ";
    getline(cin, type);

    bool found = false;
    for (const auto &doc : docs)
    {
        if (doc.type == type)
        {
            printDocument(doc);
            found = true;
        }
    }
    if (!found)
        cout << "Not found." << endl;
}

void countDocumentsPerDay(const vector<Document> &docs)
{
    map<string, int> dailyCount;

    for (const auto &doc : docs)
    {
        string key = to_string(doc.arrivalDate.year) + "." + to_string(doc.arrivalDate.month) + "." + to_string(doc.arrivalDate.day);
        dailyCount[key]++;
    }

    cout << "\n=== Documents count in day ===\n";
    for (const auto &entry : dailyCount)
    {
        cout << entry.first << ": " << entry.second << " documents" << endl;
    }
}