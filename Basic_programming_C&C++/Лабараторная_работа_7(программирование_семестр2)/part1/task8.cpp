#include <iostream>
using namespace std;

int getPibonatch(int n)
{
    int a = 1;
    int b = 1;

    if (n == 0)
    {
        return 0;
    }
    if (n < 3)
    {
        return 1;
    }
    else
    {
        int next = 0;
        for (int i = 3; i <= n; i++)
        {
            next = a + b;
            a = b;
            b = next;
        }
        return next;
    }
}

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;

    int result = getPibonatch(n);

    cout << "Result: " << result << endl;

    return 0;
}