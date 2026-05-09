#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int n = 0;
int weights[1000] = {0};
set<int> resultSet;

void solve(int i, int sum)
{
    if (i == n)
    {
        if (sum > 0)
        {
            resultSet.insert(sum);
        }
        return;
    }

    solve(i + 1, sum);
    solve(i + 1, sum + weights[i]);
    solve(i + 1, sum - weights[i]);
}

int main()
{
    cout << "Input amount of weights (<10): ";
    cin >> n;

    cout << "Input weight of weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    solve(0, 0);

    for (int w : resultSet)
    {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}