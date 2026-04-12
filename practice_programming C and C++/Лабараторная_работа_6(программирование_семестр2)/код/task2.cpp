#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <unordered_set>
#include <numeric>
#include <chrono> // time???

using namespace std;

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

int main()
{
    cout << "========== TASK2 (variant1) ==========" << endl;

    cout << endl;
    cout << "--- 1. Create random nums ---" << endl;
    const int M1 = -10;
    const int M2 = 10;
    const int SIZE = 20;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(M1, M2);

    vector<int> vec(SIZE);
    generate(vec.begin(), vec.end(), [&]()
             { return dist(gen); });

    printContainer(vec, "created random numbers");

    auto max_abs_it = max_element(vec.begin(), vec.end(),
                                  [](int a, int b)
                                  {
                                      return abs(a) < abs(b);
                                  });

    if (max_abs_it != vec.end())
    {
        cout << "abs max element: " << *max_abs_it << " (|" << abs(*max_abs_it) << "|)" << endl;
    }

    cout << endl;
    cout << "--- 2. Replace numbers less than 0 with 0 ---" << endl;

    vector<int> vec2 = vec;
    printContainer(vec2, "before change");

    replace_if(vec2.begin(), vec2.end(), [](int x)
               { return x < 0; }, 0);

    printContainer(vec2, "after change");

    cout << "\n--- 3. Remove duplicates (keep first) ---" << endl;

    vector<int> unique_vec;
    unordered_set<int> seen;

    for (int num : vec)
    {
        if (seen.find(num) == seen.end())
        {
            unique_vec.push_back(num);
            seen.insert(num);
        }
    }

    printContainer(unique_vec, "after removing duplicates");
    cout << "Removed " << (vec.size() - unique_vec.size()) << " duplicates" << endl;

    return 0;
}