#include <iostream>

using namespace std;

int main()
{
    int m;
    int n;

    cout << "input m: ";
    cin >> m;
    cout << "input n: ";
    cin >> n;

    int result_pow = 1 << m;
    cout << "2 ^ " << m << " = " << result_pow << endl;

    int result_sum = (1 << m) | (1 << n);
    cout << "2 ^ " << m << " + 2 ^ " << n << " = " << result_sum << endl;

    return 0;
}