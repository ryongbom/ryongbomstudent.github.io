#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int numSet;

    cout << "Input number of sets: ";
    cin >> numSet;

    vector<string> result;

    for (int i = 0; i < numSet; i++)
    {
        int size;
        cout << "Set " << i + 1 << ": input size of element: ";
        cin >> size;

        cout << "Set " << i + 1 << ": input elements: ";
        for (int j = 0; j < size; j++)
        {
            string element;
            cin >> element;
            result.push_back(element);
        }
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    cout << "Union of sets: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}