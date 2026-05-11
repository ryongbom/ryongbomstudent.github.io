#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Input number (0-255): ";
    cin >> number;

    string result = "";
    for (int i = 7; i >= 0; i--)
    {
        int sub_res = (number >> i) & 1;
        if (sub_res == 1)
        {
            result += "1";
        }
        else
        {
            result += "0";
        }
    }
    cout << "binary expression of number: " << result << endl;

    return 0;
}