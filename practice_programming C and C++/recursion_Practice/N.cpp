#include <iostream>
using namespace std;

int steps[100] = {0};
int n;

void printResult(int i, int sum)
{
    if (sum > n)
    {
        return;
    }

    if (sum == n)
    {
        for (int j = 0; j < i; j++)
        {
            cout << steps[j];
        }
        cout << endl;
        return;
    }

    steps[i] = 1;
    printResult(i + 1, sum + 1);
    steps[i] = 2;
    printResult(i + 1, sum + 2);

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
    printResult(0, 0);
    return 0;
}