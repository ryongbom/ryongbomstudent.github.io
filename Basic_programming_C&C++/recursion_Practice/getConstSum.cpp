#include <iostream>
using namespace std;

int n;
int ops[10];

void func(int num, int sum)
{
    if (num == 10)
    {
        if (sum == n)
        {
            cout << "1 ";

            for (int i = 2; i < 10; i++)
            {
                if (ops[i] == 1)
                    cout << "+ " << i << " ";
                else
                    cout << "- " << i << " ";
            }

            cout << "= " << n << endl;
        }
        return;
    }
    ops[num] = 0;
    func(num + 1, sum - num);
    ops[num] = 1;
    func(num + 1, sum + num);
}

int main()
{
    cout << "Input const Sum: ";
    cin >> n;

    func(2, 1);

    return 0;
}