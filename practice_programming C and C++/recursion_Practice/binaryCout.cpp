#include <iostream>
using namespace std;

int n;
int a[100];

void func(int step)
{
    if (step == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        return;
    }

    a[step] = 0;
    func(step + 1);
    a[step] = 1;
    func(step + 1);
}

int main()
{
    cout << "Input length of binary:";
    cin >> n;
    func(0);

    return 0;
}