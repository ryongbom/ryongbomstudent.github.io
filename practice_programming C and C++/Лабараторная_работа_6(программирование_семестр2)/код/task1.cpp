#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

struct Person
{
    string surname;
    string name;
    int age;

    Person(const string &st, const string &n, int a) : surname(st), name(n), age(a) {}

    Person() : surname(""), name(""), age(0) {}

    bool operator<(const Person &other) const
    {
        if (age != other.age)
            return age < other.age;
        if (surname != other.surname)
            return surname < other.surname;
        return name < other.name;
    }

    friend ostream &operator<<(ostream &os, const Person &p)
    {
        os << "[" << p.surname << " " << p.name << " " << p.age << "age]";
        return os;
    }
};

template <typename T>
void printContainer(const T &container, const string &name)
{
    cout << name << ": ";

    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
}

template <typename K, typename V>
void printMap(const map<K, V> &m, const string &name)
{
    cout << name << ": ";

    for (typename map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << "{" << it->first << ":" << it->second << "} ";
    }
    cout << endl;
}

// it is function to save vector to file
void saveVectorToFile(const vector<int> &vec, const string &filename)
{
    ofstream outFile(filename);

    if (!outFile.is_open())
    {
        cerr << "Can not open file: " << filename << endl;
        return;
    }

    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        outFile << *it << " ";
    }

    outFile.close();
    cout << "Completed saved to " << filename << endl;
}

// it is function to load vector from file
vector<int> loadVectorFromFile(const string &filename)
{
    vector<int> result;
    ifstream inFile(filename);

    if (!inFile.is_open())
    {
        cerr << "Can not open file: " << filename << endl;
        return result;
    }

    int value;
    while (inFile >> value)
    {
        result.push_back(value);
    }
    inFile.close();
    cout << "Completed load vector from " << filename << endl;
    return result;
}

