#include <iostream>
using namespace std;

int arr[100] = {0};
int n = 0;
bool used[100] = {false};

bool sisu(int k)
{
    if (k < 2)
        return false;
    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
            return false;
    }
    return true;
}

void printSisuCircle(int i, int prev)
{
    if (i == n)
    {
        if (!sisu(arr[n - 1] + 1))
            return;

        for (int j = 0; j < i; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
        return;
    }

    for (int k = 2; k <= n; k++)
    {
        if (!sisu(k + prev) || used[k])
            continue;

        arr[i] = k;
        used[k] = true;
        printSisuCircle(i + 1, k);

        used[k] = false;
        arr[i] = 0;
    }
}

int main()
{
    do
    {
        cout << "Input number n: ";
        cin >> n;
    } while (n < 1);

    arr[0] = 1;
    used[1] = true;

    printSisuCircle(1, 1);

    return 0;
}