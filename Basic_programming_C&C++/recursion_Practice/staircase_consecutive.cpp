#include <iostream>
using namespace std;

int steps[100] = {0};
int n;
int count = 0;

void printResult(int i, int sum, int prev, int count)
{
    if (n < sum)
    {
        return;
    }

    if (sum == n)
    {
        if (count < 2)
        {
            return;
        }
        for (int j = 0; j < i; j++)
        {
            cout << steps[j] << " ";
        }
        cout << endl;
        return;
    }

    steps[i] = 1;
    if (prev == 1)
        printResult(i + 1, sum + 1, 1, count + 1);
    else if (count >= 2 || prev == 0)
        printResult(i + 1, sum + 1, 1, 1);

    steps[i] = 2;
    if (prev == 2)
        printResult(i + 1, sum + 2, 2, count + 1);
    else if (count >= 2 || prev == 0)
        printResult(i + 1, sum + 2, 2, 1);

    steps[i] = 0;
}

int main()
{
    cout << "Input N (N < 15): ";
    cin >> n;
    while (n >= 15 || n < 1)
    {
        cout << "Must input number (N < 15)! Input again:";
        cin >> n;
    }
    printResult(0, 0, 0, 0);
    return 0;
}