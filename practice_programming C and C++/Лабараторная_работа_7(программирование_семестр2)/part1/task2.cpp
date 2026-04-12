#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int num;
    int bit_position;

    cout << "input number to work with bit: ";
    cin >> num;
    cout << "input position of bit: ";
    cin >> bit_position;

    cout << "binary number of " << num << ": " << bitset<8>(num) << endl;

    int result1 = num | (1 << bit_position);
    cout << "Make the bit of position " << bit_position << " 1: " << result1 << endl;
    cout << "binary number of " << result1 << ": " << bitset<8>(result1) << endl;

    int result2 = num & (~(1 << bit_position));
    cout << "Make the bit of position " << bit_position << " 0: " << result2 << endl;
    cout << "binary number of " << result2 << ": " << bitset<8>(result2) << endl;

    return 0;
}