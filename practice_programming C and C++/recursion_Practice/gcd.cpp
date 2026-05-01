#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int num1, num2;
    cout << "Input num1: ";
    cin >> num1;
    cout << "Input num2: ";
    cin >> num2;

    cout << "gcd: " << gcd(num1, num2);

    return 0;
}