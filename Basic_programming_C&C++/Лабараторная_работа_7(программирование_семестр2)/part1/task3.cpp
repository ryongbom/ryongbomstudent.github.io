#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int num;
    int bit_position;

    cout << "input number: ";
    cin >> num;
    cout << "input position of bit: ";
    cin >> bit_position;

    cout << "binary number of " << num << ": " << bitset<8>(num) << endl;

    int bit_value = (num >> bit_position) & 1;

    cout << "bit value in position " << bit_position << " : " << bit_value << endl;

    return 0;
}