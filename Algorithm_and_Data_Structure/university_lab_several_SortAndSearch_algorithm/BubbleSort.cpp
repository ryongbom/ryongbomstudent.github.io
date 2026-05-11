// Bubble sort

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int swapCount = 0;
    cout << "Input length of array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Input elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Swap count: " << swapCount << endl;

    return 0;
}