#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(const vector<int> &arr, int target)
{
    int size = arr.size();
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < K; i++)
    {
        int query;
        cin >> query;

        if (binarySearch(arr, query))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}