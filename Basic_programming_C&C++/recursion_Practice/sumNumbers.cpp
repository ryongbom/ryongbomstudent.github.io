#include <iostream>
using namespace std;

int n = 0;
int m = 0;
int nums[1000];
int result[1000] = {0};
bool used[1000] = {false};

void printResult(int i, int prev, int sum)
{
    if (sum > m || i > n)
    {
        return;
    }
    if (sum == m)
    {
        for (int j = 0; j < i; j++)
        {
            cout << result[j] << " ";
        }
        cout << endl;
        return;
    }

    for (int u = 0; u < n; u++)
    {
        if (used[nums[u]] == true || nums[u] < prev)
        {
            continue;
        }
        result[i] = nums[u];
        used[nums[u]] = true;

        printResult(i + 1, nums[u], sum + nums[u]);
        used[nums[u]] = false;
    }
}

int main()
{
    cout << "Input length of array of numbers: ";
    cin >> n;

    cout << "Input elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Sum of numbers: ";
    cin >> m;

    printResult(0, 0, 0);

    return 0;
}