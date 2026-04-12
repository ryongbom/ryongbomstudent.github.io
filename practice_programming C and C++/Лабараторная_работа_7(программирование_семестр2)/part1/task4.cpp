#include <iostream>

using namespace std;

int uklid(int a, int b)
{
    do
    {
        int temp = a % b;
        a = b;
        b = temp;
    } while (b);
    return a;
}

int main()
{
    int a, b;
    cout << "Input nums to work: ";
    cin >> a >> b;

    int c = uklid(a, b);
    cout << c << endl;

    return 0;
}