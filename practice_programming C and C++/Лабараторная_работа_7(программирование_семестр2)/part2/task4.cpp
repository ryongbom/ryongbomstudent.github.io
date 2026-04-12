// Inserting sort

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    // cout << "Input length of array: ";
    cin >> n;
    vector<int> arr(n);

    // cout << "Input elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // first I thought here. but it was false
        // while (j >= 0)
        // {
        //     if (arr[j] > key)
        //     {
        //         arr[j + 1] = arr[j];
        //     }
        //     j--;
        // }

        // in true way here
        // while (j >= 0)
        // {
        //     if (arr[j] > key)
        //     {
        //         arr[j + 1] = arr[j];
        //         j--;
        //     }
        //     else
        //         break;
        // }

        arr[j + 1] = key;
    }

    // cout << "Inserting sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}