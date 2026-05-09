#include <iostream>
using namespace std;

int N = 0;
int array[20] = {0};
bool used[10] = {false};

void solveNumberCard(int i)
{
    if (i == 2 * N)
    {
        for (int j = 0; j < i; j++)
        {
            cout << array[j];
        }
        cout << endl;
        return;
    }

    if (array[i] != 0)
    {
        solveNumberCard(i + 1);
        return;
    }

    for (int k = 1; k <= N; k++)
    {
        int second = i + k + 1;
        if (used[k] == true || second >= 2 * N || array[second] != 0)
        {
            continue;
        }

        array[i] = k;
        array[second] = k;
        used[k] = true;

        solveNumberCard(i + 1);
        array[i] = 0;
        array[second] = 0;
        used[k] = false;
    }
}

int main()
{
    cout << "Input N: ";
    cin >> N;

    solveNumberCard(0);

    cout << endl;
}
