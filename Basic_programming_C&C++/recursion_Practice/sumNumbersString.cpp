#include <iostream>
#include <string>
using namespace std;

char signResult[9] = {};
int n = 0;

void solve(int i, int sum, int currentNum)
{
    if (i == 10)
    {
        if (sum + currentNum == n)
        {
            cout << "1";
            for (int j = 2; j <= 9; j++)
            {
                if (signResult[j] == ' ')
                    cout << j;
                else
                    cout << " " << signResult[j] << " " << j;
            }
            cout << "= " << n << endl;
        }
        return;
    }

    signResult[i] = '+';
    solve(i + 1, sum + currentNum, i);

    signResult[i] = '-';
    solve(i + 1, sum + currentNum, -i);

    signResult[i] = ' ';

    if (currentNum >= 0)
        solve(i + 1, sum, currentNum * 10 + i);
    else
        solve(i + 1, sum, currentNum * 10 - i);
}

int main()
{
    cout << "input n: ";
    cin >> n;

    solve(2, 0, 1);

    return 0;
}