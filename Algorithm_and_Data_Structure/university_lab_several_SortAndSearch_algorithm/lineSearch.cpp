#include <iostream>
#include <vector>
using namespace std;

int getCount(const vector<int> &v, int target)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int target;
    int n;
    vector<int> vec;

    cout << "Input length of array: ";
    cin >> n;
    cout << "Input array:";

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    cout << "Input target: ";
    cin >> target;

    int count = getCount(vec, target);
    cout << "Result: " << count << endl;

    return 0;
}