int main()
{
    cout << "========== init container ==========" << endl;
    cout << endl;

    cout << "--- array container ---" << endl;

    array<int, 5> arr1;
    array<int, 5> arr2 = {10, 20, 30, 40, 50};
    array<int, 5> arr3;
    arr3.fill(100);
    array<int, 5> arr4(arr2);

    printContainer(arr2, "arr2 (every element init)");
    printContainer(arr3, "arr3 (used fill())");
    printContainer(arr4, "arr4 (copy used)");
    cout << endl;

    cout << "--- vector container ---" << endl;
    vector<int> vec1;
    vector<int> vec2 = {1, 2, 3, 4, 5};
    vector<int> vec3(10, 7);
    vector<int> vec4(vec2.begin(), vec2.end());
    vector<int> vec5;
    vec5.assign({100, 200, 300});

    printContainer(vec2, "vec2 (every element init)");
    printContainer(vec3, "vec3 (fill 7 in 10 elements)");
    printContainer(vec4, "vec4 (vec2 copied)");
    printContainer(vec5, "vec5 (used assign())");
    cout << endl;

    cout << "--- list container ---" << endl;
    list<int> list1;
    list<int> list2 = {5, 10, 15, 20};
    list<int> list3(3, 5);
    list<int> list4(vec2.begin(), vec2.end());

    printContainer(list2, "list2 (every element init)");
    printContainer(list3, "list3 (fill 3 in 5 elements)");
    printContainer(list4, "list4 (vec2 copied)");
    cout << endl;

    cout << "--- set container ---" << endl;
    set<int> set1;
    set<int> set2 = {10, 20, 30, 5, 15, 25, 70, 35};
    set<int> set3(vec2.begin(), vec2.end());
    set<int> set4;
    set4.insert(100);
    set4.insert(200);
    set4.insert(150);

    printContainer(set2, "set2 (init)");
    printContainer(set3, "set3 (vec2, copied)");
    printContainer(set4, "set4 (used insert())");
    cout << endl;

    cout << "--- map container ---" << endl;
    map<int, string> map1;
    map<int, string> map2 = {
        {1, "one"},
        {2, "two"},
        {3, "three"}};
    map<int, string> map3;
    map3.insert(make_pair(10, "10"));
    map3.insert({20, "twenty"});
    map3[30] = "thirty";

    map<int, string> map4(map2);

    printMap(map2, "map2 (init list)");
    printMap(map3, "map3 (insert with several methods)");
    printMap(map4, "map4 (map2 copied)");
    cout << endl;

    cout << "--- multimap container ---" << endl;

    multimap<int, int> mmap1;
    multimap<int, int> mmap2 = {
        {1, 100},
        {1, 200},
        {2, 300},
        {3, 400}};
    multimap<int, int> mmap3;
    mmap3.insert({5, 500});
    mmap3.insert({5, 550});

    cout << "mmap2: ";
    for (multimap<int, int>::const_iterator it = mmap2.begin(); it != mmap2.end(); ++it)
    {
        cout << "{" << it->first << ":" << it->second << "} ";
    }
    cout << endl;
    for (const auto &p : mmap3)
    {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << endl;

    cout << "--- unordered_set container ---" << endl;

    unordered_set<int> uset1;
    unordered_set<int> uset2 = {5, 6, 3, 8, 9, 1, 11, 2};
    unordered_set<int> uset3(vec2.begin(), vec2.end());
    unordered_set<int> uset4;
    uset4.insert(100);
    uset4.insert(200);
    uset4.insert(150);
    uset4.insert({300, 400, 500});

    printContainer(uset2, "uset2 (init list)");
    printContainer(uset3, "uset3 (vec2 copied)");
    printContainer(uset4, "uset4 (insert() used)");
    cout << endl;

    cout << "========== Container operator and file I/O ==========" << endl;

    cout << "--- vector operator ---" << endl;
    vector<int> v = {10, 20, 30, 40, 50};
    printContainer(v, "first time vector");

    v.insert(v.begin() + 2, 25);
    printContainer(v, "insert 25 in index 2");

    cout << "Finding 40 in vector v: ";
    vector<int>::iterator it = find(v.begin(), v.end(), 40);
    if (it != v.end())
    {
        cout << "Found 40" << endl;
        *it = 99;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    printContainer(v, "changed 40 to 99");

    v.erase(v.begin() + 1);
    printContainer(v, "delete in index 2");

    cout << endl;
    cout << "--- list operations ---" << endl;
    list<int> lst = {10, 20, 30, 40, 50};
    printContainer(lst, "first list");

    auto it_list = lst.begin();
    advance(it_list, 2);
    lst.insert(it_list, 12);
    printContainer(lst, "insert 12 in index 2");

    cout << "finding 20 in list: ";
    auto lit = find(lst.begin(), lst.end(), 20);
    if (lit != lst.end())
    {
        cout << "Found 20" << endl;
        *lit = 99;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    printContainer(lst, "changed 20 to 99");
    lst.pop_front();
    printContainer(lst, "deleted first element of list");

    cout << endl;
    cout << "--- map operations ---" << endl;

    map<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
    printMap(m, "first map");

    m.insert({4, "four"});
    m[5] = "five";
    auto it_map = m.find(2);

    if (it_map != m.end())
    {
        cout << "Found key 2: value = " << it_map->second << endl;
        it_map->second = "TWO";
    }
    else
    {
        cout << "Not Found key 2" << endl;
    }
    m.erase(3);
    printMap(m, "final map");

    cout << endl;
    cout << "--- Set Person operations ---" << endl;

    set<Person> people;
    people.insert(Person("Kim", "SongChol", 20));
    people.insert(Person("Yang", "SonWon", 35));
    people.insert(Person("Pak", "SongIl", 40));
    people.insert(Person("Choe", "hyongSik", 15));
    people.insert(Person("Kim", "SongChol", 20));

    cout << "Size of set<Person> people: " << people.size() << endl;

    cout << "Elements of set<Person> people: ";
    for (set<Person>::const_iterator it = people.begin(); it != people.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << endl;
    cout << "--- File I/O test ---" << endl;

    vector<int> vecData;
    for (int i = 0; i < 10; i++)
    {
        vecData.push_back(i * 10);
    }
    printContainer(vecData, "data to save");

    saveVectorToFile(vecData, "data.txt");

    vector<int> loadedVec = loadVectorFromFile("data.txt");
    printContainer(loadedVec, "loaded data");

    return 0;
}