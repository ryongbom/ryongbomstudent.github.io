#include <iostream>
using namespace std;

int n;
int m;
int arr[100] = {0};

void numbersArray(int i, int prev)
{
    if (i == m)
    {
        for (int j = 0; j < i; j++)
        {
            cout << arr[j];
        }
        cout << endl;
        return;
    }

    for (int k = 1; k <= n; k++)
    {
        if (i != 0 && k == prev)
        {
            continue;
        }
        arr[i] = k;
        numbersArray(i + 1, k);
    }

    arr[i] = 0;
}

int main()
{
    do
    {
        cout << "Input number n (<10): ";
        cin >> n;
        cout << "Input length m: ";
        cin >> m;
    } while (n >= 10 || n < 1);

    numbersArray(0, 0);

    return 0;
}