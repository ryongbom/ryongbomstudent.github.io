#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

struct Person
{
    string surname;
    string name;
    int age;

    Person(const string &st, const string &n, int a) : surname(st), name(n), age(a) {}

    Person() : surname(""), name(""), age(0) {}

    friend ostream &operator<<(ostream &os, const Person &p)
    {
        os << "[" << p.surname << " " << p.name << " " << p.age << "age]";
        return os;
    }
};

struct ComparePersonByAge
{
    bool operator()(const Person &a, const Person &b) const
    {
        return a.age < b.age;
    }
};

int main()
{
    multiset<Person, ComparePersonByAge> people;

    people.insert(Person("Kim", "CholSu", 25));
    people.insert(Person("Lee", "YoungHui", 25));
    people.insert(Person("Park", "Minsu", 30));
    people.insert(Person("Choe", "Jinhyok", 22));

    cout << "People in multiset (age):" << endl;

    for (const auto p : people)
    {
        cout << "  " << p << endl;
    }

    cout << "Size: " << people.size() << endl;

    cout << "\n--- Search Operations ---" << endl;

    // 1. count()
    int age25count = people.count(Person("", "", 25));
    cout << "Number of people aged 25: " << age25count << endl;

    // 2. find()
    auto it = people.find(Person("", "", 30));
    if (it != people.end())
    {
        cout << "Found: " << *it << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    // 3. equal_range()
    auto range = people.equal_range(Person("", "", 25));
    cout << "Everyone aged 25: " << endl;

    for (auto it2 = range.first; it2 != range.second; ++it2)
    {
        cout << "  " << *it2 << endl;
    }

    cout << "\n--- Range Search ---" << endl;

    // 4. lower_bound()
    auto low = people.lower_bound(Person("", "", 25));
    cout << "First person with age >= 25: " << *low << endl;

    // 5. upper_bound()
    auto up = people.upper_bound(Person("", "", 25));
    cout << "First person with age > 25: " << *up << endl;

    // 6. print
    cout << "People with age 25 <= age < 30: " << endl;
    for (auto it3 = low; it3 != up; ++it3)
    {
        cout << "  " << *it3 << endl;
    }

    cout << endl;
    cout << "========== PERFORMANCE TEST ==========" << endl;

    const int TEST_SIZE = 100000;
    vector<int> testData;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100000);

    for (int i = 0; i < TEST_SIZE; i++)
    {
        testData.push_back(dist(gen));
    }

    cout << "size of testData: " << TEST_SIZE << endl
         << endl;

    // 1. vector insert time
    auto start = chrono::high_resolution_clock::now();
    vector<int> vec;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        vec.push_back(testData[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto vecTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "vector insert: " << vecTime << " ms" << endl;

    // 2. list insert time
    start = chrono::high_resolution_clock::now();
    list<int> lst;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        lst.push_back(testData[i]);
    }
    end = chrono::high_resolution_clock::now();
    auto lstTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "list insert: " << lstTime << " ms" << endl;

    // 3. set insert time
    start = chrono::high_resolution_clock::now();
    set<int> s;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        s.insert(testData[i]);
    }
    end = chrono::high_resolution_clock::now();
    auto setTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "set insert: " << setTime << " ms" << endl;

    // 4. unordered_set insert time
    start = chrono::high_resolution_clock::now();
    unordered_set<int> us;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        us.insert(testData[i]);
    }
    end = chrono::high_resolution_clock::now();
    auto usTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "unordered_set insert: " << usTime << " ms" << endl;

    cout << endl;
    cout << "--- Search Time comparing ---" << endl;
    int searchValue = testData[TEST_SIZE / 2];

    // vector 검색
    start = chrono::high_resolution_clock::now();
    find(vec.begin(), vec.end(), searchValue);
    end = chrono::high_resolution_clock::now();
    auto vecSearch = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "vector search: " << vecSearch << " μs" << endl;

    // set 검색
    start = chrono::high_resolution_clock::now();
    s.find(searchValue);
    end = chrono::high_resolution_clock::now();
    auto setSearch = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "set search: " << setSearch << " μs" << endl;

    // unordered_set 검색
    start = chrono::high_resolution_clock::now();
    us.find(searchValue);
    end = chrono::high_resolution_clock::now();
    auto usSearch = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "unordered_set search: " << usSearch << " μs" << endl;

    // 7. 이론적 예상과 비교
    cout << "\n=== Theoretical Expectation ===" << endl;
    cout << "Vector Insertion: O(1) (Append to End) - Actual: " << vecTime << " ms" << endl;
    cout << "List Insertion: O(1) - Actual: " << lstTime << " ms" << endl;
    cout << "Set Insertion: O(log n) - Actual: " << setTime << " ms" << endl;
    cout << "Unordered_set Insertion: Average O(1) - Actual: " << usTime << " ms" << endl;

    return 0;
}